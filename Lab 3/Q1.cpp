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
        head=x;
     }
     else
     {
        n->next=head;
        head=n;
     }
}

void InsertAtTail(const int x)
{
    Node *n=new Node(x);
    Node *curr=head;
    if (head==NULL)
    {
        head=n;
    }
    else
    {
        while(curr!=NULL)
        {
           curr=curr->next;
        }
        curr->next=n;
        n->next=NULL;
    }

}

void InsertAfterValue(const int vale,const int inseritngValue)
{
  if(head!= NULL)
  {
    Node *n=new Node(inseritngValue);
    Node *currentPTR=head;
    while(currentPTR->data!=value)
    {
      currentPTR=currentPTR->next;
    }
    n->next=currentPTR->next
    currentPTR->next=n;
  }
  else
  {
    cout<<"There os no Node with the given value\n";
  }
}

void InsertBeforeValue(const int vale,const int inseritngValue)
{
  if(head!= NULL)
  {
    Node *n=new Node(inseritngValue);
    Node *currentPTR=head;
    Npde *prev=NULL;
    while(currentPTR!=NULL && currentPTR->data!=value)
    {
        prev=currentPTR;
       currentPTR=currentPTR->next;
    }
    n->next=currentPTR;
    prev->next=n;
  }
  else
  {
    cout<<"There os no Node with the given value\n";
  }
}

void DeleteLast()
{
    if (head!=NULL)
    {
        Node *CurrPTR=head;
        while(CurrPTR->next->next!=NULL)
        {
            CurrPTR=CurrPTR->next;
        }
        Node *temp=CurrPTR->next;
        CurrPTR->next=NULL;
        delete temp;
        temp=NULL;
    }
    else
    {
        cout<<"List is already Empty\n";
    }
}

void DeleteStart()
{
    if (head!=NULL)
    {
        Node *CurrPTR=head;
       head=CurrPTR->next;
       delete CurrPTR;
       CurrPTR=NULL;
    }
    else
    {
        cout<<"List is already Empty\n";
    }
}

void DeleteAt(const int n)
{
    if (head!=NULL)
    {
        Node *CurrPTR=head;
        Node *Prev=NULL;
        while(CurrPTR->next!=n)
        {
            Prev=CurrPTR;
            CurrPTR=CurrPTR->next;
        }
        Prev=CurrPTR->next;
        CurrPTR->next=NULL;
        delete CurrPTR;
        CurrPTR=NULL;
    }
    else
    {
        cout<<"List is already Empty\n";
    }
}
int countlist()
{
    int count=0;
    Node *curr=head;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        while(curr!=NULL)
        {
          count++;
          curr=curr->next;
        }
    }
    return count;
}
};

int main()
{
    SingelyLinkedList* l1=new SingelyLinkedList() ;
    l1.InsertAtFront(4);
    l1.InsertAfterValue(2,6);
    l1.InsertAtTail(37);
    l1.InsertBeforeValue(3,8);
    l1.countlist();
    l1.DeleteStart();
    l1.DeleteLast();
    l1.DeleteAt(4);
}
