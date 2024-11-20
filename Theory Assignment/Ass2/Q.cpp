#include <iostream>
#include <queue>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

struct Record
{
    int ID;
    string Name;
    int Age;

    Record(int id, string name, int age) : ID(id), Name(name), Age(age) {}
};

class BSTnode
{
    Record record;
    BSTnode *left;
    BSTnode *right;

public:
    BSTnode(Record &t) : record(t)
    {
        left = nullptr;
        right = nullptr;
    }

    friend class BST;
};

class BST
{
    BSTnode *head;

    BSTnode *inserting(BSTnode *root, Record &record)
    {
        if (root == nullptr)
        {
            return new BSTnode(record);
        }
        if (record.ID == root->record.ID)
            return root;

        if (root->record.ID > record.ID)
        {
            root->left = inserting(root->left, record);
        }
        else
        {
            root->right = inserting(root->right, record);
        }
        return root;
    }

    BSTnode *deleteBSTnode(BSTnode *root, int data)
    {
        if (root == nullptr)
            return nullptr;

        else if (data < root->record.ID)
        {
            root->left = deleteBSTnode(root->left, data);
        }

        else if (data > root->record.ID)
        {
            root->right = deleteBSTnode(root->right, data);
        }

        else
        {
            if (root->left == nullptr)
            {
                BSTnode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                BSTnode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                BSTnode *temp = minValueBSTnode(root->right);
                root->record.ID = temp->record.ID;
                root->right = deleteBSTnode(root->right, temp->record.ID);
            }
        }
    }

