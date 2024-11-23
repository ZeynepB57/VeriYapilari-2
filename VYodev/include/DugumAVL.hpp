/**
* @file DugumAVL.hpp
* @description   avl için dugum olusturmak 
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/

#ifndef DUGUMAVL_HPP
#define DUGUMAVL_HPP
#include "Kuyruk.hpp"

class DugumAVL {
public:
    int data;
    Kuyruk* line;               //kuyruktaki sira
    DugumAVL* left;             //dugumun solu icin
    DugumAVL* right;            //dugumun sagi icin
    int height;

    DugumAVL(Kuyruk* vr, DugumAVL* sl, DugumAVL* sg);       //solunda ve sagýnda dugum olan 
    DugumAVL(Kuyruk* vr, DugumAVL* sl);                     //solunda dugum olan
    DugumAVL(Kuyruk* vr);                                   //ilk dugum 
};


#endif /* NODEAVL_HPP */
