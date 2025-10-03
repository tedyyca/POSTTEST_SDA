#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};


void sortedInsert(Node*& head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // --- LENGKAPI DI SINI ---
    // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
    if (data <= head_ref->data) {
        Node* tail = head_ref->prev; // Dapatkan tail
        
        newNode->next = head_ref;
        head_ref->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        
        head_ref = newNode; // Update head baru
        return;
    }

    // Kasus 3: Cari posisi yang tepat (tengah/akhir)
    Node* current = head_ref;
    // Loop sampai menemukan posisi yang tepat atau kembali ke head
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // Sisipkan newNode setelah current
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
    // --- LENGKAPI DI SINI ---
}

void printList(Node* head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    Node* current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node* head = nullptr;


    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (urutan tetap): ";
    printList(head); 
    return 0;
}