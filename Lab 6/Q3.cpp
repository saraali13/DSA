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

bool isFull(queue *que)
{
    if (que->end == que->size - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(queue *que)
{
    if (que->end == que->start)
    {
        return true;
    }
    return false;
}

void enqueue(queue *que, int val)
{
    if (isFull(que))
    {
        cout << "Queue Overflowed";
    }
    que->end++;
    que->arr[que->end] = val;
}

void dequeue(queue *que)
{
    int value = -1;
    if (isEmpty(que))
    {
        cout << "Queue Underflowed\n";
    }
    else
    {
        que->start++;
        que->size++;
    }
}

void Display(queue *que)
{
    for (int i = que->start + 1; i <= que->end; i++)
    {
        cout << que->arr[i] << ", ";
    }
    cout<<endl;
}

int main()
{
    queue *que1 = new queue(10);

    cout << "Before Deque: \n";
    enqueue(que1, 1);
    enqueue(que1, 2);
    enqueue(que1, 3);
    enqueue(que1, 4);
    enqueue(que1, 5);
    enqueue(que1, 6);
    Display(que1);
    cout << "After Deque: \n";
    dequeue(que1);
    dequeue(que1);
    dequeue(que1);
    Display(que1);
}

