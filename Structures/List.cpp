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
    template <typename U>
    friend class List;
};
template <typename T>
class List
{
private:
    Node<T> *head;
    int size;

public:
    List()
    {
        this->size = 0;
        this->head = nullptr;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    int getSize()
    {
        return this->size;
    }

    void add(T data)
    {
        Node<T> *node = new Node<T>(data);

        if (this->isEmpty())
        {
            this->head = node;
        }
        else
        {
            Node<T> *temp = this->head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        this->size++;
    }

    void remove(T data)
    {
        if (isEmpty())
        {
            cout << "List is empty!\n";
            return;
        }
        Node<T> *current = this->head;
        Node<T> *prev = nullptr;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                if (prev == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                size--;
                cout << "Removed: " << data << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        }
    void display()
    {
        if (isEmpty())
        {
            cout << "List is empty!\n";
            return;
        }

        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
int main()
{
    List<int> list;

    list.add(10);
    list.add(20);
    list.add(30);

    list.display();

    list.remove(20);
    list.display();

    list.remove(40);

    cout << "List size: " << list.getSize() << endl;

    return 0;
}