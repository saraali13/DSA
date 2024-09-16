/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

void Arr_BubbleSort(int arr[], int size,int i, int j)
{
    bool swaped=false;
    if(i >= size-1)
	{
        return;
    }
    
    if(j == size)
	{
        i += 1;
        j = i;
    }
    
    if(arr[i] > arr[j])
	
	{
       swap(arr[i],arr[j]);
    }
    Arr_BubbleSort(arr,size,i,j+1);
    
}


int main()
{
	int arr1[5]={9,34,56,8,1};
	Arr_BubbleSort(arr1,5,0,0);
	
	for(int i=0;i<5;i++)
	{
		cout<<arr1[i]<<", ";
	}
	cout<<"NULL\n";
	
	return 0;
	
}
