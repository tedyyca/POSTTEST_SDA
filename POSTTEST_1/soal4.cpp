#include <iostream>
#include <string>
using namespace std;


void tukarNilai(int **a, int **b) {
    cout << "Dalam fungsi tukarNilai():" << endl;
    cout << "  Nilai **a sebelum: " << **a << endl;
    cout << "  Nilai **b sebelum: " << **b << endl;
    
    int temp = **a;  
    **a = **b;       
    **b = temp;      
    
    cout << "  Nilai **a sesudah: " << **a << endl;
    cout << "  Nilai **b sesudah: " << **b << endl;
}

void tampilkanStatus(int nilai1, int nilai2, int *ptr1, int *ptr2, const string &waktu) {
    cout << waktu << endl;
    cout << "Nilai 1: " << nilai1 
         << " (alamat: " << &nilai1 << ")" << endl;
    cout << "Nilai 2: " << nilai2 
         << " (alamat: " << &nilai2 << ")" << endl;
    cout << "ptr1 menunjuk ke: " << *ptr1 
         << " (alamat ptr1: " << &ptr1 
         << ", alamat yang ditunjuk: " << ptr1 << ")" << endl;
    cout << "ptr2 menunjuk ke: " << *ptr2 
         << " (alamat ptr2: " << &ptr2 
         << ", alamat yang ditunjuk: " << ptr2 << ")" << endl;
    cout << endl;
}

int main() {
    int nilai1, nilai2;
    int *ptr1, *ptr2;
    
    cout << "SOAL 4. Pointer pada fungsi" << endl;
    cout << "Menggunakan double pointer (int **) untuk menukar nilai" << endl << endl;
    
    
    cout << "Masukkan nilai pertama: ";
    cin >> nilai1;
    cout << "Masukkan nilai kedua: ";
    cin >> nilai2;
    cout << endl;
    
    ptr1 = &nilai1;
    ptr2 = &nilai2;
    

    tampilkanStatus(nilai1, nilai2, ptr1, ptr2, "Sebelum di tukar: ");
    
    cout << "melakukan pertukaran nilai" << endl;
    cout << "Memanggil fungsi tukarNilai(&ptr1, &ptr2)" << endl;
    tukarNilai(&ptr1, &ptr2);
    cout << endl;
    
    
    tampilkanStatus(nilai1, nilai2, ptr1, ptr2, "Setelah di tukar: ");
    
    return 0;
}