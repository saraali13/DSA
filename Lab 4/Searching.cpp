/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

int LinearSearch(int arr[],int n,int target)
{
    bool found=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        {
            cout<<"Match found\n";
            found=true;
            return i;
        }
    }
    if(!found)
    {
        cout<<"match not found\n";
        return -1;
    }

}

int main ()
{
    int arr1[5]={11,23,16,4,8};
    int x=LinearSearch(arr1,5,16);
    cout<<"The desired number is at the index: "<<x<<endl;
    return 0;
}
