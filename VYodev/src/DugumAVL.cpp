/**
* @file DugumAVL.cpp
* @description   avl için dugum olusturmak
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/
#include "DugumAVL.hpp"

DugumAVL::DugumAVL(Kuyruk* vr, DugumAVL* sl, DugumAVL* sg) { //agacýn sag ve sol dugumu varsa eklemek icin bu kullanilir
    data = vr->toplaKuyruk();
    line = vr;
    left = sl;
    right = sg;
    height = 0;
}

DugumAVL::DugumAVL(Kuyruk* vr, DugumAVL* sl) {          //agacin sadece sol dugum varsa eklemek icin bu kullanilir
    data = vr->toplaKuyruk();
    line = vr;
    left = sl;
    right = 0;
    height = 0;
}

DugumAVL::DugumAVL(Kuyruk* vr) {            //agacin ilk elemiysa eklemek icin 
    data = vr->toplaKuyruk();
    line = vr;
    left = 0;
    right = 0;
    height = 0;
}