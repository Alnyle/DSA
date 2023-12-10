#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class queue
{

    T *arr;
    int first, rear;
    int length;
    int Size;

public:
    queue(int size = 10)
    {
        if (size < 0)
        {
            Size = 100;
        }
        else {
            Size = size;
        }


        first = 0;
        rear = Size - 1;
        arr = new T[Size];
        length = 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == Size;
    }

    void push(T element)
    {

        if (isFull())
        {
            cout << "Queue is Full can not push";
        }
        else
        {
            rear = (rear + 1) % Size;
            arr[rear] = element;
            length++;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty can not pop";
        }
        else
        {
            first = (first + 1) % Size;
            length--;
        }
    }

    int getSize()
    {
        return length;
    }

    T getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty can not get Front!";
            return 0;
        }
        else
        {
            return arr[first];
        }
    }

    T getBack()
    {

        if (isEmpty())
        {
            cout << "Queue is Empty can not get back";
            return 0;
        }
        else
        {
            return arr[rear];
        }
    }

    void print()
    {

        cout << "[";
        for (int i = first; i != rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << " ";
        cout << "]";
    }


    int search(T element) {
        int pos = -1;

        if (!isEmpty()) {

            for (int i = first; i != rear; i = (i + 1) % Size) {
                if (arr[i] == element) {
                    pos = i;
                    break;
                }
            }



            if (pos == -1) {
                if (arr[rear] == element) {
                    pos = rear;
                }
            }    
        }

        return pos;
    }
};

int main()
{
    
    // Add(back) / Remove(Front) O(1)
    // Access(Front, Back) O(1)
    // Search O(N)
    queue<char> q(5);
    q.push('A');
    q.push('B');
    q.push('S');
    q.push('L');
    q.push('X');
    cout << q.search('o') << endl;
    cout << q.getFront() << endl;
    q.print();

}