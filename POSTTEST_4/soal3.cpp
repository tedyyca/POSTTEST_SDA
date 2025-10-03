#include <iostream>
#include <string>

using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};
    
    // --- LENGKAPI DI SINI ---
    // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
    if (front == nullptr) {
        front = rear = newNode;
    } 
    // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
    else {
        rear->next = newNode;
        rear = newNode;
    }
    // --- LENGKAPI DI SINI ---
}

// Fungsi untuk mengambil dan menghapus elemen dari depan antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; 
    
    // --- LENGKAPI DI SINI ---
    // 1. Simpan data dan node dari front
    string docData = front->document;
    Node* temp = front;

    // 2. Geser front ke front->next
    front = front->next;

    // 3. Jika front menjadi nullptr (queue jadi kosong), set rear juga ke nullptr
    if (front == nullptr) {
        rear = nullptr;
    }

    // 4. Delete node lama dan return data
    delete temp;
    return docData;
    // --- LENGKAPI DI SINI ---
}

// Fungsi untuk memproses semua dokumen dalam antrian
void processAllDocuments(Node*& front, Node*& rear) {
    // --- LENGKAPI DI SINI ---
    // Loop hingga queue kosong, dequeue dan print setiap dokumen
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
    cout << "Semua dokumen telah diproses." << endl;
    // --- LENGKAPI DI SINI ---
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}