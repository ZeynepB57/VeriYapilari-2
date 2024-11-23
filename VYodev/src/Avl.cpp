/**
* @file Avl.cpp
* @description   Agac olusturmak icin
* @course 1/A
* @assignment 1
* @date 23.08.2022
* @author Zeynep Bezirci
*/
#include "Avl.hpp"
DugumAVL* AVL::SolCocuklaTakas(DugumAVL* downDugum) {         //agac sol tarafa dengesiz olmussa


    DugumAVL* tmp = downDugum->left;                    //dugum asagýya  iner
    downDugum->left = tmp->right;                       
    tmp->right = downDugum;

    downDugum->height = Height(downDugum);
    tmp->height = 1 + max(Height(tmp->left), downDugum->height);

    if (!downDugum->line->isEmpty()) {   //dugum asagi indigi icin en buyuk degri silmek icin kuyrugun son elemanini sil
        downDugum->line->kuyrukSilSon();
    }
    postorderMaxDel(downDugum->right);    //dugum yukari ciktigi icin en kucuk degri silmek icin kuyrugun bassini sil
    if (!tmp->line->isEmpty()) {
        tmp->line->kuyrukSilBas();
    }
    postorderDel(tmp->left);
    return tmp;
}
DugumAVL* AVL::AraVeEkle(DugumAVL* downDugum, int item, Kuyruk* items) {   //agacta preorder sekilde olacak sekilde nereye ekleyecegini bulur ve ekler

    if (downDugum == NULL) downDugum = new DugumAVL(items);     
    else if (item < downDugum->data) {                              //gelen veri kucukse agacta sol taraf eklemek icin 
        downDugum->left = AraVeEkle(downDugum->left, item, items);

        if (Height(downDugum->left) == Height(downDugum->right) + 2) {  //sag sol dengesizligi icinyukseklik kontrolu yapilir
            if (item < downDugum->left->data)

                downDugum = SolCocuklaTakas(downDugum);         
            else {

                downDugum->left = SagCocuklaTakas(downDugum->left);    //sola dondurme 
                downDugum = SolCocuklaTakas(downDugum);
            }
        }
    }
    else if (item > downDugum->data) {              //gelen veri buyukse agacta sag tarafa eklemek icin
        downDugum->right = AraVeEkle(downDugum->right, item, items);

        if (Height(downDugum->right) == Height(downDugum->left) + 2) {          //sag sol dengesizligi olmasin diye yukseklik kontrolu
            if (item > downDugum->right->data)

                downDugum = SagCocuklaTakas(downDugum);            
            else {

                downDugum->right = SolCocuklaTakas(downDugum->right); //saga dondurme
                downDugum = SagCocuklaTakas(downDugum);
            }
        }
    }
    else;

    downDugum->height = Height(downDugum);
    return downDugum;
}



DugumAVL* AVL::SagCocuklaTakas(DugumAVL* downDugum) {    //agac sag tarafa dengesiz olmussa 

    DugumAVL* tmp = downDugum->right;
    downDugum->right = tmp->left;
    tmp->left = downDugum;

    downDugum->height = Height(downDugum);
    tmp->height = 1 + max(Height(tmp->right), downDugum->height);
    if (!downDugum->line->isEmpty()) {           //dugum asagi indigi icin en buyuk degri silmek icin kuyrugun son elemanini sil
        downDugum->line->kuyrukSilSon();
    }
    postorderMaxDel(downDugum->left);
    if (!tmp->line->isEmpty()) {            //dugum yukari ciktigi icin en kucuk degri silmek icin kuyrugun bassini sil
        tmp->line->kuyrukSilBas();
    }
    postorderDel(tmp->right);           
    return tmp;
}

int AVL::Height(DugumAVL* downDugum) {      //dengesizligi bulmak icin isimize yarayacak yukseklþigi bulur
    if (downDugum == NULL) return -1;
    return 1 + max(Height(downDugum->left), Height(downDugum->right));
}

bool AVL::DugumSil(DugumAVL*& downDugum) {          
    DugumAVL* delNode = downDugum;

    if (downDugum->right == NULL) downDugum = downDugum->left;      //dugumun sagi bossa dugume dugumun solunu gosterir
    else if (downDugum->left == NULL) downDugum = downDugum->right;  //dugumun solu bossa dugume dugumun sagýný gosterir
    else {                                                           //sagý ve solu doluysa
        delNode = downDugum->left;
        DugumAVL* parentNode = downDugum;
        while (delNode->right != NULL) {
            parentNode = delNode;
            delNode = delNode->right;
        }
        downDugum->data = delNode->data;
        if (parentNode == downDugum) downDugum->left = delNode->left;
        else parentNode->right = delNode->left;
    }
    delete delNode;
    return true;
}

void AVL::postorderDel(DugumAVL* downDugum) {   //bastaki dugum silmek icin
    if (downDugum != NULL) {//dugum bos degilse

        postorderDel(downDugum->left);
        postorderDel(downDugum->right);
        if (!downDugum->line->isEmpty()) {
            downDugum->line->kuyrukSilBas();//dugum yukari ciktigi icin en kucuk degri silmek icin kuyrugun bassini sil
        }
    }
}

void AVL::postorderMaxDel(DugumAVL* downDugum) {//sondaki dugum silmek icin

    if (downDugum != NULL) {

        postorderMaxDel(downDugum->left);
        postorderMaxDel(downDugum->right);
        if (!downDugum->line->isEmpty()) {
            downDugum->line->kuyrukSilSon(); //dugum asagi indigi icin en buyuk degri silmek icin kuyrugun son elemanini sil
        }

    }
}

void AVL::preorder(DugumAVL* downDugum) {//sagi buyuk solu kucuk sekilde yazdirma
    if (downDugum != NULL) {
        cout << downDugum->data << ": ";
        while (!downDugum->line->isEmpty()) {   //agacin tamamini dolasir

            int number = downDugum->line->peek();
            std::cout << number << " ";
            downDugum->line->kuyrukSilBas();
        }
        cout << endl;
        preorder(downDugum->left);
        preorder(downDugum->right);
    }
}



AVL::AVL() {        //agac olusur
    kok = NULL;
}

void AVL::Ekle(Kuyruk* item) {      //agaca ekleme
    int num = item->toplaKuyruk();
    kok = AraVeEkle(kok, num, item);
}

void AVL::Clear() {     //agaci tamamen silme
    while (!isEmpty()) DugumSil(kok);   //bos olana kadar doner
}

void AVL::preorder() {  //ozel kuralli yazim sekli
    preorder(kok);
}

int AVL::Height() {     //agacin yuksekligi
    return Height(kok);
}


bool AVL::isEmpty()const { //agac bos mu dolu mu kontrolu
    return kok == NULL;
}

AVL::~AVL() {//yikici fonksiyon
    Clear();
}