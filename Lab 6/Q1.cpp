/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

template <typename T>
class Node 
{
public:
    T data;
    Node* next;

    Node(T data = 0, Node* next = NULL) : data(data), next(next) 
    {}

   // friend class Stack<T>;
};

template <typename T>
class Stack 
{
private:
    Node<T>* top;

public:
    Stack() 
    {
        top = NULL;
    }

    void push(int x) 
    {
        Node<T>* temp = new Node<T>(x, top);
        top = temp;
    }

    T pop() 
    {
        if (top == NULL) 
        {
            cout << "Stack underflow\n";
            return -1;
        }
        Node<T>* temp = top;
        T value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() 
    {
        return top == NULL;
    }

    void DisplayStack() 
    {
        if (top == NULL) 
        {
            cout << "Stack is Empty\n";
            return;
        }
        Node<T>* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) 
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }
};

template <typename T>
void Sep_Even_Odd(Stack<T> &arr, Stack<T> &E, Stack<T> &O) {
    if (arr.isEmpty()) {
        cout << "Stack is Empty\n";
        return;
    }

    T val;
    while (!arr.isEmpty()) {
        val=arr.pop();
        if (val % 2 == 0) {
            E.push(val);
        } else {
            O.push(val);
        }
    }
}

int main() {
    Stack<int> s1;
    Stack<int> Even;
    Stack<int> Odd;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(11);
    s1.push(27);
    s1.push(31);
    s1.push(24);
    s1.push(53);

    s1.DisplayStack();
    Sep_Even_Odd(s1, Even, Odd);

    cout << "Even Stack after Sepration: ";
    Even.DisplayStack();
    cout << "Odd Stack after Sepration: ";
    Odd.DisplayStack();

    return 0;
}
