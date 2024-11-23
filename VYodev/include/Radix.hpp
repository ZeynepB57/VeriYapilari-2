/**
* @file Radix.hpp
* @description   Sayýlarý büyükten küçüðe sýralamak için
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/


#ifndef RADIX_HPP
#define RADIX_HPP

#include <math.h>
#include "Kuyruk.hpp"

class Radix {
private:
    int* sayilar;           
    int length;
    Kuyruk** kuyruklar;
    int maxAdim;
    int adimSayici(int);
    int MaxAdimSayi(); 

public:
    Radix(Kuyruk*);
    Kuyruk* Sirala();       
    ~Radix();
};


#endif /* RADIX_HPP */
