/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <cmath>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int height(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool isBST(TreeNode *node, TreeNode *minNode = nullptr, TreeNode *maxNode = nullptr)
{
    if (node == nullptr)
        return true;
    if ((minNode && node->value <= minNode->value) || (maxNode && node->value >= maxNode->value))
        return false;
    return isBST(node->left, minNode, node) && isBST(node->right, node, maxNode);
}

bool isBalanced(TreeNode *node)
{
    if (node == nullptr)
        return true;
    int balanceFactor = height(node->left) - height(node->right);
    return abs(balanceFactor) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

bool isValidAVL(TreeNode *root)
{
    if (isBST(root) && isBalanced(root))
    return true;
    else 
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(13);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    if (isValidAVL(root))
        cout << "The tree is a valid AVL tree\n";
    else
        cout << "The tree is not a valid AVL tree\n";

    return 0;
}
