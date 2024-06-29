#include<iostream>
using namespace std;

template<typename T>
class Node
{
    public:
        Node* next;
        T value;

        //Constructor for Node class
        Node(T value)
        {
            this->value = value;
            this->next = nullptr;
        }
};

template<typename T>
class Queue
{
    private:
        Node<T>* front;
        Node<T>* back;
        int size:
    public:
        //Constructor with no element
        Queue()
        {
           front = nullptr;
           back = front;
           size = 0;
        }

        int getSize()
        {
            return size;
        }


};