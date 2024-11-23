/**
* @file text.cpp
* @description   dosya adýný alýr ve ekrana aðacý yazdýrýr
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/
#include <cstdlib>
#include<iostream>
#include "Radix.hpp"
#include "Dosya.hpp"
#include "Avl.hpp"
using namespace std;

int main(int argc, char** argv) {

    Dosya* read = new Dosya("sayi.TXT");            //okunacak dosyanin adai alinir
    Kuyruk** kuyruklar = read->sortFile();          //dosya siralanir
    AVL* avl = new AVL();                           //yeni avl agaci olusturulur
    for (int index = 0; index < read->lineCount(); index++) {           //satir sayisi kadar döner


        avl->Ekle(kuyruklar[index]);            //kuyruktaki bulunan toplam degerleri agaca ekler

    }
    cout<<endl;
    std::cout << "preorder yazim sekli:" << std::endl;
    avl->preorder();
    delete read;
    delete avl;     //agac silinir


    return 0;
}
