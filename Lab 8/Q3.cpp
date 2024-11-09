/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>

class Node
{
public:
    int profitValue;
    Node *leftBranch;
    Node *rightBranch;

    Node(int val) : profitValue(val), leftBranch(nullptr), rightBranch(nullptr) {}
};

class ProfitTree
{
private:
    Node *rootNode;

    int findMaxProfitPath(Node *currentNode)
    {
        if (currentNode == nullptr)
        {
            return 0;
        }

        int leftProfit = findMaxProfitPath(currentNode->leftBranch);
        int rightProfit = findMaxProfitPath(currentNode->rightBranch);

        return currentNode->profitValue + (leftProfit > rightProfit ? leftProfit : rightProfit);
    }

public:
    ProfitTree() : rootNode(nullptr) {}

    void setRoot(Node *root)
    {
        rootNode = root;
    }

    int getMaxProfitPath()
    {
        return findMaxProfitPath(rootNode);
    }

    ~ProfitTree()
    {
        deleteTree(rootNode);
    }

    void deleteTree(Node *currentNode)
    {
        if (currentNode)
        {
            deleteTree(currentNode->leftBranch);
            deleteTree(currentNode->rightBranch);
            delete currentNode;
        }
    }
};

int main()
{
    ProfitTree tree;
    Node *root = new Node(10);
    root->leftBranch = new Node(5);
    root->rightBranch = new Node(13);
    root->leftBranch->leftBranch = new Node(3);
    root->leftBranch->rightBranch = new Node(7);
    root->rightBranch->rightBranch = new Node(1);
    root->leftBranch->leftBranch->leftBranch = new Node(3);
    root->leftBranch->leftBranch->rightBranch = new Node(2);
    root->leftBranch->rightBranch->rightBranch = new Node(1);

    tree.setRoot(root);

    int maxProfit = tree.getMaxProfitPath();
    std::cout << "Maximum profit path: " << maxProfit << std::endl;

    return 0;
}

