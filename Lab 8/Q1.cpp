/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class node 
{
    string data;
    node *right;
    node *left;

public:
    node(string data) : data(data), right(NULL), left(NULL) {}

    friend class BST;
};

class BST 
{
    node *head;

    node* insertion(node *head, string data) 
	{
        if (head == NULL) 
		{
            return new node(data);
        }

        if (head->data == data) 
		{
            return head;
        }
        if (data < head->data) 
		{
            head->left = insertion(head->left, data);
        } 
		else 
		{
            head->right = insertion(head->right, data);
        }
        return head;
    }

public:
    BST() : head(NULL) {}

    void insert(string data) 
	{
        head = insertion(head, data);
    }

    void preOrderTraversal(node *root) 
	{
        if (root == NULL) 
		{
            cout << "NULL ";
            return;
        }

        cout << root->data << " ,";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void traverse() 
	{
        preOrderTraversal(head);
    }

    void transfer(node *root, BST &newTree) 
	{
        if (root == NULL)
            return;

        newTree.insert(root->data);  // Directly insert the current node's data into the new tree
        transfer(root->left, newTree);   // Recursively transfer the left subtree
        transfer(root->right, newTree);  // Recursively transfer the right subtree
    }

    BST catchtree() 
	{
        BST newTree;
        transfer(head, newTree);
        return newTree;
    }
};

int main() 
{
    BST tree1;
    tree1.insert("4");
    tree1.insert("8");
    tree1.insert("2");
    tree1.insert("3");
    tree1.insert("1");
    tree1.insert("9");
    tree1.traverse();
    BST newTree = tree1.catchtree();
    cout << "\npre-order: \n";
    newTree.traverse();
    cout << endl;
    return 0;
}
