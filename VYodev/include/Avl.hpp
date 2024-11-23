/**
* @file Avl.hpp
* @description   Agac olusturmak icin
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/
#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <cmath>
#include "Kuyruk.hpp"
#include "DugumAVL.hpp"
using namespace std;

class AVL {
private:
    DugumAVL* kok;
    DugumAVL* AraVeEkle(DugumAVL* subNode, int item, Kuyruk* items);     
    DugumAVL* SolCocuklaTakas(DugumAVL* subNode);                       //agac sola dogru fazla dallanmasin diye
    DugumAVL* SagCocuklaTakas(DugumAVL* subNode);                       //agac saga dogru fazla dallanmasin diye
    bool DugumSil(DugumAVL*& subNode);                  
    void postorderMaxDel(DugumAVL* subNode);        //sondakini silmek icin
    void postorderDel(DugumAVL* subNode);           //bsatakini silmek icin
    void preorder(DugumAVL* subNode);
    int Height(DugumAVL* subNode);

public:
    
    AVL();
    bool isEmpty()const;
    void Ekle(Kuyruk* item);
    void preorder();
    int Height();
    void Clear();
    ~AVL();
};


#endif /* AVL_HPP */
