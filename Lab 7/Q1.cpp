/*
Name:S.Sara ALi
ID:23K-0070
*/

#include <iostream>
using namespace std;

class Node 
{
private:
    int data;
    Node* next;

public:
    Node() : data(0), next(NULL) 
	{}
    Node(int data) : data(data), next(NULL) 
	{}

    friend class SinglyLinkedList;
};

class SinglyLinkedList 
{
private:
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    void insertAtEnd(int value) 
	{
        Node* newNode = new Node(value);
        if (head == NULL) 
		{
            head = newNode;
        } 
		else 
		{
            Node* temp = head;
            while (temp->next != NULL) 
			{
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void swap(Node* a, Node* b) 
	{
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node* partition(Node* low, Node* high) 
	{
        int pivot = high->data;
        Node* i = low;

        for (Node* j = low; j != high; j = j->next) 
		{
            if (j->data < pivot) 
			{
                swap(i, j);
                i = i->next;
            }
        }
        swap(i, high);
        return i;
    }

    void quickSort(Node* low, Node* high) 
	{
        if (low != NULL && high != NULL && low != high && low != high->next) {
            Node* pivot = partition(low, high);

            Node* temp = low;
            while (temp != NULL && temp->next != pivot) 
			{
                temp = temp->next;
            }
            if (temp != NULL) 
			{
                quickSort(low, temp);
            }
            quickSort(pivot->next, high);
        }
    }

    Node* getLastNode() 
	{
        Node* temp = head;
        while (temp != NULL && temp->next != NULL) 
		{
            temp = temp->next;
        }
        return temp;
    }

    void quickSortList() 
	{
        Node* tail = getLastNode();
        quickSort(head, tail);
    }

    void printList() 
	{
        Node* curr = head;
        while (curr != NULL) 
		{
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

int main() 
{
    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    list.insertAtEnd(1);
    list.insertAtEnd(5);
    list.insertAtEnd(3);

    cout << "Original List: ";
    list.printList();
    list.quickSortList();
    cout << "Sorted List: ";
    list.printList();

    return 0;
}

