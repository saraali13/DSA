/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <vector>
using namespace std;

#define TABLE_SIZE 11

// Hash table to store account numbers
vector<int> hashTable(TABLE_SIZE, -1); // -1 indicates an empty slot

// Primary hash function: ID % table_size
int primaryHash(int id) 
{
    return id % TABLE_SIZE;
}

// Secondary hash function: 7 - (ID % 7)
int secondaryHash(int id) 
{
    return 7 - (id % 7);
}

// Function to insert an account number into the hash table
void insert(int id) 
{
    int index = primaryHash(id);
    int step = secondaryHash(id);

    // Use double hashing to find an empty slot
    while (hashTable[index] != -1) 
    {
        index = (index + step) % TABLE_SIZE;
    }
    hashTable[index] = id;
}

// Function to search for an account number in the hash table
int search(int id) 
{
    int index = primaryHash(id);
    int step = secondaryHash(id);

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        if (hashTable[index] == -1) 
        {
            return -1; // Not found
        }
        if (hashTable[index] == id) 
        {
            return index; // Found
        }
        index = (index + step) % TABLE_SIZE;
    }
    return -1; // Not found
}

// Function to delete an account number from the hash table
void deleteAccount(int id) 
{
    int index = search(id);
    if (index != -1) 
    {
        hashTable[index] = -2; // Mark as deleted
    }
}

// Function to display the hash table
void display() 
{
    cout << "Hash Table: ";
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        if (hashTable[i] == -1) 
        {
            cout << " [ ] ";
        } 
        else if (hashTable[i] == -2) 
        {
            cout << " [X] "; // X indicates a deleted slot
        } 
        else 
        {
            cout << " [" << hashTable[i] << "] ";
        }
    }
    cout << endl;
}

int main() 
{
    // Insert account numbers
    cout << "Inserting account numbers...\n";
    insert(101);
    insert(111);
    insert(121);
    insert(131);
    insert(141);
    insert(151);
    display();

    // Search for account numbers
    cout << "\nSearching for account numbers...\n";
    vector<int> searchIDs = {111, 141, 161};
    for (int id : searchIDs) 
    {
        int result = search(id);
        if (result != -1) 
        {
            cout << "Account number " << id << " found at index " << result << endl;
        } 
        else 
        {
            cout << "Account number " << id << " not found.\n";
        }
    }

    // Delete account numbers
    cout << "\nDeleting account numbers 111 and 131...\n";
    deleteAccount(111);
    deleteAccount(131);
    display();

    // Insert new account numbers
    cout << "\nInserting account numbers 161 and 171...\n";
    insert(161);
    insert(171);
    display();

    return 0;
}
