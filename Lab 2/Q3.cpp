/*
Name: S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class Friendship 
{
private:
    bool friends[5][5];

public:
    Friendship() 
	{
        bool temp[5][5] = 
	//we can't initiallize a matrix with bool values directly so that why we're declaing a temp variable then then will copy it's values to our acual matrix
		{
            {false, true, false, true, true},
            {true, false, true, false, true},
            {false, true, false, false, false},
            {true, false, false, false, true},
            {true, true, false, true, false}
        };
        

        for (int i = 0; i < 5; i++) 
		{
            for (int j = 0; j < 5; j++) 
			{
                friends[i][j] = temp[i][j];
            }
        }
    }//

    void hasCommonFriend(int p1, int p2) 
	{
        for (int i = 0; i < 5; i++) 
		{
            if (friends[p1][i] && friends[p2][i]) 
			{
                cout<<"Person 1 and 2 have common friends\n";
                return;
            }
        }
         cout<<"Person 1 and 2 doesnot have any common friends\n";
    }//
};

int main() 
{
    Friendship fr1;
    Friendship fr2;
    int pr1 = 0, pr2 = 4;
    int pr3 = 1, pr4 =2;

    fr1.hasCommonFriend(pr1, pr2);
    fr2.hasCommonFriend(pr3, pr4);
    
    return 0;
}
