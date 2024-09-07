/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

class Node 
{
private:
    int data;
    Node* next;
    Node* prev;

public:
    Node() : data(0), next(NULL), prev(NULL) {}
    Node(int val) : data(val), next(NULL), prev(NULL) {}
    friend class DoublyLinkedList; 
};

class DoublyLinkedList 
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertAtEnd(int val) 
    {
        Node* newNode = new Node(val);
        if (tail == NULL) 
        { 
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    //function for sorting the list
    void sortList() 
    {
        if (head == NULL) return;

        bool swapped;
        Node* temp;

        do 
        {
            swapped = false;
            temp = head;

            while (temp->next != NULL) 
            {
                if (temp->data > temp->next->data) 
                {
                    // Swap data between adjacent nodes
                    int tempData = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tempData;

                    swapped = true;
                }
                temp = temp->next;
            }
        } 
        while (swapped);
    }

//function for removing the duplicated elements of the list
    void removeDuplicates() 
    {
        if (head == NULL) return;

        Node* temp = head;

        while (temp->next != NULL) 
        {
            if (temp->data == temp->next->data) 
            {
                Node* duplicateNode = temp->next;
                temp->next = duplicateNode->next;
                if (duplicateNode->next != NULL) 
                {
                    duplicateNode->next->prev = temp;
                }
                delete duplicateNode;
            } 
            else 
            {
                temp = temp->next;
            }
        }
    }

    void printList() 
    {
        Node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    DoublyLinkedList *dll=new DoublyLinkedList();

    dll->insertAtEnd(11);
    dll->insertAtEnd(2);
    dll->insertAtEnd(3);
    dll->insertAtEnd(11);
    dll->insertAtEnd(4);
    dll->insertAtEnd(53);
    
    dll->printList();
    dll->sortList();
    cout<<"\nSorted list:\n";
    dll->printList();
    dll->removeDuplicates();
    cout<<"\nFinal List:\n";
    dll->printList();
}
