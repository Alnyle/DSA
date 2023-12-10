#include <iostream>
using namespace std;

template <class T>

class stack
{

    struct Node
    {
        T item;
        Node *next;
    };

    Node *top, *cur;
    int length, Size;

public:
    stack()
    {
        top = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(T item)
    {
        Node *newItemPtr = new Node;
        newItemPtr->item = item;
    
        if (isEmpty()) {
            top = newItemPtr;
            newItemPtr->next = NULL;
        }
        else {
            newItemPtr->next = top;
            top = newItemPtr;
        }
        length++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Can not pop stack elements stack is empty";
        }
        else
        {
            Node *temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
            length--;
        }
    }

    T getTop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty can not get Top!";
            return;
        }

        return top->item;
    }

    int getSize() {
        return length;
    }


    void print() {
        cur = top;
        cout << "[";
        while (cur != NULL) {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]";
    }
};

int main()
{
    stack<int> s;
    s.push(2);
    s.push(42);
    s.push(52);
    s.pop();
    s.print();
}