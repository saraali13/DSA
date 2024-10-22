/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

const int MAX = 100;
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

int exploreForest(char field[MAX][MAX], int x, int y, int rows, int cols) 
{
    if (x < 0 || x >= rows || y < 0 || y >= cols || field[x][y] != 'T') 
	{
        return 0;
    }

    field[x][y] = 'W';

    int count = 1;

    for (int i = 0; i < 4; i++) 
	{
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        count += exploreForest(field, newX, newY, rows, cols);
    }

    return count; 
}

int findLargestForest(char field[MAX][MAX], int rows, int cols) 
{
    int largestForest = 0;

    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            if (field[i][j] == 'T') 
			{
                int forestSize = exploreForest(field, i, j, rows, cols);
                if (forestSize > largestForest) 
				{
                    largestForest = forestSize;
                }
            }
        }
    }

    return largestForest;
}

int main() 
{
    int rows, cols;
    char field[MAX][MAX];

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter the field (W for water, T for tree): " << endl;
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            cin >> field[i][j];
        }
    }

    int largestForest = findLargestForest(field, rows, cols);

    cout << "The size of the largest forest is: " << largestForest << endl;

    return 0;
}
