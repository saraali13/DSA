/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

int fib(int num, int a = 0, int b = 1, int count = 1) 
{
    if (num == 0) 
	     return 0; 
    if (num == 1) 
	     return a; 
    if (count == num) 
	{
        return a;
    }
    return fib(num, a + b, a, count + 1); 
}

int main() {
 
 cout<<fib(7);
    return 0;
}
