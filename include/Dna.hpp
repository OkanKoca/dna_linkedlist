#ifndef DNA_HPP
#define DNA_HPP

#include "Kromozom.hpp"
#include <fstream>

class Dna {
private:
    Kromozom *pHeadKrom = nullptr;
    Kromozom *pTailKrom = nullptr;

public:
    //~Dna(); // Destructor
    void GenOku();
    void setHeadKrom(Kromozom *pHeadKrom);
    Kromozom* getHeadKrom() const;
    void setTailKrom(Kromozom *pTailKrom);
    Kromozom* getTailKrom();
    void printChromosomes(Kromozom *pHeadKrom);
    void Caprazla(int krom1 = 0, int krom2 = 0);
    void Mutasyon(int satir, int sutun);
    void OtomatikIslemler();
    void ekranaYaz();



};

#endif 