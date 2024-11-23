/**
* @file Radix.cpp
* @description   Sayýlarý büyükten küçüðe sýralamak için
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/
#include "Radix.hpp"

int Radix::adimSayici(int number) {          //basmak sayisi bulmak icin
    number = abs(number);
    int basamak = 0;
    if (number == 0)basamak = 1;    //sayi 0 sa basamak sayisi 1 dir 
    while (number > 0) {            //basamak sayisi 0 dan büyükse 10 a böle böle bulunur
        basamak++;
        number /= 10;
    }
    return basamak;
}

int Radix::MaxAdimSayi() {        //en buyuk basamak sayi bulmak icin
    int max = 0;
    for (int i = 0; i < length; i++) {         
        if (adimSayici(sayilar[i]) > max) max = adimSayici(sayilar[i]);       //bir onceci ve sonraki basamak sayilarina bakarak kontrol edilir 
    }
    return max;
}

Radix::Radix(Kuyruk *kuyruk) {            //
    int index = 0;
    this->sayilar = new int[kuyruk->count()];
    this->length = kuyruk->count();      //kuyrugun uzunlugu
    while (!kuyruk->isEmpty()) {
        int number = kuyruk->peek();     //kurugun basindaki degri getirir

        sayilar[index] = number;
        kuyruk->kuyrukSilBas();           //kuyrugun basindakini siler
        index++;
    }

    kuyruklar = new Kuyruk*[10];
    for (int j = 0; j < 10; j++) {
        kuyruklar[j] = new Kuyruk();
    }
    maxAdim = MaxAdimSayi();
}

Kuyruk* Radix::Sirala() {          //siralama
    int numberIndex = 0;
    //oncce diziden oku ve kuyruga ekle
    for (; numberIndex < length; numberIndex++) {
        int adimSayisi = sayilar[numberIndex] % 10;
        int num = sayilar[numberIndex];         //sayilar dizisinden elemanlar alinir 
        kuyruklar[adimSayisi]->kuyrukEkle(num);        //kuyruga eklenir
    }

    //ilk hane islendigi icin 1 den basliyorum 
    for (int i = 1; i < maxAdim; i++) {
        int arr[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = kuyruklar[i]->count();
        }
        for (int index = 0; index < 10; index++) {
            int len = arr[index];
            for (; len > 0; len--) {        //
                int number = kuyruklar[index]->peek();
                kuyruklar[index]->kuyrukSilBas();           //kuyruktan siler
                int stepValue = (number / (int) pow(10, i)) % 10;
                kuyruklar[stepValue]->kuyrukEkle(number);         //kuyruga ekler

            }
        }
    }

    
    Kuyruk* kuyrukSiparis = new Kuyruk();
    numberIndex = 0;
    for (int index = 0; index < 10; index++) {
        while (!kuyruklar[index]->isEmpty()) {
            int number = kuyruklar[index]->peek();         //kuyrugun ilk elemanini alma
            kuyrukSiparis->kuyrukEkle(number);       //kuyruga ekleme
            kuyruklar[index]->kuyrukSilBas();       //kurugun basindaaki silinir
        }
    }

    return kuyrukSiparis;     
}

Radix::~Radix() {       //yikici fonksiyon
    delete [] sayilar;
    for (int i = 0; i < 10; i++) delete kuyruklar[i];      //kuruktaki degerler silinir
    delete [] kuyruklar;       //kuyruk silinir
}