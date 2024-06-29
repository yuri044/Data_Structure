#include<iostream>
using namespace std;

template<typename T>
class Node
//Overhead size
//2*Sieof(Node*) + 2n Size of (Node*)
{
    T value;
    //value that holds an element
    Node* next;
    //Point to the next item
    Node* prev;
    //Point to the previous item
};

template<typename T>
class Doubly_Linked
{
    private:
        Node<T>* head;
        //Pointer to head
        Node<T>* tail;
        //Pointer to tail

        unsigned int = size;
        //This is for size of list

    public:

        //Constructor with no element
        Doubly_Linked()
        {
            head = tail = nullptr;
            //set head and tail as nullptr as default
            size = 0;
            //set size is 0 for default constructor
        }

        //Constructor with elements
        Doubly_Linked(T element)
        {
            Node<T>* newNode = new Node<T>;
            //Create a new node for new element
            newNode->value = element;
            //value of new node is an element that is inserted
            newNode->next = nullptr;
            //next of new node is nullptr because there is no element after this next element
            newNode->prev = nullptr;
            //previous pointer of new Node is nullptr because there is no element.

            head = tail = newNode;
            size = 1;
        }

        //Destructor
        ~Destructor()
        {
            Node<T>* current;
            current = head;

            while(current != nullptr)
            {//If current is not nullptr
                next = current->next;
                //set next = the next item of current
                delete current;
                current = next;
                //Assign next to the current, next is also pointing to the same value
            }

            size = 0;
            head = tail = nullptr;

        }

        template<typename T>
        void addLast(T element)
        {

        }

        template<typename T>
        Binary_Search(Node<T>* head, T element)
        {
            if(size == 0)
            {
                throw("No such element exist");
            }
            else
            {
                Node<T>* start = head;  //Define pointer to the head item
                Node<T>* end = nullptr; 
                Node<T>* middle; //Make new node called middle

                while(start != end)
                {
                    middle = ((start + end) / 2); //head + tail divided by 2 produces 

                    if(middle != nullptr && middle->value == element) //if middle is not nullptr AND middle->value is the input
                    {
                        return middle->value; //Return the value of middle
                    }

                    else if(middle->value > element) //If the middle element is greater than the input value
                    {
                        end = middle; // split into half, and use left list, which means middle will be middle is the end of left list
                    }

                    else if(middle->value < element) //If the middle element is less than the middle 
                    {
                        start = middle->next; //Split the list into half and use right handside of list, still, end is nullptr
                    }

                }

                return nullptr; //If the value is not found, return nullptr
            }

            template<typename T> 
            Node<T>* getMiddle(Node<T>* start, Node<T>* end)
            {
                Node<T>* 
            }
            
        }

};