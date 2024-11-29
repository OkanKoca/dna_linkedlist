/**       
* @file  main.cpp
* @description Programın başlangıç noktası olan main fonksiyonunun bulunduğu, menu şeklinde işlem seçenekleri sunan dosya.
* @course  1.öğretim A grubu
* @assignment  1.ödev
* @date  26/11/2024 (daha önce başladım fakat bu kısmı yazmayı unuttuğum için tarihini hatırlamıyorum.)
* @author  Okan KOCA - b231210016@sakarya.edu.tr
*/ 
#include<iostream>
#include "Dna.hpp"
#include <chrono>
using namespace std;

int main(){

    // auto start = chrono::high_resolution_clock::now();

    Dna *dna = new Dna(); // constructor ile GenOku fonksiyonu çağırılır, genler okunur, kromozomlar oluşturulur.

    // auto end = chrono::high_resolution_clock::now();
    // auto sure = chrono::duration_cast<chrono::milliseconds>(end - start); // süre milisaniye cinsinden hesaplanır.
    // //chrono::duration<double> sure = end - start; // okuma süresi hesaplanır.

    // cout << "okuma suresi: " << sure.count() << " milisaniye" << endl;  // SUREYI KONTROL AMACLI YAZILDI. YORUM SATIRINDAN ÇIKARILIP KONTROL EDİLEBİLİR.


    int secim;

    do{
        
    cout << endl << endl;
    cout << "----------1. Caprazlama----------" << endl;
    cout << "----------2. Mutasyon----------" << endl;
    cout << "----------3. Otomatik Islemler----------" << endl;
    cout << "----------4. Ekrana Yazdir----------" << endl;
    cout << "----------5. Cikis----------" << endl;
    cout << "secim yapiniz: ";
    cin >> secim;
    cout << endl << endl;

    switch (secim)
    {
        case 1:
            int krom1, krom2;
            cout << "Caprazlanacak 1. kromozom indexini giriniz: ";
            cin >> krom1;
            cout << "Caprazlanacak 2. kromozom indexini giriniz: ";
            cin >> krom2;
            dna->Caprazla(krom1, krom2);
            break;
        case 2:
            int satir, sutun;
            cout << "Mutasyon yapilacak kromozom indexini giriniz: ";
            cin >> satir;
            cout << "Mutasyon yapilacak gen indexini giriniz: ";
            cin >> sutun;
            dna->Mutasyon(satir, sutun);
            break;
        case 3:
            dna->OtomatikIslemler();
            break;
        case 4:
            dna->ekranaYaz();
            break;
        case 5: 
            cout << "Programdan cikiliyor..." << endl;
            break;
        default:
        cout << "gecersiz secim";
            break;
        }
        
    } while (secim != 5);
    
    delete dna; // destructor çağırılır.
    
    return 0;
}