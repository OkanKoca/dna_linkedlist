/**       
* @file  Gen.cpp
* @description Gen sınıfına ait metotların gövdelerinin bulunduğu, next pointerı previous pointerını alma gibi metotların olduğu dosya.
* @course  1.öğretim A grubu
* @assignment  1.ödev
* @date  26/11/2024 (daha önce başladım fakat bu kısmı yazmayı unuttuğum için tarihini hatırlamıyorum.)
* @author  Okan KOCA - b231210016@sakarya.edu.tr
*/ 

#include <iostream>
#include "Gen.hpp"
#include "Kromozom.hpp"

Gen* Gen::GenOlustur(char nuc, Gen *pNext, Gen *pPrev) {
    this->nuc = nuc;
    this->pNext = pNext;
    this->pPrev = pPrev;
    return this;
}

Gen* Gen::getNext() const {
    return this->pNext;
}

Gen* Gen::getPrev() const {
    return this->pPrev;
}

char Gen::getNuc() const {
    return this->nuc;
}

void Gen::setNuc(char nuc) {
    this->nuc = nuc;
}

void Gen::setNext(Gen* newGen) {
    this->pNext = newGen;
}


