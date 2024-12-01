/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <vector>
using namespace std;

class UniversityPortal 
{
private:
    vector<int> table;
    int size;
    int currentSize;

    int hashCode(int studentID) 
    {
        return studentID % size;
    }

    void resize() 
   {
        int oldSize = size;
        size *= 2;
        vector<int> newTable(size, -1);

        for (int id : table) 
        {
            if (id != -1) 
            {
                int index = id % size;
                while (newTable[index] != -1) {
                    index = (index + 1) % size;
                }
                newTable[index] = id;
            }
        }
        table = newTable;
    }

public:
    UniversityPortal(int tableSize) : size(tableSize), currentSize(0) 
    {
        table.resize(size, -1);
    }

    void insert(int studentID) 
    {
        if ((float)currentSize / size > 0.75) 
        {
            resize();
        }

        int index = hashCode(studentID);
        while (table[index] != -1) 
        {
            index = (index + 1) % size;
        }
        table[index] = studentID;
        currentSize++;
    }

    bool search(int studentID) 
    {
        int index = hashCode(studentID);
        for (int i = 0; i < size; i++)
          {
            if (table[index] == studentID)
                return true;
            if (table[index] == -1)
                return false;
            index = (index + 1) % size;
        }
        return false;
    }

    void display() 
     {
        for (int i = 0; i < size; i++) 
        {
            if (table[i] == -1)
                cout << i << ": ~~" << endl;
            else
                cout << i << ": " << table[i] << endl;
        }
    }
};

int main() 
{
    UniversityPortal portal(7);

    // Insert student IDs
    portal.insert(12);
    portal.insert(22);
    portal.insert(32);
    portal.insert(42);
    portal.insert(52);
    portal.insert(62);

    cout << "University Portal after insertion:" << endl;
    portal.display();

    // Insert additional IDs to trigger resize
    portal.insert(72);
    portal.insert(82);

    cout << "\nUniversity Portal after resizing:" << endl;
    portal.display();

    return 0;
}
