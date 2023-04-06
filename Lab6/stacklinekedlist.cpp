#include <iostream>
#include<cmath>
#include<ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}



bool isEmpty() {
    return top == NULL;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty";
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    clock_t begin = clock();
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    push(4);
    push(30);
    push(3);
    push(1);
    display();
    clock_t end = clock();
    double duration_1 = ((float)(end-begin)/CLOCKS_PER_SEC)*pow(10, 6);
    cout << "Exceution Time is " << duration_1;
    return 0;


}