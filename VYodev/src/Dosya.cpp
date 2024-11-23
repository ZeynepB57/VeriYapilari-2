/**
* @file Dosya.cpp
* @description   Agac olusturmak icin
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/

#include "Dosya.hpp"

Dosya::Dosya(std::string fileName) {        //dosyadaki satir sayisi kadar kuyruk olusturmak icin    
    this->fileName = fileName;          //dosyanin adi atanir


    int numlines = lineCount();         //satir satisi alinir
    this->lines = new Kuyruk * [numlines];       //kuyruk olusturulur
    for (int i = 0; i < numlines; i++) {
        this->lines[i] = new Kuyruk();  //her satir icin kuyrurk olusturur
    }
}

int Dosya::lineCount() {    //satir sayisini bulur
    int counter = 0;
    std::ifstream file(this->fileName);     //dosyayi okur
    std::string unused;
    while (std::getline(file, unused))          // satir satir dolasir her satirda sayici 1 artar
        ++counter;

    file.close();   // dosya kapatilir
    return counter;
}

void Dosya::readLine() {              //satirdaki sayilari okumak icin
    std::string token;                  
    std::ifstream file(this->fileName);         //dosya okumak icin acilir
    std::string str;
    int index = 0;
    while (std::getline(file, token)) {     //dosya satir satir okutulut
        std::istringstream ss(token);       

        while (std::getline(ss, str, ' ')) {        //sayilari ayri ayri alabilmek icin boslug kontrolu 
            this->lines[index]->kuyrukEkle(stoi(str));     //stringi inte cevirir ve kuyruga atar

        }
        index++;

    }
    file.close();       //dosya kapanir
}

Kuyruk** Dosya::sortFile() {           //sadece kuyrukta siralama yapar
    readLine();                         //kuyrugu oku
    int count = lineCount();            //kuyrugun boyutu
    for (int index = 0; index < count; index++) {       //kuyrugun sonuna kadar donmek icin
        Radix sort(lines[index]);           //gecici kuyruk olusturulur sýralama yaptiçca ggecici silinerek sýralama yapilir
        Kuyruk* tmp = lines[index];
        lines[index] = sort.Sirala();
        delete tmp;

    }
    return lines;
}
Dosya::~Dosya() {       //yikici fonksiyonu
    if (lines != 0) {
        int count = lineCount();
        for (int i = 0; i < count; i++) {
            if (lines[i] != 0) delete lines[i];
        }
        delete[] lines;     //kuyruk silinir
    }

}