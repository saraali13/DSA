/*
Name: S. Sara Ali
ID: 23K-0070
*/

//Stack using arrays

#include <iostream>
using namespace std;

class Stack 
{
private:
	
    int top;
    int arr[10];

public:
    Stack() 
	{ 
	   top = -1; 
	}

    void push(int x) 
	{
        if (top >= 9) 
		{
            cout << "Stack overflowed\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() 
	{
        if (top < 0) 
		{
            cout << "Stack underflow\n";
            return;
        }
        top--;
    }

    int peek() 
	{
        if (top < 0) 
		{
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void isEmpty() 
	{ 
	  if (top < 0) 
	  {
        cout << "Stack is empty\n";
        return; 
      }
      else 
      cout<<"Stack is not empty\n";
	}
	
    void DisplayStack() 
	{
      if (top == -1) 
	  {
        cout << "Stack is Empty\n";
        return;
      }
    
      cout << "Stack elements: ";
      for (int i = top; i >= 0; i--) 
	  {
        cout << arr[i] << " ";
      }
      cout << endl;
    }

};

int main() 
{
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
