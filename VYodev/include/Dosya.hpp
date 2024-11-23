/**
* @file Dosya.hpp
* @description   dosyadan verileri okumak icin
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/

#ifndef DOSYA_HPP
#define DOSYA_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Kuyruk.hpp"
#include "Radix.hpp"

class Dosya {
private:


    std::string fileName;       //dosya adi icin
public:

    Dosya(std::string);       //dosya okuma ve siralama icin
    ~Dosya();                 //yikici fonksiyonu
    Kuyruk** sortFile();               //kuyrukta siralama
    int lineCount();                //kuyruk boyutu
private:
    Kuyruk** lines;          
    void readLine();            //kuyruk okumak icin


};



#endif /* READANDSORT_HPP */
