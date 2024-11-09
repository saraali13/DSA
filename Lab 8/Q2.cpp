/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *leftChild;
    TreeNode *rightChild;

    TreeNode(int val) : value(val), leftChild(nullptr), rightChild(nullptr) {}
};

int findHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = findHeight(root->leftChild);
    int rightHeight = findHeight(root->rightChild);
    return max(leftHeight, rightHeight) + 1;
}

void printLevel(TreeNode *root, int level, bool leftToRight)
{
    if (root == nullptr)
        return;
    if (level == 1)
    {
        cout << root->value << " ";
    }
    else if (level > 1)
    {
        if (leftToRight)
        {
            printLevel(root->leftChild, level - 1, leftToRight);
            printLevel(root->rightChild, level - 1, leftToRight);
        }
        else
        {
            printLevel(root->rightChild, level - 1, leftToRight);
            printLevel(root->leftChild, level - 1, leftToRight);
        }
    }
}

void zigzagTraversal(TreeNode *root)
{
    int height = findHeight(root);
    bool leftToRight = true;

    for (int level = 1; level <= height; ++level)
    {
        printLevel(root, level, leftToRight);
        leftToRight = !leftToRight; 
    }
}

int main()
{
    TreeNode *root = new TreeNode(24);
    root->leftChild = new TreeNode(12);
    root->rightChild = new TreeNode(20);
    root->rightChild->rightChild = new TreeNode(15);
    root->leftChild->leftChild = new TreeNode(4);
    root->leftChild->rightChild = new TreeNode(11);
    root->leftChild->rightChild->leftChild = new TreeNode(10);
    root->leftChild->rightChild->rightChild = new TreeNode(6);

    cout << "Zigzag Traversal: ";
    zigzagTraversal(root);

    return 0;
}

