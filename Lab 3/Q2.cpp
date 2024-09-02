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
Node *next;

public:
Node():data(0),next(NULL)
{}
Node(int data):data(data),next(NULL)
{}
friend class SingelyLinkedList;

};

class SingelyLinkedList
{
private:
Node *head;

public:
SingelyLinkedList():head(NULL){}
SingelyLinkedList(Node* n):head(n){}

void InsertAtFront(const int x)
{
     Node *n= new Node(x);
     if (head==NULL)
     {
        head=n;
     }
     else
     {
        n->next=head;
        head=n;
     }
}

Node *reverse()
{
    if (head==NULL)
    {
        cout<<"List is empty,Can't reverse\n";
    }
    else
    {
        Node *curr=head;
        Node *Next=NULL;
        Node *prev=NULL;
        while(curr!=NULL)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        head=prev;
        return prev;
    }
}

void PrintList()
{
    Node * curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<", ";
        curr=curr->next;
    }
    cout<<"NULL\n";
}


};

int main()
{
    SingelyLinkedList* l1=new SingelyLinkedList() ;
    l1->InsertAtFront(4);
    l1->InsertAtFront(9);
    l1->InsertAtFront(7);
    l1->PrintList();
    l1->reverse();
    l1->PrintList();
}
