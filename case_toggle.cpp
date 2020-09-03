#include <iostream>
using namespace std;

int main()
{
    char A[] = "WELCOME";
    
    for (int i = 0; A[i]!='\0'; i++)
    {
        A[i] = A[i] + 32; //upper to lower case +32 , to lowercase -32
    }
    for (int j = 0; A[j]!='\0'; j++)
        cout << A[j];
    return 0;
}