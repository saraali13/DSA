/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include<iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int val)
{
    if (low > high) 
	{
        return -1; 
    }

    int mid = low + (high - low) / 2;

    if(arr[mid] == val)
	{
        return mid;
    }
    else if(arr[mid] < val)
	{
        return BinarySearch(arr,mid+1,high,val);
    }
    else
	{
        return BinarySearch(arr,low,mid-1,val);
    }
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    cout<<BinarySearch(arr,0,4,3);
}
