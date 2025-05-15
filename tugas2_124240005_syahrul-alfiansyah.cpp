#include <iostream>
using namespace std;

struct barang {
    string nama;
    string kode;
    int harga;
    int stok;
    barang* next; 
};
barang* head = NULL;

void kembali(){
    char back;
    cout << "Kembali Ke Menu Utama? (y/n): ";
    cin >> back;

    if(back == 'y' || back == 'Y'){
    }else if(back == 'n' || back == 'N'){
        cout << "Terima Kasih BYE BYE";
        exit(0);
    }
}

void tambahBarang(){
    int jumlah;
    cout << "Jumlah Barang Ditambahkan: ";
    cin >> jumlah;

        for(int i = 1; i <= jumlah; i++){
            barang* baru = new barang;

            cout << "Barang ke-" << i << endl;
            cout << "Masukkan Kode Barang: ";
            cin >> baru->kode;
            cout << "Masukkan Nama Barang: ";
            cin >> baru->nama;
            cout << "Masukkan Harga Barang: ";
            cin >> baru->harga;
            cout << "Masukkan Stok Barang: ";
            cin >> baru->stok;
            baru->next = NULL;
        if(head == NULL || baru->harga < head->harga){
            baru->next = head;
            head = baru;
        }else{
            barang* temp = head;
            while(temp->next != NULL && temp->next->harga <= baru->harga){
                temp = temp->next;
            }
            baru->next = temp->next;
            temp->next = baru;
        }
        cout << "Barang ke-" << i << " Berhasil Ditambahkan\n" << endl;
    }
    kembali();
}

void tampilBarang(bool termurah){
    barang* temp = head;

    if(temp == NULL){
        cout << "Tidak Ada Barang Yang Tersedia\n";
        return;
    }
    barang* arr[100];
    int n = 0;
    while(temp != NULL){
        arr[n++] = temp;
        temp = temp->next;
    }

    
    if(termurah){
        cout << "=====Harga Termurah=====\n";
        cout << "     Daftar Barang      \n";
        cout << "---------------------------\n";
        cout << "Nama | Kode | Harga | Stok\n";
        cout << "---------------------------\n\n";
        for(int i = 0; i < n; i++){
            cout << arr[i]->nama << " | " << arr[i]->kode << " | " 
                 << arr[i]->harga << " | " << arr[i]->stok << endl << endl;
        }
    }else {
        cout << "=====Harga Termahal=====\n";
        cout << "     Daftar Barang      \n";
        cout << "---------------------------\n";
        cout << "Nama | Kode | Harga | Stok\n";
        cout << "---------------------------\n\n";
        for(int i = n-1; i >= 0; i--){
            cout << arr[i]->nama << " | " << arr[i]->kode << " | "
                 << arr[i]->harga << " | " << arr[i]->stok << endl << endl; 
        }
    }
}

void hapusBarang(){
    if(head == NULL){
        cout << "Tidak Ada Barang Yang Tersedia\n";
        return;
    }

    barang* temp = head;
    int no = 1;

    cout << "=====Daftar Barang=====\n";
    cout << "Nama | Kode | Harga | Stok\n";
    cout << "---------------------------\n";
    while(temp != NULL){
        cout << no << ". " << temp->nama << " | " << temp->kode << " | "
             << temp->harga << " | " << temp->stok << endl;
        temp = temp->next;
        no++;
    }


    string hapus;
    cout << "=====Hapus Barang=====\n";
    cout << "Masukan Nama Barang Yang Ingin Dihapus: ";
    cin >> hapus;

    temp = head;
    barang* prev = NULL;
    while(temp != NULL && temp->nama != hapus){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Barang Tidak Ditemukan\n";
        return;
    }
    if(prev == NULL){
        head = temp->next;
    }else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Barang Berhasil Dihapus\n";

    kembali();
}

void menuTampilBarang(){
    int pilih;
    cout << "Tampilkan Barang Berdasarkan Harga\n";
    cout << "1. Dari Harga Termurah\n";
    cout << "2. Dari Harga Termahal\n";
    cout << ": ";
    cin >> pilih;
    if(pilih == 1){
        tampilBarang(true); // Dari Harga Termurah
    }else if(pilih == 2){
        tampilBarang(false); // Dari Harga Termahal
    }else {
        cout << "Tidak Ada Pilihan";
    }
    kembali();
}

void menu(){
    cout << "=========================================\n";
    cout << "------Sistem Manajemen Stok Gudang-------\n";
    cout << "=========================================\n";
    cout << "1. Input Stok Barang\n";
    cout << "2. Lihat Stok Barang\n";
    cout << "3. Hapus Barang Dari Stok\n";
    cout << "0. Keluar\n";
}

int main(){
    int pilih;
    
    do{
        menu();
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch(pilih){
            case 1:
                tambahBarang();
                break;
            case 2:
                menuTampilBarang();
                break;
            case 3:
                hapusBarang();
                break;
            case 0:
                cout << "Terima Kasih BYE BYE";
                break;
            default:
                cout << "Tidak Valid\n";
        }

    }while(pilih != 0);
    return 0;
}