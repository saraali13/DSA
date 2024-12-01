/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class LibraryCatalog 
{
private:
    vector<list<int>> table; // Hash table using separate chaining
    int size;

    int hashCode(int bookID) 
   {
        return bookID % size;
    }

public:
    LibraryCatalog(int tableSize) : size(tableSize)
    {
        table.resize(size);
    }

    void insert(int bookID) 
    {
        int index = hashCode(bookID);
        table[index].push_back(bookID);
    }

    bool search(int bookID) 
      {
        int index = hashCode(bookID);
        for (int id : table[index]) 
        {
            if (id == bookID)
                return true;
        }
        return false;
    }

    void remove(int bookID) 
    {
        int index = hashCode(bookID);
        table[index].remove(bookID);
    }

    void display() 
     {
        for (int i = 0; i < size; i++) 
         {
            cout << "Index " << i << ": ";
            for (int id : table[i])
                cout << id << " -> ";
            cout << "nullptr" << endl;
        }
    }
};

int main() 
{
    LibraryCatalog catalog(10);

    // Insert books
    catalog.insert(101); // Author A
    catalog.insert(102); // Author A
    catalog.insert(103); // Author A
    catalog.insert(201); // Author B
    catalog.insert(202); // Author B
    catalog.insert(301); // Author C
    catalog.insert(302); // Author C
    catalog.insert(303); // Author C
    catalog.insert(304); // Author C

    cout << "Library Catalog after insertion:" << endl;
    catalog.display();

    // Search for books
    cout << "\nSearching for book 102: " << (catalog.search(102) ? "Found" : "Not Found") << endl;
    cout << "Searching for book 303: " << (catalog.search(303) ? "Found" : "Not Found") << endl;
    cout << "Searching for book 401: " << (catalog.search(401) ? "Found" : "Not Found") << endl;

    // Delete books
    catalog.remove(102);
    catalog.remove(303);
    cout << "\nLibrary Catalog after deletion of 102 and 303:" << endl;
    catalog.display();

    return 0;
}

