#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}

int main()
{

    int n;
    cout << "Enter N to find the sum of \n";
    cin >> n;

    int total= n*(n+1)/2;
    // int total = sum(n);
    cout << total << "\n";
}


// sum=n*(n+1)/2; formula as sum of natural numbers will be 1+2+3+4+5=n*
