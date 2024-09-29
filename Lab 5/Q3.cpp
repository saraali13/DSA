/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

class Node 
{
    int data;
    Node* next;

    public:
        Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}

        friend class LinkedList;
};

class LinkedList 
{
    Node* head;

    Node* reverseHelper(Node* node) 
	{
        if(!node || !node->next) return node;

        Node* reversed = reverseHelper(node->next);
        node->next->next = node;
        node->next = nullptr;

        return reversed;
    }

    public:
        LinkedList() : head(nullptr) {}

        void insertAtFront(int val) 
		{
            head = new Node(val, head);
        }

        void reverse() 
		{
            head = reverseHelper(head);
        }

        void printList() 
		{
            for(Node* curr = head; curr; curr = curr->next) 
			{
                cout << curr->data << " -> ";
            }
            cout << "NULL" << endl;
        }
};

int main() 
{
    LinkedList ll;
    ll.insertAtFront(1);
    ll.insertAtFront(7);
    ll.insertAtFront(13);
    ll.insertAtFront(43);
    ll.insertAtFront(5);

    cout << "Before reversing" << endl;
    ll.printList();
    
    ll.reverse();
    
    cout << endl << "After reversing" << endl;
    ll.printList();

    return 0;
}
