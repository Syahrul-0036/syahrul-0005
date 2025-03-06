#include <iostream>
using namespace std;

void menu();
void inputData();
void tampilData();
void searching();
void sorting();
void bubblesort();
void tanya();

struct kendaraan{
    int plat;
    string merk;
    string jenis;
    string model;
    string nama;
    int tahun;
};
    kendaraan datakendaraan[150];
    int jumlahkendaraan = 0;

int main(){
    FILE *ptr;
    int pilihan;
    do{
        menu();
        cout << "Pilih Menu Yang Ingin Di lakukan : "; 
        cin >> pilihan; 
        switch (pilihan)
        {
            case 1:
            inputData();
            break;
            case 2:
            tampilData();
            break;
            case 3:
            searching();
            break;
            case 4:
            sorting();
            case 5:
            cout << "terima Kasih" << endl;
            default :
            ;
        }
    }while (pilihan != 5);
    return 0;    
}

void tanya(){
    char lagi;
    do{
        cout << "Apakah Anda Ingin Memilih Menu yang lain? (y/n)";
        cin >> lagi;
    }while(lagi != 'y' || lagi != 'n');
    cout << "Terima Kasih";
}

void menu(){
    cout << "\n============================\n";
    cout << "        MENU PILIHAN        \n";
    cout << "============================\n";
    cout << "1. Input Data Kendaraan\n";
    cout << "2. Tampilkan Seluruh Data Kendaraan\n";
    cout << "3. Searching\n";
    cout << "4. Sorting\n";
    cout << "5. Exit\n";
    cout << "============================\n";
    
}

void inputData(){
    FILE *simpan;
    int tambah;
    cout << "masukan banyak kendaraan : ";
    cin >> tambah;
    cin.ignore();

    if(jumlahkendaraan + tambah > 0){
        cout << "Data melebih Batas" << endl;

    }
    for(int i = jumlahkendaraan; i < jumlahkendaraan + tambah; i++){
        cout << "\nKendaraan ke-" << (i + 1) << ":" << endl;

        cout << "Masukan Nomor Kendaraan : ";
        cin >> datakendaraan[i].plat;

        cout << "Masukan Jenis Kendaraan : ";
        cin >> datakendaraan[i].jenis;

        cout << "Masukan Merk Kendaraan : ";
        cin >> datakendaraan[i].merk;

        cout << "Masukan Model Kendaraan : ";
        cin >> datakendaraan[i].model;

        cout << "Masukan Nama Pemilik : ";
        cin >> datakendaraan[i].nama;

        cout << "Masukan Tahun Produksi : ";
        cin >> datakendaraan[i].tahun;
    }
    jumlahkendaraan += tambah;
    cout << "\nData telah di tambahkan" << endl;

}

void tampilData(){
    if(jumlahkendaraan == 0){
        cout << "Tidak ada data yang tersedia" << endl;
    }
    cout << "\nDaftar Kendaraan : \n";
    for (int i = 0; i < jumlahkendaraan; i++){
        cout << "\nNomor Kendaraan : " << datakendaraan[i].plat
             << "\nJenis Kendaraan : " << datakendaraan[i].jenis
             << "\nMerk Kendaraan : " << datakendaraan[i].merk
             << "\nModel Kendaraan : " << datakendaraan[i].model
             << "\nNama Pemilik : " << datakendaraan[i].nama
             << "\nTahun Produksi : " << datakendaraan[i].tahun << endl;
    }
}
void searching(){ // sequntial search
    string cari;
    bool found = false;
    int i = 0;

    if (jumlahkendaraan == 0){
        cout << "Data Kosong" << endl;
        return;
    }
    cout << "Masukan Nama Pemilik Kendaraan yang ingin di cari : "; cin >> cari;
    
    while ((i < jumlahkendaraan) && !found){
        if (datakendaraan[i].nama == cari){
            found = true;
        } else {    
            i++;
        }
    }
    if (found){
        cout << "Kendaraan yang ditemukan:\n";
        cout << "\nNomor Kendaraan : " << datakendaraan[i].plat
             << "\nJenis Kendaraan : " << datakendaraan[i].jenis
             << "\nMerk Kendaraan : " << datakendaraan[i].merk
             << "\nModel Kendaraan : " << datakendaraan[i].model
             << "\nNama Pemilik : " << datakendaraan[i].nama
             << "\nTahun Produksi : " << datakendaraan[i].tahun << endl;
    } else {
        cout << "Kendaraan dengan Nama " << cari << " tidak ditemukan" << endl;
    }
}
void sorting(){
    int metode;
    if(jumlahkendaraan == 0){
        cout << "Data Kosong" << endl;
    }
    cout << "Pilih Metode Sorting"
         << "\n1. Bubble sort"
         << "\npilihan : ";
         cin >> metode;
         if(metode == 1){
            bubblesort();
         }else{
          cout << "Tidak sesuai pilihan" << endl;
         }

}
void bubblesort(){
    if (jumlahkendaraan == 0) {
        cout << "Belum ada data kendaraan untuk diurutkan.\n";
        return;
    }

    for (int i = 0; i < jumlahkendaraan - 1; i++) {
        for (int j = 0; j < jumlahkendaraan - i - 1; j++) {
            if (datakendaraan[j].tahun > datakendaraan[j + 1].tahun) {
                swap(datakendaraan[j], datakendaraan[j + 1]);
            }
        }
    }
    
    cout << "Data kendaraan telah diurutkan berdasarkan tahun produksi.\n";
}
