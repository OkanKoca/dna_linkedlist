#ifndef GEN_HPP
#define GEN_HPP

class Gen {
private:
    Gen *pNext;
    Gen *pPrev;
    //Gen *pSelf;
    char nuc;

public:
    //Gen(); 
    //~Gen();

    Gen* GenOlustur(char nuc, Gen *pNext = nullptr, Gen *pPrev = nullptr);
    //void kuyrugaEkle(Gen *newGen);
    //Gen* addTail(char nuc, Gen *pNext = nullptr, Gen *pPrev = nullptr);
    char getNuc() const;
    void setNuc(char nuc);
    Gen* getNext() const;
    Gen* getPrev() const;
    void setNext(Gen* newGen);


};

#endif 