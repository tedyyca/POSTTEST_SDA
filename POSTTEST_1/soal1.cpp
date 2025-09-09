#include <iostream>
using namespace std;

void balikArray(int *arr, int size) {
    int *start = arr;           
    int *end = arr + size - 1;  
    int temp;
    
    
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void tampilkanArray(int *arr, int size, const string &keterangan) {
    cout << keterangan << ": ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int data[7];
    int size = 7;
    
    cout << "SOAL 1. Array + Pointer " << endl;
    cout << "Mengisi array dengan kelipatan 3" << endl << endl;
    
    
    for (int i = 0; i < size; i++) {
        data[i] = (i + 1) * 3;
    }
    
    
    tampilkanArray(data, size, "Array sebelum dibalik");
    
    balikArray(data, size);

    tampilkanArray(data, size, "Array setelah dibalik");
    
    return 0;
}