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

    TreeNode(int v) : value(v), leftChild(nullptr), rightChild(nullptr) {}
    friend class BinarySearchTree;
};

class BinarySearchTree
{
private:
    TreeNode *root;

    TreeNode *insertNode(TreeNode *currentNode, int value)
    {
        if (currentNode == nullptr)
        {
            return new TreeNode(value);
        }
        if (currentNode->value == value)
        {
            return currentNode; 
        }
        if (value < currentNode->value)
        {
            currentNode->leftChild = insertNode(currentNode->leftChild, value);
        }
        else
        {
            currentNode->rightChild = insertNode(currentNode->rightChild, value);
        }
        return currentNode;
    }

public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(TreeNode *n) : root(n) {}

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    TreeNode *getRoot()
    {
        return root;
    }
};

TreeNode *buildBalancedBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    TreeNode *newRoot = new TreeNode(arr[mid]);

    newRoot->leftChild = buildBalancedBST(arr, start, mid - 1);
    newRoot->rightChild = buildBalancedBST(arr, mid + 1, end);
    return newRoot;
}

void inOrderTraversal(TreeNode *node)
{
    if (node == nullptr)
        return;

    inOrderTraversal(node->leftChild);
    cout << node->value << " ";
    inOrderTraversal(node->rightChild);
}

int main()
{
    int sortedArray[] = {1, 2, 4, 6, 7, 10};
    TreeNode *rootNode = buildBalancedBST(sortedArray, 0, 5);

    cout << "In-Order Traversal of Balanced BST: ";
    inOrderTraversal(rootNode);
    cout << endl;

    return 0;
}

