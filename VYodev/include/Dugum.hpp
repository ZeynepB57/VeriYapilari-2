/**
* @file Dugum.hpp
* @description   dugum olusturmak icin
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/


#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum {
public:
    int item;
    Dugum* next;
    Dugum(int item);
    Dugum(int, Dugum*);
};


#endif /* NODE_HPP */
