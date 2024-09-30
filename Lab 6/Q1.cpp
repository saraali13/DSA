/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

template <typename T>
class Node 
{
    T data;
    Node* next;

public:
    Node(T data = 0, Node* next = nullptr) : data(data), next(next) 
    {}

    friend class Stack<T>;
};

template <typename T>
class Stack 
{
private:
    Node<T>* top;

public:
    Stack() 
    {
        top = nullptr;
    }

    void push(int x) 
    {
        Node<T>* temp = new Node<T>(x, top);
        top = temp;
    }

    T pop() 
    {
        if (top == nullptr) 
        {
            cout << "Stack underflow\n";
            return;
        }
        Node<T>* temp = top;
        T value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }

    void DisplayStack() 
    {
        if (top == nullptr) 
        {
            cout << "Stack is Empty\n";
            return;
        }
        Node<T>* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void Sep_Even_Odd(Stack &arr, Stack &E, Stack &O) {
    if (arr.isEmpty()) {
        cout << "Stack is Empty\n";
        return;
    }

    int val;
    while (!arr.isEmpty()) {
        arr.pop(val);
        if (val % 2 == 0) {
            E.push(val);
        } else {
            O.push(val);
        }
    }
}

int main() {
    Stack s1;
    Stack Even;
    Stack Odd;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(5);
    s1.push(7);
    s1.push(1);
    s1.push(2);
    s1.push(3);

    s1.DisplayStack();
    Sep_Even_Odd(s1, Even, Odd);

    cout << "Even ";
    Even.DisplayStack();
    cout << "Odd ";
    Odd.DisplayStack();

    return 0;
}

