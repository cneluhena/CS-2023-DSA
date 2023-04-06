#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int top = -1;
int* stack;

bool isEmpty(){
    if (top == -1){
        return true;
    }
    else{
        return false;
    }

}

void push(int ele, int size){
    top += 1;
    if (top >= size){
        cout << "Stack Overflow";
    }
    stack[top] = ele;
}

int pop(){
    if (isEmpty()){
        cout << "Stack Underflow";
        return 0;
    }
    else {
        top -= 1;
        return stack[top+1];
    }
}

void display(){
    for (int i=0; i <= top; i++){
        cout << stack[i] << " ";

    }
    cout << endl;
}



int main(){
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    stack = new int[size];
    clock_t begin = clock();
    push(8, size);
    push(10, size);
    push(5, size);
    push(11, size);
    push(15, size);
    push(23, size);
    push(6, size);
    push(18, size);
    push(20, size);
    push(17, size);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    push(4, size);
    push(30, size);
    push(3, size);
    push(1, size);
    display();
    clock_t end = clock();
    double duration_1 = ((float)(end-begin)/CLOCKS_PER_SEC)*pow(10, 6);
    cout << "Exceution Time is " << duration_1;

}
