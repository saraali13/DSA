/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;

    for (ListNode *list : lists)
    {
        if (list != nullptr)
        {
            minHeap.push(list);
        }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (!minHeap.empty())
    {
        ListNode *smallest = minHeap.top();
        minHeap.pop();

        current->next = smallest;
        current = current->next;

        if (smallest->next != nullptr)
        {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode *> lists = {list1, list2, list3};

    ListNode *mergedList = mergeKLists(lists);

    cout << "Merged sorted list: ";
    printList(mergedList);

    return 0;
}
