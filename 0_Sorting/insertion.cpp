#include<iostream>

using namespace std;


template<class T>
void insertion(T data[], int n) {

    for (int i = 1, j; i < n; i++) {
        T temp = data[i];

        for(j = i; j > 0 and temp < data[j - 1]; j--)
          data[j] = data[j - 1];

        data[j] = temp;
    }
  
}


template<class T>
void print(T arr[],int n) {
    cout << '[';
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    cout << ']';
}

template<class T>
void swap(T &first, T &second) {
    int temp = first;
    first = second;
    second = temp;
}

int main() {
    
    int data[] = {1, 6, 4, 3, 2};
    
    insertion(data, 5);
    print(data, 5);

    return 0;
}