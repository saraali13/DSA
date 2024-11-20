/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> maxHeap;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {

        maxHeap.push({nums[i], i});

        while (!maxHeap.empty() && maxHeap.top().second <= i - k)
        {
            maxHeap.pop();
        }

        if (i >= k - 1)
        {
            result.push_back(maxHeap.top().first);
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = slidingWindowMaximum(nums, k);

    cout << "Sliding window maximums: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

