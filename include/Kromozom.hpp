#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "Gen.hpp"

class Kromozom {
private:
    Gen *pHead;
    Gen *pTail;
    Kromozom *pNext;
    int len; 

public:
    Kromozom();
    
    Kromozom* getNext() const;
    void setNext(Kromozom *pNext);
    void setpHead(Gen *pHead);
    void setpTail(Gen *pTail);
    void setLen(int len);
    Gen* getGenHead() const;
    Gen* getTail() const;
    Gen* getGenByIndex(int index) const;
    //Gen* ifBothEven(Kromozom *krom1Ptr, Kromozom *krom2Ptr, Kromozom *tailKrom) const;
    int getLength();

};

#endif