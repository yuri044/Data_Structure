#ifndef LINKED_LIST_H
#define LINKED_LIST_H



template<typename T>
class LinkedList
{
    public:
         LinkedList()
         {
            //Make constructor head = tail = null
            head = tail = nullptr;
            //set initial size as 0;
            size = 0;

         }

         //Destructor
         ~LinkedList()
         {
            //Define node that points to the current node
            Node<T>* current = head;
            //Define a node that points 
            Node<T>* nextNode;

            while(current != nullptr)
            //if the head is not nullptr
            {
                nextNode = current->next;
                //Next node point to the next item of current
                delete current;
                //Delete item in current
                current = nextNode;
            }

            //set head and tail point to nullptr
            head = tail = nullptr;
            //Set the size = 0;
            size = 0;
         }



         //Copy constructor
         //take existing object
         LinkedList(const LinkedList<T>& existObj)
         {
            size = existObj.size;
            //copy the size from the existing object 
           
            Node<T>* toCopy = existObj.head;
            //creating a pointer to the head of the list to be copied

            Node<T>* prevNode = nullptr;
            //Initialize a pointer to keep track of the previous node
            //Initially nullptr

            head = tail = nullptr;
            //Initialize head and tail pointer to the null as a default

            while(toCopy != nullptr)
            //Iterate through each node in the list for copying
            {
                Node<T>* newNode = new Node<T>(*toCopy);
                //Inside the loop, this part creates a new node that is a copy of the current node in the existing list
                if(head == nullptr)
                //If there is no item in the list
                {
                    head = newNode;
                    //head is newNode
                }

                else
                //If there is some items
                    prevNode->next = newNode;
                    //next item point to the new Node

                prevNode = newNode;
                //previous node points to the new node

                toCopy = toCopy->next;
            }

            tail = prevNode;
         }

        T& operator[](unsigned int index)
        //This declaration of the operator
        //Allows you to access elements in the list using array-like syntax
        {

            if(index < 0 || index >= size)
            //This checks if the given index is valid
            //If this is less than 0 or greater than or equal to the size,throw an error
            {
                throw "Index out of range";
            }

            Node<T>* temp = head;
            //Creates a variable called temp that holds an item
            for(int i = 0; i < index; i++)
            //Iterates through variable until it reaches specified index
            {
                //If it reaches, temp points to the next node
                temp = temp->next;
                
            }

            //Return the actual value of index
            return temp->data;
            
        }

        T removeFrom(unsigned int index)
        {
            Node<T>* toDelete;
            //Initiate variable that holds an element to delete
            Node<T>* prevNode = head;
            //Initiate variable that holds previous Node

            if(index == 0)
            {
                toDelete = head;
                //toDelete holds head element
                head = toDelete->next;
                //head is pointing to next node

                if(head == nullptr)
                //If head is nullptr, this means there is no element
                {
                    tail = nullptr:
                    //If there is no element, then head and tail should point to nullptr
                }

            }

            else
            {

                for(int i = 0; i < index - 1; i++)
                //Iterate through all elements
                //index - 1 is the very last element of the list
                     {
                        prevNode = prevNode->next;
                        //prevNode points to the next item

                     }

                toDelete = prevNode->next;
                //Assign the element to toDelete variable
                prevNode->next = toDelete->next;
                //previous Node should points to the next item of toDelete variable

                if(index == size - 1)
                //if index is same is the last index
                {
                    tail = prevNode;
                    //tail will be the previous node, but next item should be the element
                }

            }
        
            T toReturn = toDelete->data;

            delete toDelete;
            //Delete the item that points to the said index
            size--;
            //Remove size by one
            return toReturn;
        }

        T addIndex(int index, T element)
        {
            if(index == 0)
            //If index is first
            {
                addFirst(element);
                //call function that add the element to the front
            }

            else if
            (index >= size)
            //If index is greater than or equal to the size, 
            //This automatically inserts the element at the end of list
            {
                addLast(element);
            }

            else
            {
                Node<T>* current = head;
                //Decleare current element that points to the head element
                for(int i = 1; i < index; i++)
                //Iterates until it reaches the index
                {
                    current = current->next;
                    //Assign the element to the next
                    
                }

                Node<T>* temp = current->next;
                //If we find the index, then make temp variable and assgins the element
                current->next = new Node<T>(element);
                (current->next)->next = temp;
                size++;
            }
        }

        T addFirst(T element)
        {
            Node<T>* newNode = new Node<T>(element);
            newNode->next = head;
            //Since new Node comes to the first , next element should be head

            head = newNode;

            size++;
            
            if(tail == nullptr)
            //If there is no item in the list
            {
                tail = head;
                //tail is the element that we are inserting
            }

        }

        T addLast(T element)
        {
            if(tail == nullptr)
            //If there is no item
            {
                head = tail = new Node<T>(element);
                //Let head, tail is new node
            }

            else
            {
                tail->next = new Node<T>(element);
                //add new element to the next of tail
                tail = tail->next;

            }

            size++;
        }

    private:

        Node<T>* head, *tail;
        unsigned int size;


    class Node {
    public:

        T data;
        Node<T>* next;

        //Default constructor
        Node(T value)
        {
            data = value;
            next = nullptr;
        }



};


};


#endif