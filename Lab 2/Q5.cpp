/*
Name:S. Sara Ali
ID:23K-0070
*/

//here also we're using jagged arrays

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;
    int MaxSeats=5;//will assign mx number of seats to avoid any run time error 
    
    int Row[rows];
    string seatingChart[rows][MaxSeats];

//taking number of seats and names input from user
    for (int i = 0; i < rows; i++) 
	{
	  cout<<"Enter Data for Row "<<i+1<<": "<<endl;
          cout <<"Enter the number of seats: ";
          cin >> Row[i];

        for (int j = 0; j < Row[i]; j++) 
	{
            cout << "Enter the name of person for seat " << j + 1 << ": ";
            cin >> seatingChart[i][j];
        }
    }

//displaying the seating chart
    cout << "\n\n/Seating Chart:\n";
    for (int i = 0; i < rows; i++) 
	{
          cout << "Row " << i + 1 << ": ";
          for (int j = 0; j < Row[i]; j++) 
	{
            cout << seatingChart[i][j] << "| ";
        }
        cout << endl;
    }

    return 0;
}

