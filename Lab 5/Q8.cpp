/*
Name: S. Sara Ali
ID: 23K-0070
*/

//Stack using linked list

#include <iostream>
using namespace std;

class Node 
{
int data;
    Node* next;

    public:
        Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}

        friend class Stack;
};

class Stack 
{

private:
	
    Node* top;

public:
    Stack() 
	{ 
	  top = NULL; 
	}

    void push(int x) 
	{
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() 
	{
        if (top == NULL) 
		{
            cout << "Stack underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() 
	{
        if (top == NULL) 
		{
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    void isEmpty() 
	{  
	   if (top == NULL)
     	{
     	  cout << "Stack is empty\n";
          return; 
        }
       else 
         cout<<"Stack is not empty\n";
	    
	}
    
    void DisplayStack() 
	{
       if (top == nullptr) 
	   {
         cout << "Stack is Empty\n";
         return;
       }
      Node* temp = top;
      cout << "Stack elements: ";
      while (temp != nullptr) 
	  {
        cout << temp->data << " ";
        temp = temp->next;
      }
     cout << endl;
    }

};

int main() {
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(5);
    s1.push(7);
    s1.DisplayStack();
    s1.pop();
    s1.DisplayStack();
    int x= s1.peek();
    s1.isEmpty();
    cout<<"Stack's peek is: "<<x<<endl;
    return 0;
}

