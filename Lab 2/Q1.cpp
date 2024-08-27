/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

int main() 
{
    int* arr[3];  
    int Size[3] = {5, 5, 5};  

    for(int i = 0; i < 3; i++) 
    {
        arr[i] = new int[Size[i]];//array has 3 rows with 5 column for each row
    }

    
    for(int i = 0; i < 3; i++) 
	{
		cout<<"Enter elements for row "<<i+1 <<": ";
		
        for(int j = 0; j < Size[i]; j++) 
		{
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < 3; i++) 
	{
        int* temp = new int[10];//each jagged array size is changed to 10 now
        for(int j = 0; j < Size[i]; j++) 
		{
            temp[j] = arr[i][j];
        }
        delete[] arr[i];  
        arr[i] = temp;    
        Size[i] = 10;// every element for  size array is 10 now
    }

   
    for(int i = 0; i < 3; i++) 
	{
		 cout << "Enter additional element for row " << i + 1 <<": ";
        for(int j = 5; j < Size[i]; j++) 
		{
            cin >> arr[i][j];
        }
    }


    cout << "\nJagged Array Elements:\n";
    for(int i = 0; i < 3; i++) 
	{
        cout << "Row " << i + 1 << ": ";
        for(int j = 0; j < Size[i]; j++) 
		{
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }

   
    for(int i = 0; i < 3; i++) 
	{
        delete[] arr[i];
    }

    return 0;
}
