/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <vector>
using namespace std;

#define EMPTY -1

class FitnessClub 
{
private:
    vector<int> table;
    int size;

    int hashCode(int memberID) 
    {
        return memberID % size;
    }

public:
    FitnessClub(int tableSize) : size(tableSize) 
    {
        table.resize(size, EMPTY);
    }

    void insert(int memberID) 
   {
        int index = hashCode(memberID);
        while (table[index] != EMPTY) \
        {
            index = (index + 1) % size;
        }
        table[index] = memberID;
    }

    bool search(int memberID) 
{
        int index = hashCode(memberID);
        for (int i = 0; i < size; i++) 
        {
            if (table[index] == memberID)
                return true;
            if (table[index] == EMPTY)
                return false;
            index = (index + 1) % size;
        }
        return false;
    }

    void remove(int memberID) 
{
        int index = hashCode(memberID);
        for (int i = 0; i < size; i++) 
        {
            if (table[index] == memberID) 
            {
                table[index] = EMPTY;
                return;
            }
            if (table[index] == EMPTY)
                return;
            index = (index + 1) % size;
        }
    }

    void display() 
{
        for (int i = 0; i < size; i++) 
        {
            if (table[i] == EMPTY)
                cout << i << ": ~~" << endl;
            else
                cout << i << ": " << table[i] << endl;
        }
    }
};

int main() 
{
    FitnessClub club(7);

    // Insert members
    club.insert(10);
    club.insert(20);
    club.insert(30);
    club.insert(40);
    club.insert(50);
    club.insert(60);

    cout << "Fitness Club after insertion:" << endl;
    club.display();

    // Search for members
    cout << "\nSearching for 30: " << (club.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for 50: " << (club.search(50) ? "Found" : "Not Found") << endl;
    cout << "Searching for 70: " << (club.search(70) ? "Found" : "Not Found") << endl;

    // Delete members
    club.remove(20);
    club.remove(40);

    // Insert new members
    club.insert(70);
    club.insert(80);

    cout << "\nFitness Club after deletion and additional insertion:" << endl;
    club.display();

    return 0;
}
