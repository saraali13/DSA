/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    int height;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(TreeNode *node)
{
    return node ? node->height : 0;
}

int getBalanceFactor(TreeNode *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

TreeNode *rotateRight(TreeNode *y, int &rotationCount)
{
    rotationCount++;
    TreeNode *x = y->left;
    TreeNode *T = x->right;

    x->right = y;
    y->left = T;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

TreeNode *rotateLeft(TreeNode *x, int &rotationCount)
{
    rotationCount++;
    TreeNode *y = x->right;
    TreeNode *T = y->left;

    y->left = x;
    x->right = T;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

TreeNode *insert(TreeNode *node, int key, int &rotationCount)
{
    if (!node)
        return new TreeNode(key);

    if (key < node->value)
        node->left = insert(node->left, key, rotationCount);
    else if (key > node->value)
        node->right = insert(node->right, key, rotationCount);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->left->value)
        return rotateRight(node, rotationCount);

    if (balance < -1 && key > node->right->value)
        return rotateLeft(node, rotationCount);

    if (balance > 1 && key > node->left->value)
    {
        node->left = rotateLeft(node->left, rotationCount);
        return rotateRight(node, rotationCount);
    }

    if (balance < -1 && key < node->right->value)
    {
        node->right = rotateRight(node->right, rotationCount);
        return rotateLeft(node, rotationCount);
    }

    return node;
}

int main()
{
    TreeNode *root = nullptr;
    int rotationCount = 0;
    int values[] = {10, 30, 50, 20, 3, 15};

    for (int val : values)
    {
        root = insert(root, val, rotationCount);
    }

    cout << "Total rotations: " << rotationCount << endl;
    return 0;
}
