#include<iostream>
#include "Dna.hpp"
#include "Kromozom.hpp"
#include <chrono>
using namespace std;

int main(){

    Dna dna;

    auto start = chrono::high_resolution_clock::now();
    dna.GenOku();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> sure = end - start;

    cout << "okuma suresi: " << sure.count() << " saniye" << endl;
    //dna.printChromosomes(dna.getHeadKrom());
    system("pause");
    dna.ekranaYaz();
    //dna.Caprazla(3,8);
    //dna.OtomatikIslemler();
    //cout << "otomatik islemler yapildi" << endl;
    system("pause");
    
    return 0;
}