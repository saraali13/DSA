/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include<iostream>
using namespace std;

int factNoTail(int n)
{
    if(n == 0 || n == 1)
	{
        return n;
    }

    int fact = n * factNoTail(n-1);
    return fact;
}

int factTail(int n,int x = 1)
{
    if(n == 0 || n==1)
	{
        return x;
    }

    return factTail(n-1,x*n);
}

int main()
{
    int num = 5;
    int a = factNoTail(num);
    int b = factTail(num);
    cout<<a<<endl;
    cout<<b<<endl;
}
