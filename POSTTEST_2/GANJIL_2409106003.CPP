#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

int getJumlahAwal(const string& nim) {
    if (nim.empty()) return 1;
    if (nim.length() == 1) return nim[0] - '0';
    string last2 = nim.substr(max(0, (int)nim.length() - 2));
    try {
        return stoi(last2);
    } catch (...) {
        return 1;
    }
}

int getPosisiSisip(const string& nim) {
    if (nim.empty()) return 1;
    char last = nim[nim.length() - 1];
    if (last < '0' || last > '9') return 1;
    return (last - '0') + 1;
}

void tambahItem(Item*& head, const string& nama, const string& tipe, int jumlah) {
    Item* baru = new Item{nama, jumlah, tipe, nullptr};
    if (!head) {
        head = baru;
    } else {
        Item* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    cout << "Item berhasil ditambahkan!\n";
}

void sisipItem(Item*& head, const string& nama, const string& tipe, int jumlah, int posisi) {
    Item* baru = new Item{nama, jumlah, tipe, nullptr};
    if (posisi <= 1 || !head) {
        baru->next = head;
        head = baru;
    } else {
        Item* temp = head;
        int idx = 1;
        while (temp->next && idx < posisi - 1) {
            temp = temp->next;
            idx++;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "Item berhasil disisipkan!\n";
}

void hapusItemTerakhir(Item*& head) {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        cout << "Item terakhir dihapus!\n";
        return;
    }
    Item* temp = head;
    while (temp->next && temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    cout << "Item terakhir dihapus!\n";
}

void gunakanItem(Item*& head, const string& namaCari) {
    Item* temp = head;
    Item* prev = nullptr;
    while (temp) {
        if (temp->namaItem == namaCari) {
            temp->jumlah--;
            cout << "Item '" << namaCari << "' digunakan! Sisa: " << temp->jumlah << endl;
            if (temp->jumlah <= 0) {
                if (!prev) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Item '" << namaCari << "' habis dan dihapus dari inventory.\n";
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item tidak ditemukan!\n";
}

void tampilkanInventory(Item* head) {
    cout << "\n+---------------------------------------------+\n";
    cout << "|                INVENTORY GAME                |\n";
    cout << "+-----------------------------------------------+\n";
    if (!head) {
        cout << "|          Inventory Kosong                   |\n";
    } else {
        Item* temp = head;
        int idx = 1;
        while (temp) {
            cout << "| " << idx << ". " << temp->namaItem 
                 << " (" << temp->tipe << ") - Jumlah: " 
                 << temp->jumlah << "\n";
            temp = temp->next;
            idx++;
        }
    }
    cout << "+---------------------------------------------+\n";
}

int main() {
    string nama, nim;
    cout << "Masukkan Nama : ";
    getline(cin, nama);
    cout << "Masukkan NIM  : ";
    getline(cin, nim);

    int jumlahAwal = getJumlahAwal(nim);
    int posisiSisip = getPosisiSisip(nim);

    Item* inventory = nullptr;
    int pilihan;

    do {
        cout << "\n+--------------------------------------------------+\n";
        cout << "|           GAME INVENTORY MANAGEMENT              |\n";
        cout << "|        [ " << nama << " - " << nim << " ]\n";
        cout << "+--------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                              |\n";
        cout << "| 2. Sisipkan Item                                 |\n";
        cout << "| 3. Hapus Item Terakhir                           |\n";
        cout << "| 4. Gunakan Item                                  |\n";
        cout << "| 5. Tampilkan Inventory                           |\n";
        cout << "| 0. Keluar                                        |\n";
        cout << "+--------------------------------------------------+\n";
        cout << "Pilih menu : ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan = -1;
        } else {
            cin.ignore();
        }

        if (pilihan == 1) {
            string namaItem, tipe;
            cout << "Nama Item : "; getline(cin, namaItem);
            cout << "Tipe Item : "; getline(cin, tipe);
            tambahItem(inventory, namaItem, tipe, jumlahAwal);
        } else if (pilihan == 2) {
            string namaItem, tipe;
            cout << "Nama Item : "; getline(cin, namaItem);
            cout << "Tipe Item : "; getline(cin, tipe);
            sisipItem(inventory, namaItem, tipe, jumlahAwal, posisiSisip);
        } else if (pilihan == 3) {
            hapusItemTerakhir(inventory);
        } else if (pilihan == 4) {
            string namaItem;
            cout << "Nama Item yang ingin digunakan : "; getline(cin, namaItem);
            gunakanItem(inventory, namaItem);
        } else if (pilihan == 5) {
            tampilkanInventory(inventory);
        } else if (pilihan == 0) {
            cout << "Keluar dari program...\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    while (inventory) {
        Item* temp = inventory;
        inventory = inventory->next;
        delete temp;
    }
    return 0;
}
