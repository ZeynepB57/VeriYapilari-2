/**
* @file Kuyruk.hpp
* @description kuyruk olusturmak icin
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/

#ifndef KUYRUK_HPP
#define KUYRUK_HPP
#include "Dugum.hpp"

class Kuyruk {
private:
    Dugum* front;       //onceki dugum
    Dugum* back;        //sonraki dugum
    int length;

    Dugum* dugumDegerMaks();        //dugumdeki maaksimum sayiyi bulmak iicin
public:
    Kuyruk();
    
    bool isEmpty()const;                //bos mu dolu mu kontrolu icin
    int count()const;               //eleman sayisi icin
    void kuyrukSilSon();          //sondan silme
    void kuyrukSilBas();             //bastan silme
    int toplaKuyruk();         //kuyruktaki sayilari toplamak icin 
    void kuyrukEkle(const int& item);      // eklemek icin 
    int& peek()const;       //kuyruktaki ilk elemanýn degeri için
    int& peekMax();         //kuyrugun sonundaki elemannin degeri için
    void clear();               //kuyrugu temizleme
    ~Kuyruk();
};


#endif /* KUYRUK_HPP */
