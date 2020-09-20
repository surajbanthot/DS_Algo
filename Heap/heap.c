#include <stdio.h>

void Insert(int H[], int n)
{
    int i = n, temp;

    temp = H[i];

    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}

int Delete(int A[], int n)
{
    int i, j, x, val;
    val = A[1];
    int temp;
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;

    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

int main()
{

    int H[] = {0,10,20,30,25,5,40,35};

    // Insert(H,2);
    // Insert(H,3);
    // Insert(H,4);

    int i;
    for (i = 2; i <= 7; i++)
        Insert(H, i);

        for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);
    printf("\n");

    printf("Deleted Value is %d\n", Delete(H, 7));

    for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}