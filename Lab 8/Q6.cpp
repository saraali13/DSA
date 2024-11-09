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
    friend class BinarySearchTree;
};

class BinarySearchTree
{
    TreeNode *root;

    TreeNode *insertNode(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        if (root->value == val)
        {
            return root;
        }
        if (val < root->value)
        {
            root->leftChild = insertNode(root->leftChild, val);
        }
        else
        {
            root->rightChild = insertNode(root->rightChild, val);
        }
        return root;
    }

public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(TreeNode *node) : root(node) {}

    void insert(int val)
    {
        root = insertNode(root, val);
    }

    TreeNode *getRoot()
    {
        return root;
    }
};

TreeNode *swapNodes(TreeNode *node, int &val1, int &val2)
{
    if (node == nullptr)
        return nullptr;

    if (node->value == val1)
    {
        node->value = val2;
    }
    else if (node->value == val2)
    {
        node->value = val1;
    }

    swapNodes(node->leftChild, val1, val2);
    swapNodes(node->rightChild, val1, val2);

    return node;
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
    BinarySearchTree tree;

    tree.insert(13);
    tree.insert(15);
    tree.insert(1);
    tree.insert(5);
    tree.insert(7);
    tree.insert(2);
    tree.insert(8);

    cout << "In-order before swapping: ";
    inOrderTraversal(tree.getRoot());
    cout << endl;

    int val1 = 7, val2 = 1;

    swapNodes(tree.getRoot(), val1, val2);

    cout << "In-order after swapping: ";
    inOrderTraversal(tree.getRoot());
    cout << endl;

    return 0;
}

