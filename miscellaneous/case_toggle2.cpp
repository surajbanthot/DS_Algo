#include <iostream>
using namespace std;

int main()
{
    char A[] = "WeLCoME";

    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 65 && A[i] <= 90)
            A[i] += 32;
        else if (A[i] >= 'a' && A[i] <= 122)
            A[i] -= 32;
    }
    for (int j = 0; A[j] != '\0'; j++)
        cout << A[j];
    return 0;
}