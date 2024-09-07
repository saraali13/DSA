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

    void InsertAtTail(const int x)
    {
        Node *n = new Node(x);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *curr = head;
            // Traverse to the end of the list
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = n;  // Set the next of the last node to the new node
        }
    }

    void InsertAfterValue(const int value, const int insertingValue)
    {
        if (head != NULL)
        {
            Node *n = new Node(insertingValue);
            Node *currentPTR = head;
            while (currentPTR != NULL && currentPTR->data != value)
            {
                currentPTR = currentPTR->next;
            }
            if (currentPTR == NULL)
            {
                cout << "No node found with value " << value << endl;
            }
            else
            {
                n->next = currentPTR->next;
                currentPTR->next = n;
            }
        }
        else
        {
            cout << "The list is empty. Cannot insert after value." << endl;
        }
    }

    void InsertBeforeValue(const int value, const int insertingValue)
    {
        if (head != NULL)
        {
            Node *n = new Node(insertingValue);
            if (head->data == value)  // If the value is at the head
            {
                n->next = head;
                head = n;
            }
            else
            {
                Node *currentPTR = head;
                Node *prev = NULL;
                while (currentPTR != NULL && currentPTR->data != value)
                {
                    prev = currentPTR;
                    currentPTR = currentPTR->next;
                }
                if (currentPTR == NULL)
                {
                    cout << "No node found with value " << value << endl;
                }
                else
                {
                    n->next = currentPTR;
                    prev->next = n;
                }
            }
        }
        else
        {
            cout << "The list is empty. Cannot insert before value." << endl;
        }
    }

    void DeleteLast()
    {
        if (head != NULL)
        {
            if (head->next == NULL)  // If only one node exists
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node *currPTR = head;
                while (currPTR->next->next != NULL)
                {
                    currPTR = currPTR->next;
                }
                Node *temp = currPTR->next;
                currPTR->next = NULL;
                delete temp;
            }
        }
        else
        {
            cout << "List is already empty.\n";
        }
    }

    void DeleteStart()
    {
        if (head != NULL)
        {
            Node *currPTR = head;
            head = currPTR->next;
            delete currPTR;
        }
        else
        {
            cout << "List is already empty.\n";
        }
    }

    void DeleteAt(const int n)
    {
        if (head != NULL)
        {
            if (head->data == n)  // If the node to delete is the head
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                Node *currPTR = head;
                Node *prev = NULL;
                while (currPTR != NULL && currPTR->data != n)
                {
                    prev = currPTR;
                    currPTR = currPTR->next;
                }
                if (currPTR == NULL)
                {
                    cout << "No node found with value " << n << endl;
                }
                else
                {
                    prev->next = currPTR->next;
                    delete currPTR;
                }
            }
        }
        else
        {
            cout << "List is already empty.\n";
        }
    }

    int countList()
    {
        int count = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void PrintList()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    SingelyLinkedList *l1 = new SingelyLinkedList();
    l1->InsertAtFront(4);
    l1->InsertAtTail(6);
    l1->InsertAtTail(37);
    l1->InsertAfterValue(6, 8);
    l1->InsertBeforeValue(4, 3);
    l1->PrintList();
    int num = l1->countList();
    cout << "Number of elements in the list: " << num << endl;

    l1->DeleteStart();
    l1->DeleteLast();
    l1->DeleteAt(6);
    l1->DeleteAt(7);

    cout << "Final List: ";
    l1->PrintList();

    return 0;
}
