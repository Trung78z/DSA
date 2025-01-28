#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node *left;
    Node *right;
    int height;

public:
    Node(T data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
        this->height = 1;
    }
    template <typename U>
    friend class TreeAVL;
};

template <typename T>
class TreeAVL
{
private:
    Node<T> *root;
    int height(Node<T> *node)
    {
        return node ? node->height : 0;
    }
    int balanceFactor(Node<T> *node)
    {
        return height(node->left) - height(node->right);
    }
    Node<T> *rightRotate(Node<T> *y)
    {
        Node<T> *x = y->left;
        Node<T> *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }
    Node<T> *leftRotate(Node<T> *x)
    {
        Node<T> *y = x->right;
        Node<T> *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
    Node<T> *insert(Node<T> *node, T data)
    {
        if (!node)
            return new Node<T>(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node<T> *node)
    {
        if (node)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    TreeAVL()
    {
        this->root = nullptr;
    }
    void insert(T data)
    {
        root = insert(root, data);
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    TreeAVL<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(28);

    cout << "In-order traversal of AVL tree: ";
    tree.inorder();
    return 0;
}