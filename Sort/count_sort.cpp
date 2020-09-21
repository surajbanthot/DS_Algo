#include <iostream>
using namespace std;

int findMax(int A[], int n)
{
    int max = INT32_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countsort(int A[], int n)
{
    int i, j, max, *c;
    max=findMax(A, n);
    c = new int[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[A[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (c[j] > 0)
        {
            A[i++] = j;
            c[j]--;
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    countsort(A, n);
    for (i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}