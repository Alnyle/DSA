#include<iostream>

using namespace std;

void selectionSort(int arr[], int n) {

    for (int i = 0,j ,least; i < n - 1; i++) {

        for (j = i + 1, least = i; j < n ; j++) 
            if (arr[j] < arr[least])
                least = j;
        
        swap(arr[i], arr[least]);
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

    selectionSort(arr, n);
    for (int i : arr) {
        cout << i << " ";
    }
}