#include<iostream>

using namespace std;

void shellSort(int arr[], int n) {

    for (int gap = n/2; gap > 0; gap /= 2) {

        for (int i = gap, j; i < n; i +=1) {
            int temp = arr[i];
            for (j = i; j >= gap && temp < arr[j - gap]; j -= gap)
                arr[j] = arr[j - gap];
            
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {3, 10, 7, -1, 31, 22, 14, 25};

    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);
    for (int i : arr) {
        cout << i << " ";
    }
}