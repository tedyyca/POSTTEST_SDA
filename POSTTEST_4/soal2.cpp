#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi untuk memeriksa keseimbangan tanda kurung
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;
    
    // --- LENGKAPI DI SINI ---
    // 1. Loop setiap karakter dalam `expr`.
    for (char c : expr) {
        // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // 3. Jika karakter adalah kurung tutup ')', '}', ']'.
        else if (c == ')' || c == '}' || c == ']') {
            // a. Apakah stack kosong? Jika ya, return false.
            if (stackTop == nullptr) {
                return false;
            }

            // b. Pop stack, lalu cek apakah cocok.
            char topChar = pop(stackTop);
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false; 
            }
        }
    }

    // 4. Setelah loop, jika stack kosong, return true. Jika tidak, return false.
    return stackTop == nullptr;
    // --- LENGKAPI DI SINI ---
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    string expr3 = "([{}])";
    cout << expr3 << " -> " << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;//nyoba aja

    return 0;
}