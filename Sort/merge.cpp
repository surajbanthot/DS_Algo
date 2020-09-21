#include <iostream>
using namespace std;

//Merges two subarrays of arr[]
//first subarray is arr[1...m]
//second subarray is arr[m+1....r]

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    //merging the temp arrays back into arr[1..r]
    i = 0;
    j = 0;
    k = l; // Initial Index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] == L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m ,r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for(i=0;i<size; i++)
    cout<<A[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[]={12, 11,13, 5,6,7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given array is \n";
    printArray(arr, arr_size);
    
    mergesort(arr, 0, arr_size-1);

    cout<<"\n Sorted Array is \n";
    printArray(arr, arr_size);
    return 0;
}