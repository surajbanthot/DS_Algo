#include <iostream>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power(m * m, n / 2);
    else
    {
        return m * power(m * m, (n - 1) / 2);
    }

    // return power(m,n-1)*m;
}

int main()
{
    int m, n;
    int sum = 1;
    cout << "Enter the value for m and it's exponent n\n";
    cin >> m >> n;
    int final_val = power(m, n);
    // for(int i=0;i<n;i++)
    // sum=sum*m;

    cout << sum;
    return 0;
}
