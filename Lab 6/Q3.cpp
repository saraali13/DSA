/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class queue
{
public:
    int *arr;
    int size;
    int start;
    int end;

    queue(int size) : size(size)
    {
        start = -1;
        end = -1;
        arr = new int[size];
    }
};

bool isFull(queue *q)
{
    if (q->end == q->size - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(queue *q)
{
    if (q->end == q->start)
    {
        return true;
    }
    return false;
}

void enqueue(queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Queue Overflowed";
    }
    q->end++;
    q->arr[q->end] = val;
}

void dequeue(queue *q)
{
    int value = -1;
    if (isEmpty(q))
    {
        cout << "Queue Underflowed\n";
    }
    else
    {
        q->start++;
        q->size++;
    }
}

void Display(queue *q)
{
    for (int i = q->start + 1; i <= q->end; i++)
    {
        cout << q->arr[i] << ", ";
    }
    cout<<endl;
}

int main()
{
    queue *que = new queue(10);

    cout << "Before Deque: \n";
    enqueue(que, 1);
    enqueue(que, 2);
    enqueue(que, 3);
    enqueue(que, 4);
    enqueue(que, 5);
    enqueue(que, 6);
    Display(que);
    cout << "After Deque: \n";
    dequeue(que);
    dequeue(que);
    dequeue(que);
    Display(que);
}

