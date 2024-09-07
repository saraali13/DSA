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

    void insertAtFront(int val) 
    {
        Node* newNode = new Node(val);
        if (head == NULL) 
        { 
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAfterValue(int val, int insertingVal) 
    {
        Node* temp = head;
        while (temp != NULL && temp->data != val) 
        {
            temp = temp->next;
        }

        if (temp == NULL) 
        {
            cout << "No node found with value " << val << endl;
            return;
        }

        Node* newNode = new Node(insertingVal);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) 
        {
            temp->next->prev = newNode;
        } 
        else 
        {
            tail = newNode;  
        }
        temp->next = newNode;
    }

    void insertBeforeValue(int val, int insertingVal) 
    {
        Node* temp = head;
        while (temp != NULL && temp->data != val) 
        {
            temp = temp->next;
        }

        if (temp == NULL) 
        {
            cout << "No node found with value " << val << endl;
            return;
        }

        Node* newNode = new Node(insertingVal);
        newNode->prev = temp->prev;
        newNode->next = temp;

        if (temp->prev != NULL) 
        {
            temp->prev->next = newNode;
        } 
        else 
        {
            head = newNode;  
        }
        temp->prev = newNode;
    }

    void deleteFromHead() 
    {
        if (head == NULL) 
        {
            cout << "List is empty\n";
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; 
        }

        delete temp;
    }

    void deleteFromEnd() 
    {
        if (tail == NULL) 
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) 
        {
            tail->next = NULL;
        } 
        else 
        {
            head = NULL; 
        }

        delete temp;
    }

    void deleteNodeWithValue(int val) 
    {
        Node* temp = head;
        while (temp != NULL && temp->data != val) 
        {
            temp = temp->next;
        }

        if (temp == NULL) 
        {
           cout << "No node found with value " << val << endl;
           return;
        }

        if (temp->prev != NULL) 
        {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;  
        }

        if (temp->next != NULL) 
        {
            temp->next->prev = temp->prev;
        } 
        else 
        {
            tail = temp->prev;  
        }

        delete temp;
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
    dll->insertAtFront(5);
    dll->insertAfterValue(3, 20);
    dll->insertBeforeValue(1, 20);
    dll->printList();

    dll->deleteFromHead();
    dll->deleteFromEnd();
    dll->deleteNodeWithValue(15);
    cout << "Final list: \n";
    dll->printList();

    return 0;
}
