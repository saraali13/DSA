/*
Name:S.Sara ALi
ID:23K-0070
*/

#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H

#include <iostream>
using namespace std;

void matrix_multiply(int** m1, int** m2, int** result, int r1, int c1, int c2) 
{
    
    for (int i = 0; i < r1; i++) 
	{
        for (int j = 0; j < c2; j++) 
		{
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) 
	{
        for (int j = 0; j < c2; j++) 
		{
            for (int k = 0; k < c1; k++) 
			{
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

#endif // MATRIX_MULTIPLY_H


int main() 
{
    int row1 = 2, col1 = 2, row2 = 2, col2 = 2;

    int** matrix1 = new int*[row1];
    for(int i = 0; i < row1; ++i)
    {
        matrix1[i] = new int[col1];
    }

    int** matrix2 = new int*[row2];
    for(int i = 0; i < row2; ++i)
    {
		matrix2[i] = new int[col2];
    }

    int** result = new int*[row1];
    for(int i = 0; i < row1; ++i)
    {
	    result[i] = new int[col2];
    }

    cout << "Enter elements for matrix1:\n";
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col1; j++)
        {
		    cin >> matrix1[i][j];
	    }
	}

    cout << "Enter elements for matrix2 (3x2):\n";
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < col2; j++)
        {
	        cin >> matrix2[i][j];
	    }
	}

    // Multiply the matrices
    matrix_multiply(matrix1, matrix2, result, row1, col1, col2);

    cout << "\nResultant Matrix:\n";
    for(int i = 0; i < row1; i++) 
	{
        for(int j = 0; j < col2; j++) 
		{
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < row1; ++i) delete[] matrix1[i];
    delete[] matrix1;

    for(int i = 0; i < row2; ++i) delete[] matrix2[i];
    delete[] matrix2;

    for(int i = 0; i < row1; ++i) delete[] result[i];
    delete[] result;

    return 0;
}
