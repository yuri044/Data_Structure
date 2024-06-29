#include<iostream>
using namespace std;

template<typename T>
class Circular_Linked
{
    public:
        //Default constructor
        Circular_Linked()
        {
            size = 0;
            //set size is 0 
            tail = nullptr;
            //set tail to nullptr
        }

        //Copy Constructor
        Circular_Linked(const Circular_Linked& obj)
        {
            size = obj.size;
            //Copy the size of list
            tail = nullptr;
            //Set tail as nullptr

            if(size != 0)
            //Check if there is any element in this list
            {
                //Define Node pointer variable
                 Node* newNode, *toCopy = obj.tail->next, *head;

            while(toCopy != obj.tail)
            {
                newNode = new Node(*toCopy);
                if(tail != nullptr)
                {
                    tail->next = newNode;
                }

                else
                {
                    head = newNode;
                }

            tail = newNode;

            toCopy = toCopy->next;
            }

            newNode = new Node(*toCopy);
            if(tail != nullptr)
            {
                tail->next = newNode;
                tail = newNode;
                tail->next = head;
            }

            else
            {
                tail = newNode;
                tail->next = newNode;
            }
            

            }
           

        }
        

        Circular_List& operator=(Circular_Linked&& tempObj)
        {
            if(this != &tempObj)
            {
                clear();

                size = tempObj.size;
                tail = tempObj.tail;
                tempObj.tail = nullptr;
                tempObj.size = 0;

            }

            return *this
        }

        void clear()
        {
           

            while(tail != nullptr)
            {
                //Creates node that points to what you are pointing to
                Node* temp;
                Node* nextNode;

                //set temp = the very top of list
                temp = tail->next;
                
                while(temp != tail)
                //Iterate through all elements in the list until the tail
                {
                    nextNode = temp->next;
                    //nextNode point to next item

                    delete temp;
                    //delete what is assigned to this temp variable

                    temp = nextNode;
                    //assign nextNode to temp variable


                }

                //delete the last item of the list
                delete tail;

                //Set the size = 0 after deleting all items
                size = 0;
            }
        }

        void printInReverse1() const
        //T(n) = n^2
        //Best and Worst is the same
        //Space complexity is O(1)
        {   if(tail != nullptr)
            {
                cout << tail->value;
                Node* lastPrinted = tail;
                //Size of T
            }

            for(int i = 0; i < size; i++)
            //local index also counts as space complexity
            {
                Node* temp = tail->next;
                //Size of T
                for(temp->next != lastPrinted; temp->next)
                {
                    cout << temp->value;
                    lastPrinted = temp;
                }
            }
        }

        void printInReverse() const
        //Time complexity = O(n)
        //Space Complexity = n;

        {
            if(tail != nullptr)
            {
                cout << tail->value;
                if(tail->next != tail)
                {
                     Node** listOfPointers = new Node*[size - 1];
                     //Size of array

                    for(Node* temp = tail->next; int i = 0; temp != tail; temp = temp->next; i++)
                        {
                            listOfPointers[i] = temp;
                        }

                }
            
                cout <<< tail->value;

                for(int i = size - 1; i >= 0; i--)
                //int i is constant because it is always called once
                {
                    cout << listOfPointers[i]->value;
                }

                delete[] listOfPointers;
            }
            
        }

        void Reverse(int size)
        {
            //If the size is less than or equal to 1, then time complexity is constant
            if(size <= 1)
            //If there is less than 1 item in the list, do nothing
            {
                return;
            }

            Node* prevNode = nullptr;
            //Define prevNode that points to nullptr initially
            Node* currentNode = tail->next;
            //Define temporay variable that points to the very first element
            Node* nextNode;

            //Linear time complexity
            for(i = 0; i < size; i++)
            {
                nextNode = currentNode->next;
                //Assign a pointer to next item of temp 
                currentNode->next = prevNode;
                prevNode = currentNode;
                currentNode = nextNode;
                
            }

            tail->next = prevNode;
            
        }

        void print(int size)
        //Take size so that it can iterate all the value
        {
            if(tail == nullptr || size = 0)

            return; 

        }

        void InsertAt(T value, int index)
        {
            if(index < 0 || index > size)
            //Check if index is less than 0 and greater than its size;
            {
                //COuld be on the exam
                throw "Invalid Index";
            }

            Node* newNode = new Node(value);

            if(index == 0)
            //If value is needed to be added at index 0
            {
                if(tail != nullptr)
                {
                    newNode->next = tail->next;
                }

                else
                    tail = newNode;
               
                //next
                tail->next = newNode;
            }

            else if(index == size)
            {
                newNode->next = tail->next;
                tail->next = newNode;
                tail = newNode;
            }

            Node* temp = tail->next;
            for(int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
                temp->next = newNode;
            }
        }

    private:

    class Node
    {
        public:
            Node(T v)
            {
                value = v;
                next = nullptr;

            }

    };

};
