#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
template <class T>
class queue
{

    struct Node
    {
        T item;
        Node *next;
    };
    Node *first, *rear;
    int Size;
    int length;

public:
    queue(int size = 10)
    {
        if (size <= 0)
        {
            Size = 100;
        }
        else
        {
            Size = size;
        }

        length = 0;
        first = rear = NULL;
    }

    bool isEmpty()
    {
        return first == NULL;
    }

    bool isFull()
    {
        return length >= Size;
    }

    int getSize() {
        return length;
    }

    void push(T element)
    {

        if (isFull())
        {
            cout << "Queue is Empty can not push to stack";
            return;
        }

        Node *newItemPtr = new Node;
        newItemPtr->item = element;
        newItemPtr->next = NULL;
        if (isEmpty())
        {
            first = rear = newItemPtr;
        }
        else
        {
            rear->next = newItemPtr;
            rear = newItemPtr;
        }

        length++;
    }

    void pop()
    {

        if (isEmpty())
        {
            cout << "Queue is Empty can not pop!";
            return;
        }

        if (length == 1)
        {
            first = rear = NULL;
        }
        else
        {
            Node *temp = first;
            first = first->next;
            temp->next = NULL;
            delete temp;
        }

        length--;
    }

    T getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty can not get Front!";
            return 0;
        }

        return first->item;
    }

    T getBack()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty can not get Front!";
            return 0;
        }

        return rear->item;
    }


    void clear() {
        Node *current = first;
        while(first != NULL) {
            current = first;
            first = first->next;
            delete current;
        }
        rear = NULL;
        length = 0;
    }

    void print() {
        if (isEmpty())
        {
            cout << "Queue is Empty is Empty!";
            return;
        }

        Node *current = first;
        cout << "[";
        while(current != NULL) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << "]";
    }

};

int main()
{

    queue<int> q;
    q.push(12);
    q.push(14);
    q.push(11);
    q.push(10);
    // q.pop();
    cout << q.getFront() << endl;
    cout << q.getBack() << endl;
    q.clear();
    q.print();
}