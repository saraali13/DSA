/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

int getMax(int arr[], int n) 
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) 
	{
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void countingSort(int arr[], int n, int exp, bool ascending = true) 
{
    int output[n]; 
    int count[10] = {0};

    for (int i = 0; i < n; i++) 
	{
        count[(arr[i] / exp) % 10]++;
    }

    if (ascending) 
	{
        for (int i = 1; i < 10; i++) 
		{
            count[i] += count[i - 1];
        }
    } 
	else 
	{
        for (int i = 8; i >= 0; i--) 
		{
            count[i] += count[i + 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) 
	{
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    for (int i = 0; i < n; i++) 
	{
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n, bool ascending = true) 
{
    int maxVal = getMax(arr, n);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) 
	{
        countingSort(arr, n, exp, ascending);
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main() 
{
    int arr[] = {17, 4, 5, 9, 8, 2, 20, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    radixSort(arr, n, true);
    cout << "\nSorted array in ascending order:\n";
    printArray(arr, n);

    radixSort(arr, n, false);
    cout << "\nSorted array in descending order:\n";
    printArray(arr, n);

    return 0;
}
