/*
Name:S.Sara ALi
ID:23K-0070
*/

#include <iostream>
#include <string>
using namespace std;

class Runner 
{
public:
    string name;
    int finishTime; 

    Runner() : name(""), finishTime(0) 
	{}
    Runner(string n, int time) : name(n), finishTime(time) 
	{}
};

void merge(Runner arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner* leftArray = new Runner[n1];
    Runner* rightArray = new Runner[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left;

    while (i < n1 && j < n2) 
	{
        if (leftArray[i].finishTime <= rightArray[j].finishTime) 
		{
            arr[k] = leftArray[i];
            i++;
        } 
		else 
		{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
	{
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) 
	{
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(Runner arr[], int left, int right) 
{
    if (left < right) 
	{
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    
}

int main() 
{
    const int numRunners = 10;
    Runner runners[numRunners];

    for (int i = 0; i < numRunners; i++) 
	{
        cout << "Enter name of participant " << (i + 1) << ": ";
        cin >> runners[i].name;
        cout << "Enter finish time (in seconds) for " << runners[i].name << ": ";
        cin >> runners[i].finishTime;
    }

    mergeSort(runners, 0, numRunners - 1);

    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5; i++) 
	{
        cout << runners[i].name << " :" << runners[i].finishTime << " seconds\n";
    }

    return 0;
}
