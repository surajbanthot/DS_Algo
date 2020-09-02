//tower of hanoi is a inorder traversal

#include <iostream>
using namespace std;

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "From " << A << " to " << C << "\n";
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(7, 1, 2, 3);

    return 0;
}