#include <iostream>
#include "Kromozom.hpp"
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
Gen* Kromozom::getTail() const {
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

int Kromozom::getLength(){
    return this->len;
}