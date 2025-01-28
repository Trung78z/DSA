#include <iostream>

using namespace std;
template <typename T>
class Node
{
    Node *next;

    T data;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ~Node() {}
    template <typename U>
    friend class Queue;
};
template <typename T>

class Queue
{
private:
    Node<T> *rear;
    Node<T> *front;
    int size;

public:
    Queue()
    {
        this->size = 0;
        this->rear = nullptr;
        this->front = nullptr;
    }
    ~Queue()
    {
        while (this->front != nullptr)
        {
            Node<T> *temp = this->front;
            this->front = this->front->next;
            delete temp;
        }
    }

    void enqueue(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (this->rear != nullptr)
        {
            this->rear->next = node;
        }
        this->rear = node;
        if (this->front == nullptr)
        {
            this->front = node;
        }

        this->size++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Node<T> *temp = this->front;
        this->front = this->front->next;
        if (this->front == nullptr)
        {
            this->rear = nullptr;
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
        this->size--;
    }
    T peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        return this->front->data;
    }
    int getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }
};

int main()
{
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.dequeue();
    std::cout << "After dequeuing, front element: " << queue.peek() << std::endl;

    std::cout << "Queue size: " << queue.getSize() << std::endl;

    std::cout << "Queue is empty: " << (queue.isEmpty() ? "true" : "false") << std::endl;
}