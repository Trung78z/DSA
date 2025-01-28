#include <iostream>
using namespace std;
template <typename T>

class Node
{
private:
    T data;
    Node *next;

public:
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node() {}
    template <typename U>
    friend class Stack;
};

template <typename T>
class Stack
{
private:
    Node<T> *top;
    int size;

public:
    Stack()
    {
        this->size = 0;
        this->top = nullptr;
    }
    ~Stack()
    {
        while (this->top != nullptr)
        {
            Node<T> *temp = this->top;
            this->top = this->top->next;
            delete temp;
        }
    };
    void push(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (this->top != nullptr)
        {
            node->next = this->top;
        }
        this->top = node;
        this->size++;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        Node<T> *temp = this->top;
        this->top = this->top->next;

        delete temp;
        this->size--;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        return this->top->data;
    }

    int getSize()
    {
        return this->size;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack<int> stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Print the top element
    std::cout << "Top element: " << stack.peek() << std::endl;

    // Pop an element
    stack.pop();
    std::cout << "After popping, top element: " << stack.peek() << std::endl;

    // Get the size of the stack
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    // Check if the stack is empty
    std::cout << "Stack is empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;

    return 0;
}