#include <iostream>
#include "Gen.hpp"
#include "Kromozom.hpp"

Gen* Gen::GenOlustur(char nuc, Gen *pNext, Gen *pPrev) {
    this->nuc = nuc;
    this->pNext = pNext;
    this->pPrev = pPrev;
    return this;
}

/*void Gen::kuyrugaEkle(Gen *newGen) {
    Gen* current = this;
    while (current->pNext != nullptr) {
        current = current->pNext;
    }
    current->pNext = newGen;
    newGen->pPrev = current;
    newGen->pNext = nullptr;
}
*/
// Gen* Gen::addTail(char nuc, Gen *pNext, Gen *pPrev) {
//     this->nuc = nuc;
//     this->pPrev = pPrev;
//     this->pNext = pNext;
//     return this;
// }

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


