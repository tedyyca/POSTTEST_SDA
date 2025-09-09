#include <iostream>
using namespace std;

void tampilkanMatriks(int matriks[3][3]) {
    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int hitungDiagonalUtama(int matriks[3][3]) {
    int jumlah = 0;
    cout << "Diagonal Utama: ";
    for (int i = 0; i < 3; i++) {
        jumlah += matriks[i][i];
        cout << matriks[i][i];
        if (i < 2) cout << " + ";
    }
    cout << " = " << jumlah << endl;
    return jumlah;
}

int hitungDiagonalSekunder(int matriks[3][3]) {
    int jumlah = 0;
    cout << "Diagonal Sekunder: ";
    for (int i = 0; i < 3; i++) {
        jumlah += matriks[i][2-i];
        cout << matriks[i][2-i];
        if (i < 2) cout << " + ";
    }
    cout << " = " << jumlah << endl;
    return jumlah;
}

int main() {
    // Saya mendeklarasikan matriks di awal
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "SOAL 2. Array 2D" << endl;
    cout << "Menghitung jumlah diagonal utama + diagonal sekunder" << endl << endl;
    
    tampilkanMatriks(matriks);
    
    
    cout << "HASIL PERHITUNGAN: " << endl;
    int diagonalUtama = hitungDiagonalUtama(matriks);
    int diagonalSekunder = hitungDiagonalSekunder(matriks);
    int totalDiagonal = diagonalUtama + diagonalSekunder;
    
    cout << endl;
    cout << "Total (Diagonal Utama + Diagonal Sekunder) = " 
         << diagonalUtama << " + " << diagonalSekunder 
         << " = " << totalDiagonal << endl;
    
    return 0;
}