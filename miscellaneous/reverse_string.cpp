#include <iostream>
using namespace std;
int main()
{
    char A[] = "python";
    int i, j;
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j = j - 1;
    cout << j << endl;
    for (i = 0; i < j; j--, i++)
    {
        char temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    for (int j = 0; A[j] != '\0'; j++)
        cout << A[j];
    return 0;
}