/*
Name:S. Sara ALi
ID:23K-0070
*/
//We'll use jagged arrays coz there are 4 departs and each deprat has its own courses
#include <iostream>
using namespace std;

int main() 
{
	//no of core courses for each depart
    int SE = 3;
    int AI = 4;
    int CS= 2;
    int DS= 1;

    float* GPAs[4];

//assinging random gpa values 
    GPAs[0] = new float[SE] {2.91, 3.56, 3.86}; // SE GPAs
    GPAs[1] = new float[AI] {3.56, 3.89, 2.99, 3.74}; // AI GPAs
    GPAs[2] = new float[CS] {3.14, 3.36}; // CS GPAs
    GPAs[3] = new float[DS] {3.79}; // DS GPAs

//printing those values of gpa in jagged array for each depart
    cout << "GPA for Software Engineering (SE) Department: \n";
    for (int i = 0; i < SE; i++)
    {
        cout << GPAs[0][i] << ", ";
    }
    cout << endl<< endl;

    cout << "GPA for Artificial Intelligence (AI) Department: \n";
    for (int i = 0; i < AI; i++)
    {
        cout << GPAs[1][i] << ", ";
    }
    cout << endl<< endl;

    cout << "GPA for Computer Science (CS) Department: \n";
    for (int i = 0; i < CS; i++)
    {
        cout << GPAs[2][i] << ", ";
    }
    cout << endl<< endl;

    cout << "GPA for Data Science (DS) Department: \n";
    for (int i = 0; i < DS; i++)
    {
        cout << GPAs[3][i] << ", ";
    }
    cout << endl<< endl;

    delete[] GPAs[0];
    delete[] GPAs[1];
    delete[] GPAs[2];
    delete[] GPAs[3];

    return 0;
}
