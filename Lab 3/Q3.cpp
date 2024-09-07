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
    Node *next;

public:
    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
    friend class SingelyLinkedList;
};

class SingelyLinkedList
{
private:
    Node *head;

public:
    SingelyLinkedList() : head(NULL) {}
    SingelyLinkedList(Node* n) : head(n) {}

    void InsertAtFront(const int x)
    {
        Node *n = new Node(x);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }

    // Function to segregate even and odd numbers
    void SegregateEvenOdd()
    {
        if (head == NULL)
        {
            return;
        }

        Node *evenHead = NULL, *evenTail = NULL;
        Node *oddHead = NULL, *oddTail = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            int value = curr->data;

            if (value % 2 == 0)
            {
                if (evenHead == NULL)
                {
                    evenHead = curr;
                    evenTail = evenHead;
                }
                else
                {
                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }
            }
  
            else
            {
                if (oddHead == NULL)
                {
                    oddHead = curr;
                    oddTail = oddHead;
                }
                else
                {
                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }
            }
            curr = curr->next;
        }
\
        if (evenHead == NULL || oddHead == NULL)
        {
            return;
        }

        evenTail->next = oddHead;
        oddTail->next = NULL;
        head = evenHead;
    }

    void PrintList()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    SingelyLinkedList *l1 = new SingelyLinkedList();

    l1->InsertAtFront(18);
    l1->InsertAtFront(12);
    l1->InsertAtFront(7);
    l1->InsertAtFront(11);
    l1->InsertAtFront(21);
    l1->InsertAtFront(68);
    l1->InsertAtFront(77);

    cout << "Before Segregation: ";
    l1->PrintList();

    l1->SegregateEvenOdd();
    cout << "After Segregation: ";
    l1->PrintList();

    return 0;
}
