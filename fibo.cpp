#include <iostream>
using namespace std;

//iterative method

// int fibo(int n)
// {
//     int t0=0,t1=1,s,i;
//     if(n<=1)return n;
//     for(i=2;i<=n;i++)
//     {
//         s=t0+t1;
//         t0=t1;

//         t1=s;
//     }
//     return s;
// }

//recursive, excessive recursion

// int fibo(int n)
// {
//     if(n<=1)
//     return n;
//     return fibo(n-2)+fibo(n-1);
// }

int f[10];

//memoization

int fib(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
            f[n - 2] = fib(n - 2);
        if (f[n - 1] == -1)
            f[n - 1] = fib(n - 1);
        return f[n - 2] + f[n - 1];
    }
}

int main()
{
    int n, i;
    for (i = 0; i < 10; i++)
        f[i] = -1;
    cout << "Enter the n value for the Fibonacci series\n";
    cin >> n;
    int result = fib(n);
    cout << "Fibonacci of " << n << " " << result;
    return 0;
}