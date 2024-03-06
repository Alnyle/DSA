#include<iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    
    for (int i = 1, j; i < n; i++) {
        
        // store current index in variable temp
        int temp = arr[i];

        
        for (j = i; j > 0 && temp < arr[j - 1]; j--) 
            arr[j] = arr[j - 1];

        arr[j] = temp;
    }
}

void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = first;
}

int main() {
    int arr[] = {3, 10, 7, -1, 31, 22, 14, 25};

    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    for (int i : arr) {
        cout << i << " ";
    }
}