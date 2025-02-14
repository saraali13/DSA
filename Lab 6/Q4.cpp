/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class stack 
{
public:
    int top;
    int* arr;
    int size;

    stack(int size) : size(size), top(-1) 
    {
        arr = new int[size];
    }

    ~stack() 
    {
        delete[] arr;
    }
};

bool isEmpty(stack* s) 
{
    return s->top == -1;
}

bool isFull(stack* s) 
{
    return s->top == s->size - 1;
}

void push(stack* st, int val) 
{
    if (isFull(st)) 
    {
        cout << "Stack is full" << endl;
    } 
    else 
    {
        st->arr[++st->top] = val;
    }
}

int pop(stack* st) 
{
    if (isEmpty(st)) 
    {
        cout << "Stack Underflow" << endl;
        return -1; 
    }
    return st->arr[st->top--];
}

class queue 
{
    stack* s1; 
    stack* s2; 

public:
    queue(int size) 
    {
        s1 = new stack(size);
        s2 = new stack(size);
    }

    ~queue() 
    {
        delete s1;
        delete s2;
    }

    void enqueue(int val) 
    {
        push(s1, val);
        cout << val << ", ";
    }
    

    void dequeue() 
    {
        if (isEmpty(s1) && isEmpty(s2)) 
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (isEmpty(s2)) 
        {
            while (!isEmpty(s1)) 
            {
                push(s2, pop(s1));
            }
        }

        if (!isEmpty(s2)) 
        {
            int val = pop(s2);
            cout << val << ", ";
        }
    }
};

int main()
{
    queue q(10); 

    cout << "Enqueuing elements:\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);

    cout << "\nDequeuing elements:\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
