/**
* @file Dugum.cpp
* @description   dugum olusturmak icin
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/


#include "Dugum.hpp"

Dugum::Dugum(int item, Dugum* next) {  //sonradan eklenecek dugumler icin
    this->item = item;
    this->next = next;
}
Dugum::Dugum(int item) {  //ilk dugum icin
    this->item = item;
    this->next = 0;
}