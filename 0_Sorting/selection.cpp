// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void selection(T data[], int n)
{

    for (int i = 0, j, least; i < n - 1; i++)
    {

        for (j = i + 1, least = i; j < n; j++)
            if (data[j] < data[least])
                least = j;

        swap(data[i], data[least]);
    }
}





template <class T>
void print(T arr[], int n)
{
    cout << '[';
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << ']';
}

template <class T>
void swap(T &first, T &second)
{
    T temp = first;
    first = second;
    second = temp;
}

int main()
{

    int data[] = {1, 6, 4, 3, 2};

    selection(data, 5);
    print(data, 5);

    return 0;
}