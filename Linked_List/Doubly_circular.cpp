#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T value;         // Value that holds an element
    Node* next;      // Point to the next item
    Node* prev;      // Point to the previous item
};

template<typename T>
class Circular_Double {
private:
    Node<T>* tail;  // Use a specific type for Node, like Node<int> if you want integers
    int size;


public:
    T popLast()
    {
        if(head == nullptr)
        //There is no item in the list
        {
            throw "List is Empty"; 
        }
        size--;
        Node* toDelete = head->next;
        T valueToReturn = toDelete->value;

        toDelete->prev->next = head;
        head->prev = toDelete->prev;

        delete toDelete;

        if(size == 0)
        {
            head = nullptr;
        }

        return valueToReturn;
    }

    void insertFirst(T value)
    {
        Node* newNode = new Node(value);//(1)
        size++;

        if(head == nullptr)
        {
            newNode->next = newNode;
            newNode->prev = newNode;     
        }

        else
        {
            newNode->next = head;//(2)
            newNode->prev = head->prev;//(3)
            head->prev->next = newNode;//(4)
            head->prev = newNode;//(5)
        }

        head = newNode;

    }
};
