#include <iostream>

using namespace std;

// my version
// template<class T>
// void bubbleSort(T data[], int n) {

//     for (int i = 0, j;i < n; i++) {

//         for(j = 1; j < n; j++) {
//             if (data[j] < data[j - 1])
//                 swap(data[j], data[j - 1]);
//         }
//     }
// }

//
template <class T>
void bubbleSort(T data[], int n)
{

    for (int i = 0, j; i < n - 1; i++)
    {

        for (j = n - 1; j > i; j--)
        {
            if (data[j] < data[j - 1])
            {
                swap(data[j], data[j - 1]);
            }
        }
    }
}

template <class T>
void print(T data[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}

template <class T>
void swap(int &first, int &second)
{

    T temp = first;
    first = second;
    first = temp;
}

int main()
{

    int data[] = {1, 6, 4, 3, 2};

    bubbleSort(data, 5);
    print(data, 5);

    return 0;
}