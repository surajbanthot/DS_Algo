#include<iostream>
using namespace std;

// int fact(int n)
// {
//     if(n==0)
//     return (1);
//     else
//     return fact(n-1)*n;
// }


//iterative

// int c(int n, int r)
// {
//    int t1,t2,t3;
//    t1=fact(n);
//    t2=fact(r);
//    t3=fact(n-r); 
//    return t1/(t2*t3);
// }

//recursive

// int c(int n, int r)
// {
//     int num,den;
//     num=fact(n);
//     den=fact(r)*fact(n-r);
//     return num/den;
    
// }


//pascal's addition


int c(int n, int r)
{
    if(r==0 || n==r)
    return 1;
    else 
    return c(n-1, r-1)+c(n-1,r);
}

int main()
{
    int n, r;
    cout<<"Enter the value's for n and r"<<endl;
    cin>>n>>r;
    int result=c(n,r);
    cout<<result;
    return 0;
}