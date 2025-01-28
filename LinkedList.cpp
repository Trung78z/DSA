#include <iostream>

template <typename T>
class Node
{
private:
    T data;
    Node *next;
    Node *prev;

public:
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    ~Node()
    {
        // Do not delete next and prev here to avoid double deletion
    }

    template <typename U>
    friend class List; // Allow List to access private members
};

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    ~List()
    {
        Node<T> *current = this->head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }
    void add(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = node;
        }
        this->size++;
    }
    void remove(T data)
    {
        Node<T> *current = this->head;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    this->head = current->next;
                }
                if (current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    this->tail = current->prev;
                }
                delete current;
                this->size--;
                return;
            }
            current = current->next;
        }
    }
    void print()
    {
        Node<T> *current = this->head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    int getSize()
    {
        return this->size;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    bool contains(T data)
    {
        Node<T> *current = this->head;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    T get(int index)
    {
        if (index < 0 || index >= this->size)
        {
            return T(); // Return default value of T
        }
        Node<T> *current = this->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }
    void set(int index, T data)
    {
        if (index < 0 || index >= this->size)
        {
            return;
        }
        Node<T> *current = this->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        current->data = data;
    }
};
int main()
{
    List<int> list;

    // Add elements to the list
    list.add(10);
    list.add(20);
    list.add(30);

    // Print the list
    std::cout << "List contents: ";
    list.print();

    // Remove an element
    list.remove(20);
    std::cout << "After removing 20: ";
    list.print();

    // Check if the list contains an element
    std::cout << "List contains 10: " << (list.contains(10) == true ? "true" : "false") << std::endl;
    std::cout << "List contains 20: " << (list.contains(20) ? "true" : "false") << std::endl;

    // Get the size of the list
    std::cout << "List size: " << list.getSize() << std::endl;

    // Get an element by index
    std::cout << "Element at index 1: " << list.get(1) << std::endl;

    // Set an element by index
    list.set(1, 40);
    std::cout << "After setting index 1 to 40: ";
    list.print();

    return 0;
}