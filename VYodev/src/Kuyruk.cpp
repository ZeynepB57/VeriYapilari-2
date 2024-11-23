/**
* @file Kuyruk.cpp
* @description kuyruk oluþturmak icin
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/

#include "Kuyruk.hpp"

Dugum* Kuyruk::dugumDegerMaks() {          
    Dugum* prev = 0;        
    Dugum* tmp = front;     //kuyrugun basi gecici olur
    int max = front->item;          //bastaki dugumun degeri
    while (tmp->next != 0) {            // temp son dugum olana kadar
        if (tmp->next->item > max) {        //gecicinin degeri onceki max dan buyukse 
            max = tmp->next->item;          //yeni max ttmp nin degeri olur
            prev = tmp;                 //preve tmp atanýr 
        }
        tmp = tmp->next;     //yeni tmp bir sonraki dugum olur
    }
    return prev;            
}

Kuyruk::Kuyruk() {      //bos kuyruk olusur
    front = back = 0;
    length = 0;
}


bool Kuyruk::isEmpty()const {       //bos mu dolu mu kontrolu
    return length == 0;
}

int Kuyruk::count()const {          //kuyrugun uzunlugu
    return length;
}


void Kuyruk::kuyrukSilSon() {           //Sondaki kuyrugu silmek icin
    if (isEmpty()) throw "Queue is Empty";          //bos mu dolu mu kontrolu
    Dugum* prev = dugumDegerMaks();                 
    Dugum* tmp;
    if (prev == 0) kuyrukSilBas();          //tek kuyruksa bastan sil yapýlýr direkt
    else {
        if (prev->next == back) back = prev;        
        tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
        length--;
    }
}

void Kuyruk::kuyrukSilBas() {        //kuyrukta bastan silmek icin 
    if (isEmpty()) throw "Queue is Empty";
    Dugum* tmp = front;         //gecici dugum oluþur buna kuyrugun basý atanýr
    front = front->next;        //yeni bas sonraki olur 
    delete tmp;                 //gecici silinir yani bastaki silinmis olur
    length--;           //uzunluk azaltilir
}

int Kuyruk::toplaKuyruk() {                 //kuyruktaki degerleri toplar
    if (front == 0) throw "Queue is empty";
    if (front->next == 0) return front->item;       //kuyruk tekse direkt onun degeri atanir
    Dugum* tmp = front;             //kuyrugun basi 
    int toplam = 0;
    while (tmp != 0) {      //kuyrugun sonuna kadar donguye girer
        toplam += tmp->item;             //toplama degerler eklenir
        tmp = tmp->next;                //kuyrukta ilerlemek icin
    }
    return toplam;
}

void Kuyruk::kuyrukEkle(const int& item) {              //kuyruk eklemek icin
    Dugum* last = new Dugum(item);
    if (isEmpty()) front = back = last;     //bos sa eger eklenir
    else {
        back->next = last;      //son dugumun ilerisini yeni eklenecek dugumu gosterir
        back = back->next;      //son dugum eklenen olur
    }
    length++;
}

int& Kuyruk::peek()const {          //kuyrugun basindaki deger
    if (isEmpty()) throw "Queue is Empty";
    return front->item;
}

int& Kuyruk::peekMax() {               //kuyrugun sonundaki degri getirir
    if (isEmpty()) throw "Queue is Empty";
    Dugum* prev = dugumDegerMaks();
    if (prev == 0) return peek();
    return prev->next->item;
}

void Kuyruk::clear() {          //kuyrugu siiler
    while (!isEmpty())kuyrukSilBas();
}

Kuyruk::~Kuyruk() {         //yikici fonksiyon
    clear();
}