#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
class stack {

    T *arr;
    int top;
    int length;
    int Size;
    public:

    stack(int size = 10) {
        if (size < 0) 
            Size = 100;
        
        Size = size;
        top = -1;
        arr = new T[Size];
        length = 0;
    }  

    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return top >= Size;
    }

    void push(T item) {
        if(!isFull()) {
            top++;
            arr[top] = item;
            length++;
        }
        else 
            cout << "Stack is Full can not push!";
    }

    void pop() {
        if (!isEmpty()) {
            top--;
            length--;
        }
        else 
            cout << "Stack is Empty can not pop!";
    }


    T getTop() {
        if (isEmpty()) {
            cout << "Stack is Empty can not get top";
            return 0;
        }

        return arr[top];
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is Empty!";
            return;
        } 

        cout << "[";
        for (int i = top; i > -1; i--) {
            cout << arr[i] << " ";
        }

        cout << "]";
    }

};



int main() 
{

    stack<int> s(20);
    s.push(12);
    s.push(8231);
    s.push(8231);
    s.push(31);
    s.push(3);
    s.push(2);
    s.push(422);
    s.pop();
    s.print();




}