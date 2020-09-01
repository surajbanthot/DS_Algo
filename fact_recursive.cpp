#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0)
    return (1);
    else
    return fact(n-1)*n;
}

int main()
{
    int n;
    cout<<"Enter the Number to find the Factorial of\n";
    cin>>n;
    int sum=fact(n);
    cout<<"Factorial of n is "<<sum<<"\n";
    return 0;
}

// Time complexity of Factorial is O(n)
