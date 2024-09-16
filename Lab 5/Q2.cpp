/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include<iostream>
using namespace std;

int factNoTail(int num)
{
    if(num == 1 || num == 2)
	{
        return num;
    }

    int a = num * factNoTail(num-1);
    return a;
}

int factTail(int num,int temp = 1)
{
    if(num == 0)
	{
        return temp;
    }

    return factTail(num-1,temp*num);
}


int main()
{
    int num = 5;
    int a = factNoTail(num);
    int b = factTail(num);
    cout<<a<<endl;
    cout<<b<<endl;
}
