#include <iostream>
#include <fstream>
#include <cstring> 
using namespace std;


struct Urun {
    char urunAdi[50];
    float fiyat;
    int stok;
};


void urunEkle() {
    Urun urun;
    ofstream dosya("urunler.dat", ios::binary | ios::app); 

    
    cout << "Urun Adi: ";
    cin.ignore(); 
    cin.getline(urun.urunAdi, 50);
    cout << "Fiyat: ";
    cin >> urun.fiyat;
    cout << "Stok Miktari: ";
    cin >> urun.stok;

   
    dosya.write((char*)&urun, sizeof(Urun));
    dosya.close();
    cout << "Urun baþarýyla eklendi!\n";
}


void urunListele() {
    Urun urun;
    ifstream dosya("urunler.dat", ios::binary); 

    if (!dosya) {
        cout << "Dosya acilamadi veya henuz urun eklenmedi.\n";
        return;
    }

    
    cout << "Mevcut Urunler:\n";
    cout << "---------------------------------------\n";
    while (dosya.read((char*)&urun, sizeof(Urun))) {
        cout << "Urun Adi: " << urun.urunAdi << endl;
        cout << "Fiyat: " << urun.fiyat << " TL" << endl;
        cout << "Stok: " << urun.stok << " adet" << endl;
        cout << "---------------------------------------\n";
    }

    dosya.close();
}


void menu() {
    int secim;
    do {
        cout << "\n--- Zuccaciye Otomasyonu ---\n";
        cout << "1. Urun Ekle\n";
        cout << "2. Urun Listele\n";
        cout << "3. Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
            case 1:
                urunEkle();
                break;
            case 2:
                urunListele();
                break;
            case 3:
                cout << "Cikis yapiliyor...\n";
                break;
            default:
                cout << "Gecersiz secim. Tekrar deneyin.\n";
        }
    } while (secim != 3);
}

int main() {
    menu(); 
    return 0;
}

