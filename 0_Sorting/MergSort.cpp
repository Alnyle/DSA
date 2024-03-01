#include <iostream>

using namespace std;

// left: first index of array
// right: second indx of array
void merge(int arr[], int left, int mid, int right) {


    int i, j, k;
    // remember left is less mid as index
    int n1 = mid - left + 1; // size of left array -> 4
    int n2 = right - mid; // size of left array -> 3

    int *L = new int[n1], *R = new int[n2];
    // fill the two arrays (n1, n2)
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = j = 0;
    k = left; // 0

    // merge the two arrays based on sort 
    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    
}


void mergeSort(int arr[], int left, int right) { // size of the array = 7 , left = 0 ,right =  6

    if (left < right) {

        int mid = left + (right - left) / 2; // 3

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid,right);

    }

}



void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int data[] = {2, 7, 5, 4, 3, 1, 6};

    int n = sizeof(data) / sizeof(data[0]);

    mergeSort(data, 0, n - 1);
    print(data, 5);

    return 0;
}