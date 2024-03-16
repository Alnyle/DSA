#include <bits/stdc++.h>

using namespace std;

// int partition(int arr[], int start, int end) {

//     int i = start;
//     int j = end;
//     int pivot = i;

//     while (true) {

//         while (arr[pivot] <= arr[j] && pivot != j) {
//             j--;
//         }
//         if (pivot == j)
//             break;
//         else if (arr[pivot] > arr[j]) {
//             swap(arr[pivot], arr[j]);
//             pivot = j;
//         }

//         while (arr[pivot] >= arr[i] && pivot != i) {i++;}
//         if (pivot == i) break;
//         else if (arr[pivot] < arr[i]) {
//             swap(arr[i], arr[pivot]);
//             pivot = i;
//         }
//     }
//      return pivot;
// }

int partition(int arr[], int start, int end)
{

    int i = start;
    int j = end;
    int pivot = arr[i];
    while (i < j)
    {

        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j) 
            swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);
    return j;
}

void quickSort(int arr[], int start, int end)
{

    if (start < end)
    {
        int piv = partition(arr, start, end);
        quickSort(arr, start, piv);
        quickSort(arr, piv + 1, end);
    }
}

int main()
{

    int arr[] = {2, -1, 4, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}