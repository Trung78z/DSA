#include <iostream>
using namespace std;

template <typename T>
class Node

{
private:
    T data;
    Node *left;
    Node *right;

public:
    Node(T data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
    template <typename U>
    friend class Tree;
};
template <typename T>
class Tree
{
private:
    Node<T> *root;
    Node<T> *insertRec(Node<T> *node, T data)
    {
        if (node == nullptr)
        {
            return new Node<T>(data);
        }
        else
        {
            if (data < node->data)
            {
                node->left = insertRec(node->left, data);
            }
            else
            {
                node->right = insertRec(node->right, data);
            }
        }
        return node;
    }
    void preorderRec(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

public:
    Tree()
    {
        this->root = nullptr;
    }

    void insert(T data)
    {
        this->root = insertRec(this->root, data);
    }
    void preorderTraversal()
    {
        preorderRec(this->root);
        cout << endl;
    }
};
int main()
{
    Tree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Data (Pre-order): ";
    tree.preorderTraversal();

    return 0;
}