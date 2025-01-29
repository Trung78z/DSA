#include <iostream>
#include <string>

using namespace std;

template <typename K, typename V>
class Node
{
private:
    K key;
    V value;
    Node *next;

public:
    Node(K key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
    template <typename U, typename W>
    friend class HashMap;
};

template <typename K, typename V>
class HashMap
{
private:
    Node<K, V> **table;
    int capacity;
    int size;
    int hash(K key)
    {
        return key % capacity;
    }

public:
    HashMap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->table = new Node<K, V> *[capacity];
        for (int i = 0; i < capacity; i++)
            table[i] = nullptr;

        cout << "HashMap initialized with capacity: " << capacity << endl; // Debug
    }

    void insert(K key, V value)
    {
        int index = hash(key);
        cout << "Inserting key: " << key << " at index: " << index << endl; // Debug statement
        Node<K, V> *node = new Node<K, V>(key, value);
        node->next = table[index];
        table[index] = node;
        size++;
    }
    void remove(K key)
    {
        int index = hash(key);
        Node<K, V> *temp = table[index];
        Node<K, V> *prev = nullptr;
        while (temp)
        {
            if (temp->key == key)
            {
                if (prev)
                    prev->next = temp->next;
                else
                    table[index] = temp->next;
                delete temp;
                size--;
                cout << "Key: " << key << " removed from index: " << index << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Key: " << key << " not found in the HashMap" << endl;
    }

    void display()
    {
        cout << "Displaying hash table:" << endl; // Debug statement
        for (int i = 0; i < capacity; i++)
        {
            Node<K, V> *temp = table[i];
            cout << i << " : ";
            while (temp)
            {
                cout << temp->key << "(" << temp->value << ") "; // Print both key and value
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int getSize()
    {
        return this->size;
    }
};

int main()
{

    cout << "Hello World" << endl;
    HashMap<int, string> h(10);
    cout << "Inserting items into the HashMap..." << endl;
    h.insert(1, "abc");
    h.insert(2, "def");
    h.insert(3, "ghi");
    h.insert(4, "jkl");
    h.insert(5, "mno");
    h.insert(6, "pqr");
    h.insert(7, "stu");
    h.insert(8, "vwx");
    h.insert(9, "yz");

    h.display();
    cout << "Size of the HashMap: " << h.getSize() << endl;
    h.insert(10, "123");
    h.display();
    h.remove(1);
    h.remove(2);
    h.display();
    return 0;
}
