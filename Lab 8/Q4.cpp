/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class TreeNode
{
    string data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(string value) : data(value), left(nullptr), right(nullptr) {}

    friend class BinarySearchTree;
};

class BinarySearchTree
{
private:
    TreeNode *root;

    TreeNode *insert(TreeNode *rootNode, string value)
    {
        if (rootNode == nullptr)
        {
            return new TreeNode(value);
        }

        if (value < rootNode->data)
        {
            rootNode->left = insert(rootNode->left, value);
        }
        else if (value > rootNode->data)
        {
            rootNode->right = insert(rootNode->right, value);
        }
        return rootNode;
    }

    bool isIdentical(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        return (root1->data == root2->data &&
                isIdentical(root1->left, root2->left) &&
                isIdentical(root1->right, root2->right));
    }

    bool isSubtree(TreeNode *mainRoot, TreeNode *subRoot)
    {
        if (subRoot == nullptr)
            return true;
        if (mainRoot == nullptr)
            return false;
        if (isIdentical(mainRoot, subRoot))
            return true;
        return isSubtree(mainRoot->left, subRoot) || isSubtree(mainRoot->right, subRoot);
    }

    void preOrderTraversal(TreeNode *rootNode)
    {
        if (rootNode == nullptr)
        {
            cout << "-1 ";
            return;
        }
        cout << rootNode->data << " ";
        preOrderTraversal(rootNode->left);
        preOrderTraversal(rootNode->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(string value)
    {
        root = insert(root, value);
    }

    void displayPreOrder()
    {
        preOrderTraversal(root);
        cout << endl;
    }

    bool checkSubtree(BinarySearchTree &otherTree)
    {
        return isSubtree(root, otherTree.root);
    }
};

int main()
{
    BinarySearchTree tree1;
    tree1.insert("1");
    tree1.insert("7");
    tree1.insert("6");
    tree1.insert("2");
    tree1.insert("9");
    tree1.insert("3");

    cout << "Tree 1 Preorder Traversal: ";
    tree1.displayPreOrder();

    BinarySearchTree tree2;
    tree2.insert("4");
    tree2.insert("5");
    tree2.insert("3");

    cout << "Tree 2 Preorder Traversal: ";
    tree2.displayPreOrder();

    if (tree1.checkSubtree(tree2))
    {
        cout << "Tree 2 is a subtree of Tree 1\n";
    }
    else
    {
        cout << "Tree 2 is NOT a subtree of Tree 1\n";
    }

    return 0;
}


