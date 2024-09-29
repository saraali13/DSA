/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int target) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == target) 
        {
            cout << "Match found using Linear Search\n";
            return i;
        }
    }
    cout << "Match not found using Linear Search\n";
    return -1;
}

int BinarySearch(int arr[], int left, int right, int target) 
{
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            cout << "Match found using Binary Search\n";
            return mid;
        }
        if (arr[mid] < target) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    cout << "Match not found using Binary Search\n";
    return -1;
}

int InterpolationSearch(int arr[], int n, int target) 
{
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) 
    {
        if (low == high) 
        {
            if (arr[low] == target) 
            {
                cout << "Match found using Interpolation Search\n";
                return low;
            }
            break;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));

        if (arr[pos] == target) 
        {
            cout << "Match found using Interpolation Search\n";
            return pos;
        }

        if (arr[pos] < target) 
        {
            low = pos + 1;
        } 
        else 
        {
            high = pos - 1;
        }
    }

    cout << "Match not found using Interpolation Search\n";
    return -1;
}

int main() {
    int arr1[5] = {4, 8, 11, 16, 23};  
    int x;
    
    x = LinearSearch(arr1, 5, 16);
    cout << "The desired number is at index: " << x << endl;

    
    x = BinarySearch(arr1, 0, 4, 16);
    cout << "The desired number is at index: " << x << endl;


    x = InterpolationSearch(arr1, 5, 16);
    cout << "The desired number is at index: " << x << endl;

    return 0;
}