    BSTnode *minValueBSTnode(BSTnode *r)
    {
        BSTnode *current = r;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    void preOrderTraversal(BSTnode *root)
    {
        if (root == nullptr)
        {
            cout << "-1" << " ";
            return;
        }

        cout << root->record.ID << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void levelOrderTraversal()
    {
        if (!head)
            return;

        queue<BSTnode *> q;
        q.push(head);

        while (!q.empty())
        {
            BSTnode *curr = q.front();
            q.pop();

            cout << curr->record.ID << " ";

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }

    BSTnode *searching(BSTnode *root, int val)
    {
        if (root == nullptr)
            return nullptr;

        BSTnode *ptr = root;

        if (ptr->record.ID == val)
        {
            return ptr;
        }
        if (ptr->record.ID > val)
        {
            ptr->left = searching(ptr->left, val);
        }
        else
        {
            ptr->right = searching(ptr->right, val);
        }
    }

public:
    BST() : head(nullptr) {}
    BST(BSTnode *n) : head(n) {}

    void insert(Record &record)
    {
        head = inserting(head, record);
    }

    void remove(int data)
    {
        head = deleteBSTnode(head, data);
    }

    string search(int data)
    {
        head = searching(head, data);
        return head->record.Name;
    }

    void traverse()
    {
        preOrderTraversal(head);
    }

    BSTnode *Head()
    {
        return head;
    }
};

class AVLnode
{
    Record record;
    AVLnode *left;
    AVLnode *right;
    int height;

public:
    AVLnode(Record &record) : record(record)
    {
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    friend class AVL;
};

class AVL
{
    AVLnode *root;

    int getHeight(AVLnode *n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return n->height;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int getBalanceFactor(AVLnode *n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return getHeight(n->left) - getHeight(n->right);
    }

    AVLnode *rightRotate(AVLnode *y)
    {
        AVLnode *x = y->left;
        AVLnode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLnode *leftRotate(AVLnode *x)
    {
        AVLnode *y = x->right;
        AVLnode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLnode *inserting(AVLnode *node, Record &record)
    {
        if (node == nullptr)
        {
            return new AVLnode(record);
        }
        if (record.ID < node->record.ID)
        {
            node->left = inserting(node->left, record);
        }
        else if (record.ID > node->record.ID)
        {
            node->right = inserting(node->right, record);
        }
        else
        {
            return node; // Duplicates are not allowed in AVL tree
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int bf = getBalanceFactor(node);

        // LL case
        if (bf > 1 && record.ID < node->left->record.ID)
        {
            return rightRotate(node);
        }

        // RR case
        if (bf < -1 && record.ID > node->right->record.ID)
        {
            return leftRotate(node);
        }

        // LR case
        if (bf > 1 && record.ID > node->left->record.ID)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL case
        if (bf < -1 && record.ID < node->right->record.ID)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLnode *deleteNode(AVLnode *root, int key)
    {
        if (!root)
        {
            return nullptr;
        }

        if (key < root->record.ID)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->record.ID)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Leaf node
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            // Only one child exist
            else if (root->left && !root->right)
            {
                AVLnode *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->right && !root->left)
            {
                AVLnode *temp = root->right;
                delete root;
                return temp;
            }
            // Both child exist
            else
            {
                // Right side smallest element
                AVLnode *curr = root->right;
                while (curr->left)
                {
                    curr = curr->left;
                }
                root->record.ID = curr->record.ID;
                root->right = deleteNode(root->right, curr->record.ID);
            }
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalanceFactor(root);

        // LL case
        if (bf > 1 && getBalanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }

        // RR case
        if (bf < -1 && getBalanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }

        // LR case
        if (bf > 1 && getBalanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RL case
        if (bf < -1 && getBalanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLnode *searching(AVLnode *node, int id)
    {
        if (!node || node->record.ID == id)
        {
            return node;
        }
        else if (id < node->record.ID)
        {
            return searching(node->left, id);
        }
        else
        {
            return searching(node->right, id);
        }
    }

public:
    AVL() : root(nullptr) {}

    void insert(Record &record)
    {
        root = inserting(root, record);
    }

    void remove(int key)
    {
        root = deleteNode(root, key);
    }

    void search(int key)
    {
        root = searching(root, key);
    }

    void traverse()
    {
        preOrderTraversal(root);
    }

private:
    void preOrderTraversal(AVLnode *root)
    {
        if (root)
        {
            cout << root->record.ID << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
};

class Node
{
public:
    vector<Node *> children;
    vector<int> ids;

    // Constructor for B-tree nodes
    Node(int degree)
    {
        ids.resize(2 * degree - 1, 0);        // Initialize ids with zeros
        children.resize(2 * degree, nullptr); // Initialize children to nullptr
    }
};

class B_TREE
{
    Node *root;
    int degree;

public:
    B_TREE(int degree) : root(nullptr), degree(degree) {}

    // Search for a key in the B-tree
    Node *search(int id)
    {
        return search(root, id);
    }

private:
    Node *search(Node *node, int id)
    {
        if (!node)
            return nullptr;

        int i = 0;
        while (i < node->ids.size() && id > node->ids[i])
            i++;

        if (i < node->ids.size() && node->ids[i] == id)
            return node;

        if (node->children.empty())
            return nullptr;

        return search(node->children[i], id);
    }

public:
    // Insert a new key into the B-tree
    void insert(int id)
    {
        if (!root)
        {
            root = new Node(degree);
            root->ids[0] = id;
            root->children.clear();
        }
        else
        {
            if (root->ids.size() == 2 * degree - 1)
            {
                Node *newRoot = new Node(degree);
                newRoot->children[0] = root;
                splitChild(newRoot, 0, root);

                int i = 0;
                if (newRoot->ids[0] < id)
                    i++;
                insertNonFull(newRoot->children[i], id);

                root = newRoot;
            }
            else
            {
                insertNonFull(root, id);
            }
        }
    }

private:
    void insertNonFull(Node *node, int id)
    {
        int i = node->ids.size() - 1;

        if (node->children.empty())
        {
            node->ids.push_back(0);
            while (i >= 0 && node->ids[i] > id)
            {
                node->ids[i + 1] = node->ids[i];
                i--;
            }
            node->ids[i + 1] = id;
        }
        else
        {
            while (i >= 0 && node->ids[i] > id)
                i--;

            if (node->children[i + 1]->ids.size() == 2 * degree - 1)
            {
                splitChild(node, i + 1, node->children[i + 1]);
                if (node->ids[i + 1] < id)
                    i++;
            }
            insertNonFull(node->children[i + 1], id);
        }
    }

    void splitChild(Node *parent, int i, Node *fullChild)
    {
        Node *newNode = new Node(degree);
        newNode->children.clear();

        for (int j = 0; j < degree - 1; j++)
            newNode->ids[j] = fullChild->ids[j + degree];

        if (!fullChild->children.empty())
        {
            for (int j = 0; j < degree; j++)
                newNode->children[j] = fullChild->children[j + degree];
        }

        fullChild->ids.resize(degree - 1);

        parent->children.insert(parent->children.begin() + i + 1, newNode);
        parent->ids.insert(parent->ids.begin() + i, fullChild->ids[degree - 1]);
    }

public:
    // Remove a key from the B-tree
    void remove(int id)
    {
        if (!root)
        {
            cout << "The tree is empty" << endl;
            return;
        }

        remove(root, id);

        if (root->ids.empty())
        {
            Node *temp = root;
            if (root->children.empty())
                root = nullptr;
            else
                root = root->children[0];
            delete temp;
        }
    }

private:
    void remove(Node *node, int id)
    {
        int idx = findKey(node, id);

        if (idx < node->ids.size() && node->ids[idx] == id)
        {
            if (node->children.empty())
                removeFromLeaf(node, idx);
            else
                removeFromNonLeaf(node, idx);
        }
        else
        {
            if (node->children.empty())
            {
                cout << "The key " << id << " is not present in the tree\n";
                return;
            }

            bool flag = (idx == node->ids.size());

            if (node->children[idx]->ids.size() < degree)
                fill(node, idx);

            if (flag && idx > node->ids.size())
                remove(node->children[idx - 1], id);
            else
                remove(node->children[idx], id);
        }
    }

    int findKey(Node *node, int id)
    {
        int idx = 0;
        while (idx < node->ids.size() && node->ids[idx] < id)
            ++idx;
        return idx;
    }

    void removeFromLeaf(Node *node, int idx)
    {
        node->ids.erase(node->ids.begin() + idx);
    }

    void removeFromNonLeaf(Node *node, int idx)
    {
        int id = node->ids[idx];

        if (node->children[idx]->ids.size() >= degree)
        {
            int pred = getPred(node, idx);
            node->ids[idx] = pred;
            remove(node->children[idx], pred);
        }
        else if (node->children[idx + 1]->ids.size() >= degree)
        {
            int succ = getSucc(node, idx);
            node->ids[idx] = succ;
            remove(node->children[idx + 1], succ);
        }
        else
        {
            merge(node, idx);
            remove(node->children[idx], id);
        }
    }

    int getPred(Node *node, int idx)
    {
        Node *cur = node->children[idx];
        while (!cur->children.empty())
            cur = cur->children.back();
        return cur->ids.back();
    }

    int getSucc(Node *node, int idx)
    {
        Node *cur = node->children[idx + 1];
        while (!cur->children.empty())
            cur = cur->children[0];
        return cur->ids[0];
    }

    void fill(Node *node, int idx)
    {
        if (idx != 0 && node->children[idx - 1]->ids.size() >= degree)
            borrowFromPrev(node, idx);
        else if (idx != node->ids.size() && node->children[idx + 1]->ids.size() >= degree)
            borrowFromNext(node, idx);
        else
        {
            if (idx != node->ids.size())
                merge(node, idx);
            else
                merge(node, idx - 1);
        }
    }

    void borrowFromPrev(Node *node, int idx)
    {
        Node *child = node->children[idx];
        Node *sibling = node->children[idx - 1];

        child->ids.insert(child->ids.begin(), node->ids[idx - 1]);
        node->ids[idx - 1] = sibling->ids.back();
        sibling->ids.pop_back();

        if (!child->children.empty())
        {
            child->children.insert(child->children.begin(), sibling->children.back());
            sibling->children.pop_back();
        }
    }

    void borrowFromNext(Node *node, int idx)
    {
        Node *child = node->children[idx];
        Node *sibling = node->children[idx + 1];

        child->ids.push_back(node->ids[idx]);
        node->ids[idx] = sibling->ids[0];
        sibling->ids.erase(sibling->ids.begin());

        if (!child->children.empty())
        {
            child->children.push_back(sibling->children[0]);
            sibling->children.erase(sibling->children.begin());
        }
    }

    void merge(Node *node, int idx)
    {
        Node *child = node->children[idx];
        Node *sibling = node->children[idx + 1];

        child->ids.push_back(node->ids[idx]);
        child->ids.insert(child->ids.end(), sibling->ids.begin(), sibling->ids.end());
        child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());

        node->ids.erase(node->ids.begin() + idx);
        node->children.erase(node->children.begin() + idx + 1);
        delete sibling;
    }
};

vector<Record> generateDummyData(int size)
{
    vector<Record> data;

    for (int i = 0; i < size; i++)
    {
        string name = "Name: " + to_string(i + 1);
        data.emplace_back(i + 1, name, rand() % 100);
    }
    return data;
}

int main()
{
    // Generate dummy data for various sizes
    vector<int> sizes = {1000, 10000};
    int searchCount = 20;

    for (int size : sizes)
    {
        cout << "\nTesting with dataset size: " << size << "\n";
        vector<Record> data = generateDummyData(size);

        // Test BST
        BST bst;

        auto start = high_resolution_clock::now();

        // Insert records
        for (auto &record : data)
        {
            bst.insert(record);
        }
        auto end = high_resolution_clock::now();
        cout << "BST - Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int searchID = data[i].ID;
            string result = bst.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "BST - Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int deleteID = data[i].ID;
            bst.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "BST - Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    for (int size : sizes)
    {
        cout << "\nTesting with dataset size: " << size << "\n";
        vector<Record> data = generateDummyData(size);

        // Test AVL
        AVL avl;

        auto start = high_resolution_clock::now();

        // Insert records
        for (auto &record : data)
        {
            avl.insert(record);
        }
        auto end = high_resolution_clock::now();
        cout << "AVL - Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int searchID = data[i].ID;
            avl.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "AVL - Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int deleteID = data[i].ID;
            avl.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "AVL - Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    for (int size : sizes)
    {
        cout << "\nTesting with dataset size: " << size << "\n";
        vector<Record> data = generateDummyData(size);

        // Test B-Tree
        B_TREE btree(3);

        auto start = high_resolution_clock::now();

        // Insert records
        cout << "Inserting records...\n";
        for (auto &record : data)
        {
            btree.insert(record.ID);
        }
        auto end = high_resolution_clock::now();
        cout << "B-Trees - Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        cout << "Searching records...\n";
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int searchID = data[i].ID;
            btree.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "B-Trees - Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        cout << "Deleting records...\n";
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int deleteID = data[i].ID;
            btree.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "B-Trees - Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    return 0;
}
