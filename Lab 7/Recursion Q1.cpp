/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;


bool isSafe(int maze[5][5], int x, int y, int n) 
{
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

void findPaths(int maze[5][5], int x, int y, int n, string path) 
{
    if (x == n - 1 && y == n - 1) 
	{
        cout << path << endl;
        return;
    }

    maze[x][y] = 0;

    if (isSafe(maze, x + 1, y, n)) //down
	{
        findPaths(maze, x + 1, y, n, path + "D");
    }
    
    if (isSafe(maze, x - 1, y, n))//up 
	{
        findPaths(maze, x - 1, y, n, path + "U");
    }
    
    if (isSafe(maze, x, y + 1, n))//right 
	{
        findPaths(maze, x, y + 1, n, path + "R");
    }

    if (isSafe(maze, x, y - 1, n))//left 
	{
        findPaths(maze, x, y - 1, n, path + "L");
    }

    maze[x][y] = 1;
}

int main() 
{
    int maze[5][5] = 
	{ 
        {1, 0, 0, 0, 0}, 
        {1, 1, 0, 1, 1}, 
        {0, 1, 0, 1, 0}, 
        {1, 1, 1, 1, 1}, 
        {0, 0, 0, 1, 1} 
    };
    int n = 5;

    cout << "Paths:\n";
    findPaths(maze, 0, 0, n, "");
    cout << endl;

    return 0;
}
