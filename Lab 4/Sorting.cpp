/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

//bubble sort algo
void BubbleSort(int arr[], int n)
{
    bool swaped=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                 swap(arr[j],arr[j+1]);
                 swaped=true;
            }
           
        }
        if(swaped==false)
        {
            break;
        }
    }
}

//selection sort algo
void SelectionSort(int arr[],int n)
{
    
  for(int i=0;i<n;i++)
  {
    int min_idx=i;
    for(int j=i+1;j<n;j++)
    {
        if (arr[j]<arr[min_idx])
        {
            min_idx=j;
        }
    }
    if(min_idx!=i)
    {
        swap(arr[i],arr[min_idx]);
    }

  }
}

//insertion sort algo
void InsertionSort(int arr[],int n)
{
   for (int i=1;i<n;i++)
   {
      int key=arr[i];
      int j;
      for (j=i-1;j>=0;j--)
      {
        if(arr[j]>key)
        {
         swap(arr[j],arr[j+1]);
        }
        else
        break;
      }
    arr[j+1]=key;
   }
}

//shell sort algo
void shellSort(int arr[],int n)
{
    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            int key=arr[i];
            int j;
            for (j=i;j>=gap;j-=gap)
             {
               if(arr[j-gap]>key)
                {
                  swap(arr[j],arr[j-gap]);
                }
               else
                break;
             }
             arr[j]=key;

        }
    }
}

//comb sort algo
void CombSort(int arr[],int n)
{
    int gap=n;
    float ShrinkFactor=1.3;
    bool sorted=true;
    while(sorted==true|| gap!=1)
    {
        gap=gap/ShrinkFactor;
        sorted=false;
        
        for(int i=0;i<n-gap;i++)
        {
           if(arr[i]>arr[i+gap])
           {
           swap(arr[i],arr[i+gap]);
           sorted=true;
           }
        }
    }

}

int main()
{
	//example for Bubble sort
   int arr1[4]={11,23,4,8};
   BubbleSort(arr1,4);
   for(int i=0;i<4;i++)
   {
     cout<<arr1[i]<<", ";
   }
   cout<<endl;
   
   //example for selection sort
   int arr2[5]={21,3,56,7,1};
   SelectionSort(arr2,5);
      for(int i=0;i<5;i++)
   {
     cout<<arr2[i]<<", ";
   }
      cout<<endl;
   
   //example for insertion sort
   int arr3[4]={2,5,7,1};
   InsertionSort(arr3,4);
      for(int i=0;i<4;i++)
   {
     cout<<arr3[i]<<", ";
   }
   cout<<endl;

    //example for shell sort
   int arr4[5]={27,5,7,31,3};
   shellSort(arr4,5);
      for(int i=0;i<5;i++)
   {
     cout<<arr4[i]<<", ";
   }
    cout<<endl;

    //example for comb sort
   int arr5[5]={2,9,7,1,11};
   CombSort(arr5,5);
      for(int i=0;i<5;i++)
   {
     cout<<arr5[i]<<", ";
   }

   return 0;
}
