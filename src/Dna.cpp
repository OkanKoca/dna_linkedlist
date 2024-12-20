/**       
* @file  Dna.cpp
* @description Diğer sınıfların aksine bağlı liste yapısında değil diğer bağlı listeleri oluşturup işlemlerini yapan sınıf.
* @course  1.öğretim A grubu
* @assignment  1.ödev
* @date  26/11/2024 (daha önce başladım fakat bu kısmı yazmayı unuttuğum için tarihini hatırlamıyorum.)
* @author  Okan KOCA - b231210016@sakarya.edu.tr
*/ 
#include <iostream>
#include <fstream>
#include "Kromozom.hpp"
#include "Gen.hpp"
#include "Dna.hpp"

using namespace std;

Dna::Dna()
{
    GenOku();
}

Dna::~Dna(){
    Kromozom *current = pHeadKrom;
    Kromozom *next = nullptr;

    while (current != nullptr)
    {
        next = current->getNext();
        while(current->getGenHead() != nullptr){
            Gen *gen = current->getGenHead();
            current->setpHead(gen->getNext());
            //cout << gen << " adresli gen siliniyor..." << endl; // kontrol amaçlı yazıldı. Yorum satırından çıkarılıp kontrol edilebilir.
            delete gen;
        }
        //cout << current << " -----------------------ADRESLI KROMOZOM SILINDI...-----------------------" << endl << endl; // kontrol amaçlı yazıldı. Yorum satırından çıkarılıp kontrol edilebilir.
        delete current;
        current = next;
    }
}

void Dna::setHeadKrom(Kromozom *pHeadKrom)
{
    this->pHeadKrom = pHeadKrom;
}

Kromozom *Dna::getHeadKrom() const
{
    return this->pHeadKrom;
}

void Dna::setTailKrom(Kromozom *pTailKrom)
{
    this->pTailKrom = pTailKrom;
}

Kromozom *Dna::getTailKrom()
{
    return this->pTailKrom;
}

int kromCount = 0;

void Dna::GenOku(){

    ifstream file("./Dna.txt");
    if (file.is_open())
    {
        char gen;

        int genCount = 0;
        Gen *genTail = nullptr;
        Kromozom *pKrom;

        while (file.get(gen))
        {       
            
            if(genCount == 0)
            {
                Kromozom *krom = new Kromozom();
                pKrom = krom;
            }

            if (gen != '\n')
            {
                if (gen != ' ')
                {
                    
                    Gen *newGen = new Gen();
                    if (genCount == 0)
                    {
                        newGen->GenOlustur(gen);
                        pKrom->setpHead(newGen);
                        pKrom->setpTail(newGen);
                        genTail = newGen;
                    }
                    else
                    {
                        newGen->GenOlustur(gen, nullptr, genTail);
                        genTail->setNext(newGen);
                        pKrom->setpTail(newGen);
                        genTail = newGen;
                    }

                    ++genCount;
                }
            }

            else
            { // satır sonuysa
                if (kromCount == 0 && genCount > 0)
                {
                    setHeadKrom(pKrom);
                    setTailKrom(pKrom);
                    pKrom->setLen(genCount);
                    pKrom->setNext(nullptr);
                } 
                else //if (genCount > 0)
                {
                    getTailKrom()->setNext(pKrom); // burayı sadece tail olacak şekilde değiştirmek 30 sn fark ettiriyor.
                    pKrom->setNext(nullptr);
                    pKrom->setLen(genCount);
                    setTailKrom(pKrom);
                }

                //cout << "Kromozom sayisi: " << kromCount << endl; // kontrol amaçlı yazıldı. Yorum satırından çıkarılıp kontrol edilebilir.
                ++kromCount;
                //cout << endl;      

                // cout << "olusturulan kromozom: "; // kontrol amaçlı yazıldı. Yorum satırından çıkarılıp kontrol edilebilir.
                // Gen* pTmp = pKrom->getGenHead();
                // while (pTmp != nullptr)
                // {
                //     cout << pTmp->getNuc() << " ";
                //     pTmp = pTmp->getNext();
                // }

                genCount = 0;
            }
        }

        // Dosyanın sonunda eksik bir kromozom varsa
        if (genCount > 0 && pKrom != nullptr) {
            if (kromCount == 0) {
                setHeadKrom(pKrom);
                setTailKrom(pKrom);
            } else {
                getTailKrom()->setNext(pKrom);
                setTailKrom(pKrom);
            }

            pKrom->setLen(genCount);
            pKrom->setNext(nullptr);
            ++kromCount;

            // cout << "Kromozom sayisi: " << kromCount << endl; kontrol amaçlı yazıldı. Yorum satırından çıkarılıp kontrol edilebilir.

            // cout << "Olusturulan kromozom: "; kontrol amaçlı yazıldı. Yorum satırından çıkarılıp kontrol edilebilir.
            // Gen *pTmp = pKrom->getGenHead();
            // while (pTmp != nullptr) {
            //     cout << pTmp->getNuc() << " ";
            //     pTmp = pTmp->getNext();
            // }
            // cout << endl;
        }
    }
    else
    {
        cout << "Dosya acilamadi." << endl;
    }
    
    file.close();
}

