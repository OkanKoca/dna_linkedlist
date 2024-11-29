/**       
* @file  Kromozom.cpp
* @description Kromozom sınıfına ait metotların gövdelerinin bulunduğu, next pointerını ayarlama, next pointerını alma, kromozomda kaç gen bulunduğunu belirten len değişkenini ayarlama gibi metotların olduğu dosya.
* @course  1.öğretim A grubu
* @assignment  1.ödev
* @date  26/11/2024 (daha önce başladım fakat bu kısmı yazmayı unuttuğum için tarihini hatırlamıyorum.)
* @author  Okan KOCA - b231210016@sakarya.edu.tr
*/ 
#include <iostream>
#include "Kromozom.hpp"
#include "Dna.hpp"
using namespace std;

Kromozom::Kromozom() {
        pHead = nullptr;
        pTail = nullptr;
        len = 0;
};

void Kromozom::setpHead(Gen *pHead) {
    this->pHead = pHead;
}

void Kromozom::setpTail(Gen *pTail) {
    this->pTail = pTail;
}

void Kromozom::setLen(int len) {
    this->len = len; 
}   
Kromozom* Kromozom::getNext() const{
    return this->pNext;
}
void Kromozom::setNext(Kromozom *pNext) {
    this->pNext = pNext;
}
Gen* Kromozom::getGenHead() const {
    return this->pHead;
}
Gen* Kromozom::getGenTail() const {
    return this->pTail;
}

Gen* Kromozom::getGenByIndex(int index)const {
    Gen *current = pHead;
    for (int i = 0; i < index; i++)
    {
        if (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
    }
    return current;
}


int Kromozom::getLength() const{
    return this->len;
}