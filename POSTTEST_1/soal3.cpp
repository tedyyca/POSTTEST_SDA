#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

// Fungsi untuk mencari mahasiswa dengan IPK tertinggi
int cariIPKTertinggi(Mahasiswa mhs[], int jumlah) {
    int indexMax = 0;
    for (int i = 1; i < jumlah; i++) {
        if (mhs[i].ipk > mhs[indexMax].ipk) {
            indexMax = i;
        }
    }
    return indexMax;
}


void tampilkanMahasiswa(const Mahasiswa &mhs, int nomor = 0) {
    if (nomor > 0) {
        cout << "Mahasiswa ke-" << nomor << ":" << endl;
    }
    cout << "Nama: " << mhs.nama << endl;
    cout << "NIM : " << mhs.nim << endl;
    cout << "IPK : " << mhs.ipk << endl;
}

int main() {
    Mahasiswa mahasiswa[5];
    int jumlahMahasiswa = 5;
    
    cout << "3. Struct + Array "<< endl;
    cout << "Input 5 mahasiswa dan menampilkan mahasiswa dengan IPK tertinggi" << endl << endl;
    
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Data Mahasiswa ke-" << (i + 1) <<endl;
        
        cout << "Nama: ";
        cin.ignore(); // membersihkan buffer untuk input pertama
        getline(cin, mahasiswa[i].nama);
        
        cout << "NIM : ";
        getline(cin, mahasiswa[i].nim);
        
        cout << "IPK : ";
        cin >> mahasiswa[i].ipk;
        
        cout << endl;
    }
    
    
    int indexTertinggi = cariIPKTertinggi(mahasiswa, jumlahMahasiswa);
    
    cout << "DAFTAR MAHASISWA" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        tampilkanMahasiswa(mahasiswa[i], i + 1);
        
    }
    
   
    cout << "Mahasiswa dengan IPK tertinggi adalah:" << endl;
    tampilkanMahasiswa(mahasiswa[indexTertinggi]);
    cout << endl;
    cout << "IPK Tertinggi: " << mahasiswa[indexTertinggi].ipk << endl;
    
    return 0;
}