void Dna::Caprazla(int kromozom1, int kromozom2)
{
    Kromozom *current = pHeadKrom;
    Kromozom *tailKrom = nullptr;
    int krom1 = kromozom1;
    int krom2 = kromozom2;

    while (current->getNext() != nullptr)
    {
        current = current->getNext();
    }
    tailKrom = current;
    current = pHeadKrom;

    Kromozom *krom1Ptr = nullptr;
    Kromozom *krom2Ptr = nullptr;

    if (krom1 > kromCount || krom2 > kromCount || krom1 < 0 || krom2 < 0)
    {
        cout << "Hatali giris! Kromozom sayisindan fazla ya da 0 dan kucuk index girdiniz..." << endl;
    }
    else
    {
        for (int i = 0; i < krom1; i++) //  ornegin 16 ya gidebilmek icin 16 kez next e gecmemiz gerekir.
        {
            if (current->getNext() != nullptr)
            {
                current = current->getNext();
            }
        }
        krom1Ptr = current;
        current = pHeadKrom;

        for (int i = 0; i < krom2; i++) //  ornegin 16 ya gidebilmek icin 16 kez next e gecmemiz gerekir.
        {
            if (current->getNext() != nullptr)
            {
                current = current->getNext();
            }
        }
        krom2Ptr = current;
        current = pHeadKrom;

        if (krom1Ptr->getLength() % 2 == 0) // 1.kromozom çift sayı ise
        {
            if (krom2Ptr->getLength() % 2 == 0) // 2.krom çift sayı ise
            {
                Gen *krom1MidGen = krom1Ptr->getGenByIndex(krom1Ptr->getLength() / 2);
                Gen *krom2MidGen = krom2Ptr->getGenByIndex(krom2Ptr->getLength() / 2);

                // 1. sağı ve 2. solu birbirine bağla

                Gen *krom1MidTmp = krom1MidGen;
                Gen *krom2MidTmp = krom2MidGen;
                Gen *krom1Head = krom1Ptr->getGenHead();
                Gen *krom2Head = krom2Ptr->getGenHead();

                Kromozom *CaprazlananKrom1 = new Kromozom();
                Kromozom *CaprazlananKrom2 = new Kromozom();
                int genCount = 0;

                while (krom1MidTmp != nullptr)
                {
                    Gen *newGen = new Gen();

                    if (genCount == 0)
                    {
                        newGen->GenOlustur(krom1MidTmp->getNuc());
                        CaprazlananKrom1->setpHead(newGen);
                        CaprazlananKrom1->setpTail(newGen);
                    }
                    else
                    {
                        newGen->GenOlustur(krom1MidTmp->getNuc(), nullptr, CaprazlananKrom1->getGenTail());
                        CaprazlananKrom1->getGenTail()->setNext(newGen);
                        CaprazlananKrom1->setpTail(newGen);
                    }
                    krom1MidTmp = krom1MidTmp->getNext();
                    genCount++;
                }
                while (krom2Head != krom2MidGen)
                {
                    Gen *newGen = new Gen();

                    newGen->GenOlustur(krom2Head->getNuc(), nullptr, CaprazlananKrom1->getGenTail());
                    CaprazlananKrom1->getGenTail()->setNext(newGen);
                    CaprazlananKrom1->setpTail(newGen);

                    krom2Head = krom2Head->getNext();
                    genCount++;
                }

                CaprazlananKrom1->setLen(genCount);
                CaprazlananKrom1->setNext(nullptr);
                tailKrom->setNext(CaprazlananKrom1);
                tailKrom = CaprazlananKrom1;

                Gen* pTmp = CaprazlananKrom1->getGenHead();
                cout << "caprazlanan 1. kromozom: ";
                while(pTmp != nullptr){
                    cout << pTmp->getNuc() << " ";
                    pTmp = pTmp->getNext();
                }

                genCount = 0;

                // 1.solu ve 2.sağı birbirine bağla
                while (krom1Head != krom1MidGen)
                {
                    Gen *newGen = new Gen();

                    if (genCount == 0)
                    {
                        newGen->GenOlustur(krom1Head->getNuc());
                        CaprazlananKrom2->setpHead(newGen);
                        CaprazlananKrom2->setpTail(newGen);
                    }
                    else
                    {
                        newGen->GenOlustur(krom1Head->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                        CaprazlananKrom2->getGenTail()->setNext(newGen);
                        CaprazlananKrom2->setpTail(newGen);
                    }
                    krom1Head = krom1Head->getNext();
                    genCount++;
                }

                while (krom2MidTmp != nullptr)
                {
                    Gen *newGen = new Gen();

                    newGen->GenOlustur(krom2MidTmp->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                    CaprazlananKrom2->getGenTail()->setNext(newGen);
                    CaprazlananKrom2->setpTail(newGen);

                    krom2MidTmp = krom2MidTmp->getNext();
                    genCount++;
                }
                CaprazlananKrom2->setLen(genCount);
                CaprazlananKrom2->setNext(nullptr);
                tailKrom->setNext(CaprazlananKrom2);
                tailKrom = CaprazlananKrom2;

                pTmp = CaprazlananKrom2->getGenHead();
                cout << "caprazlanan 2. kromozom: ";
                while(pTmp != nullptr){
                    cout << pTmp->getNuc() << " ";
                    pTmp = pTmp->getNext();
                }

            }

            else // 2.krom tek sayı ise
            {
                Gen *krom1MidGen = krom1Ptr->getGenByIndex(krom1Ptr->getLength() / 2);
                Gen *krom2MidGen = krom2Ptr->getGenByIndex(krom2Ptr->getLength() / 2);

                // 1. sağı ve 2. solu birbirine bağla

                Gen *krom1MidTmp = krom1MidGen;
                Gen *krom2MidTmp = krom2MidGen;
                Gen *krom1Head = krom1Ptr->getGenHead();
                Gen *krom2Head = krom2Ptr->getGenHead();

                Kromozom *CaprazlananKrom1 = new Kromozom();
                Kromozom *CaprazlananKrom2 = new Kromozom();
                int genCount = 0;

                while (krom1MidTmp != nullptr)
                {
                    Gen *newGen = new Gen();
                    if (genCount == 0)
                    {
                        newGen->GenOlustur(krom1MidTmp->getNuc());
                        CaprazlananKrom1->setpHead(newGen);
                        CaprazlananKrom1->setpTail(newGen);
                    }
                    else
                    {
                        newGen->GenOlustur(krom1MidTmp->getNuc(), nullptr, CaprazlananKrom1->getGenTail());
                        CaprazlananKrom1->getGenTail()->setNext(newGen);
                        CaprazlananKrom1->setpTail(newGen);
                    }
                    krom1MidTmp = krom1MidTmp->getNext();
                    genCount++;
                }
                while (krom2Head != krom2MidGen) // tek sayı oldugu icin bu gene esit olunca duracak ve onun solundakiler caprazlamaya alinmis olacak kendisi haric.
                {
                    Gen *newGen = new Gen();
                    newGen->GenOlustur(krom2Head->getNuc(), nullptr, CaprazlananKrom1->getGenTail());
                    CaprazlananKrom1->getGenTail()->setNext(newGen);
                    CaprazlananKrom1->setpTail(newGen);

                    krom2Head = krom2Head->getNext();
                    genCount++;
                }

                CaprazlananKrom1->setLen(genCount);
                CaprazlananKrom1->setNext(nullptr);
                tailKrom->setNext(CaprazlananKrom1);
                tailKrom = CaprazlananKrom1;

                Gen* pTmp = CaprazlananKrom1->getGenHead(); 
                cout << "caprazlanan 1. kromozom: ";
                while(pTmp != nullptr){
                    cout << pTmp->getNuc() << " ";
                    pTmp = pTmp->getNext();
                }

                genCount = 0;


                while (krom1Head != krom1MidGen->getNext())
                {
                    Gen *newGen = new Gen();
                    if (genCount == 0)
                    {
                        newGen->GenOlustur(krom1Head->getNuc());
                        CaprazlananKrom2->setpHead(newGen);
                        CaprazlananKrom2->setpTail(newGen);
                    }
                    else
                    {
                        newGen->GenOlustur(krom1Head->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                        CaprazlananKrom2->getGenTail()->setNext(newGen);
                        CaprazlananKrom2->setpTail(newGen);
                    }
                    krom1Head = krom1Head->getNext();
                    genCount++;
                }

                krom2MidTmp = krom2MidGen->getNext(); // ortanın bir sağından itibaren
                while (krom2MidTmp != nullptr)
                {
                    Gen *newGen = new Gen();
                    newGen->GenOlustur(krom2MidTmp->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                    CaprazlananKrom2->getGenTail()->setNext(newGen);
                    CaprazlananKrom2->setpTail(newGen);

                    krom2MidTmp = krom2MidTmp->getNext();
                    genCount++;
                }

                CaprazlananKrom2->setLen(genCount);
                CaprazlananKrom2->setNext(nullptr);
                tailKrom->setNext(CaprazlananKrom2);
                tailKrom = CaprazlananKrom2;

                pTmp = CaprazlananKrom2->getGenHead();
                cout << "caprazlanan 2. kromozom: ";
                while(pTmp != nullptr){
                    cout << pTmp->getNuc() << " ";
                    pTmp = pTmp->getNext();
                }

            }
        }
        else // 1.krom tek sayı ise
        {

            if (krom2Ptr->getLength() % 2 == 0) // 2.krom çift sayı ise
            {
                Gen *krom1MidGen = krom1Ptr->getGenByIndex(krom1Ptr->getLength() / 2);
                Gen *krom2MidGen = krom2Ptr->getGenByIndex(krom2Ptr->getLength() / 2);

                // 1. sağı ve 2. solu birbirine bağla

                Gen *krom1MidTmp = krom1MidGen;
                Gen *krom2MidTmp = krom2MidGen;
                Gen *krom1Head = krom1Ptr->getGenHead();
                Gen *krom2Head = krom2Ptr->getGenHead();

                Kromozom *CaprazlananKrom1 = new Kromozom();
                Kromozom *CaprazlananKrom2 = new Kromozom();
                int genCount = 0;

                // 1.kromozom tek sayıda
                // 1.krom solu ve 2.krom sağı birbirine bağla
                while (krom1Head != krom1MidGen)
                {
                    Gen *newGen = new Gen();
                    if (genCount == 0)
                    {
                        newGen->GenOlustur(krom1Head->getNuc());
                        CaprazlananKrom1->setpHead(newGen);
                        CaprazlananKrom1->setpTail(newGen);
                    }
                    else
                    {
                        newGen->GenOlustur(krom1Head->getNuc(), nullptr, CaprazlananKrom1->getGenTail());
                        CaprazlananKrom1->getGenTail()->setNext(newGen);
                        CaprazlananKrom1->setpTail(newGen);
                    }
                    krom1Head = krom1Head->getNext();
                    genCount++;
                }

                while (krom2MidTmp != nullptr)
                {
                    Gen *newGen = new Gen();
                    newGen->GenOlustur(krom2MidTmp->getNuc(), nullptr, CaprazlananKrom1->getGenTail());
                    CaprazlananKrom1->getGenTail()->setNext(newGen);
                    CaprazlananKrom1->setpTail(newGen);

                    krom2MidTmp = krom2MidTmp->getNext();
                    genCount++;
                }

                CaprazlananKrom1->setLen(genCount);
                CaprazlananKrom1->setNext(nullptr);
                tailKrom->setNext(CaprazlananKrom1);
                tailKrom = CaprazlananKrom1;

                Gen* pTmp = CaprazlananKrom1->getGenHead();
                cout << "caprazlanan 1. kromozom: ";
                while(pTmp != nullptr){
                    cout << pTmp->getNuc() << " ";
                    pTmp = pTmp->getNext();
                }

                genCount = 0;

                //1.kromun ortanın sağından başlaması lazım
                krom1MidTmp = krom1MidGen->getNext();
                while(krom1MidTmp != nullptr)
                {
                    Gen* newGen = new Gen();
                    if (genCount == 0)
                    {
                        newGen->GenOlustur(krom1MidTmp->getNuc());
                        CaprazlananKrom2->setpHead(newGen);
                        CaprazlananKrom2->setpTail(newGen);
                    }
                    else
                    {
                        newGen->GenOlustur(krom1MidTmp->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                        CaprazlananKrom2->getGenTail()->setNext(newGen);
                        CaprazlananKrom2->setpTail(newGen);
                    }
                    krom1MidTmp = krom1MidTmp->getNext();
                    genCount++;
                }

                // 2.krom sol taraf
                krom2MidTmp = krom2MidGen; // bundan önce diğer işlemi yaptığım için krom2MidTmp yi tekrar başa alıyorum
                while (krom2Head != krom2MidTmp)
                {
                    Gen* newGen = new Gen();
                    newGen->GenOlustur(krom2Head->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                    CaprazlananKrom2->getGenTail()->setNext(newGen);
                    CaprazlananKrom2->setpTail(newGen);

                    krom2Head = krom2Head->getNext(); 
                    genCount++;

                }

                CaprazlananKrom2->setLen(genCount);
                CaprazlananKrom2->setNext(nullptr);
                tailKrom->setNext(CaprazlananKrom2);
                tailKrom = CaprazlananKrom2;

                pTmp = CaprazlananKrom2->getGenHead();
                cout << "caprazlanan 2. kromozom: ";
                while(pTmp != nullptr){
                    cout << pTmp->getNuc() << " ";
                    pTmp = pTmp->getNext();
                }

            }
            else{ // 2.krom tek sayı ise

                Gen *krom1MidGen = krom1Ptr->getGenByIndex(krom1Ptr->getLength() / 2);
                Gen *krom2MidGen = krom2Ptr->getGenByIndex(krom2Ptr->getLength() / 2);

                // 1. sağı ve 2. solu birbirine bağla

                Gen *krom1MidTmp = krom1MidGen;
                Gen *krom2MidTmp = krom2MidGen;
                Gen *krom1Head = krom1Ptr->getGenHead();
                Gen *krom2Head = krom2Ptr->getGenHead();

                Kromozom *CaprazlananKrom1 = new Kromozom();
                Kromozom *CaprazlananKrom2 = new Kromozom();
                int genCount = 0;

                // 1.kromozom tek sayıda
                // 1.krom solu ve 2.krom sağı birbirine bağla
                while (krom1Head != krom1MidGen)
                {
                    Gen *newGen = new Gen();
                    if (genCount == 0)
                    {
                        newGen->GenOlustur(krom1Head->getNuc());
                        CaprazlananKrom1->setpHead(newGen);
                        CaprazlananKrom1->setpTail(newGen);
                    }
                    else
                    {
                        newGen->GenOlustur(krom1Head->getNuc(), nullptr, CaprazlananKrom1->getGenTail());
                        CaprazlananKrom1->getGenTail()->setNext(newGen);
                        CaprazlananKrom1->setpTail(newGen);
                    }
                    krom1Head = krom1Head->getNext();
                    genCount++;
                }

                krom2MidTmp = krom2MidGen->getNext(); // ortanın bir sağından itibaren 
                while (krom2MidTmp != nullptr)
                {
                    Gen *newGen = new Gen();
                    newGen->GenOlustur(krom2MidTmp->getNuc(), nullptr, CaprazlananKrom1->getGenTail());
                    CaprazlananKrom1->getGenTail()->setNext(newGen);
                    CaprazlananKrom1->setpTail(newGen);

                    krom2MidTmp = krom2MidTmp->getNext();
                    genCount++;
                }

                CaprazlananKrom1->setLen(genCount);
                CaprazlananKrom1->setNext(nullptr);
                tailKrom->setNext(CaprazlananKrom1);
                tailKrom = CaprazlananKrom1;

                Gen* pTmp = CaprazlananKrom1->getGenHead();
                cout << "caprazlanan 1. kromozom: ";
                while(pTmp != nullptr){
                    cout << pTmp->getNuc() << " ";
                    pTmp = pTmp->getNext();
                }

                genCount = 0;


                krom1MidTmp = krom1MidGen->getNext();
                while (krom1MidTmp != nullptr)
                {
                    Gen* newGen = new Gen();
                    if (genCount == 0)
                    {
                        newGen->GenOlustur(krom1MidTmp->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                        CaprazlananKrom2->setpHead(newGen);
                        CaprazlananKrom2->setpTail(newGen);
                    }
                    else
                    {
                        newGen->GenOlustur(krom1MidTmp->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                        CaprazlananKrom2->getGenTail()->setNext(newGen);
                        CaprazlananKrom2->setpTail(newGen);
                    }
            
                    krom1MidTmp = krom1MidTmp->getNext();
                    genCount++;
                }

                // 2.krom sol taraf

                while (krom2Head != krom2MidGen)
                {
                    Gen* newGen = new Gen();
                    newGen->GenOlustur(krom2Head->getNuc(), nullptr, CaprazlananKrom2->getGenTail());
                    CaprazlananKrom2->getGenTail()->setNext(newGen);
                    CaprazlananKrom2->setpTail(newGen);

                    krom2Head = krom2Head->getNext();
                    genCount++;
                }

                CaprazlananKrom2->setLen(genCount);
                CaprazlananKrom2->setNext(nullptr);
                tailKrom->setNext(CaprazlananKrom2);
                tailKrom = CaprazlananKrom2;

                pTmp = CaprazlananKrom2->getGenHead();
                cout << "caprazlanan 2. kromozom: ";
                while(pTmp != nullptr){
                    cout << pTmp->getNuc() << " ";
                    pTmp = pTmp->getNext();
                }

            }
        }
    }
}

void Dna::Mutasyon(int satir, int sutun) {
    int kromIndex = satir;
    int genIndex = sutun;

    Kromozom* current = pHeadKrom;

    if (kromIndex < kromCount && kromIndex >= 0)
    {
        for (int i = 0; i < kromIndex; i++)
        {
            if (current->getNext() != nullptr)
            {
                current = current->getNext();
            }
        }

        if (current->getLength() < genIndex)
        {
            cout << "Hatali giris! Gen sayisindan fazla index girdiniz..." << endl;
        }
        else
        {
            Gen *gen = current->getGenByIndex(genIndex);
            gen->setNuc('X');
        }
    
    }
    else
        cout << "Hatali giris! Kromozom sayisindan fazla index ya da 0 dan küçük index girdiniz..." << endl;
    
}

int caprazSayac = 0;
int mutSayac = 0;

void Dna::OtomatikIslemler(){
    ifstream file("./Islemler.txt");
    if (file.is_open())
    {
        char islem;
        int sayi1;
        int sayi2;
        while(file.get(islem)){
            if(islem == 'C'){
                file >> sayi1;
                file >> sayi2;
                caprazSayac++;
                cout << caprazSayac << ". caprazlama islemi yapiliyor..." << endl;
                Caprazla(sayi1, sayi2);
                cout << endl;
            }
            else if(islem == 'M'){
                file >> sayi1;
                file >> sayi2;
                mutSayac++;
                cout << mutSayac << ". mutasyon islemi yapiliyor..." << endl;
                Mutasyon(sayi1, sayi2);
                cout << endl;
            }
        }
    }    
    else    
    {
        cout << "Dosya acilamadi." << endl;
    }
}

void Dna::ekranaYaz(){
    Kromozom *pKrom = getHeadKrom();
    Gen *pGen = pKrom->getGenHead();
    
    while (pKrom != nullptr){

        char firstGenNuc = pKrom->getGenHead()->getNuc();
        pGen = pKrom->getGenTail();

        while(pGen != nullptr){
            if (pGen->getNuc() < firstGenNuc)
            {
                cout << pGen->getNuc() << " ";
                break;
            }
            else if (pGen == pKrom->getGenHead())
            {
                cout << pGen->getNuc() << " ";
                break;
            }
            else{
                pGen = pGen->getPrev();
            }
        }
        pKrom = pKrom->getNext();
    }  
}

