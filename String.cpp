#include <iostream>
#include<cctype>
#include<string>
#include<cstring>

using namespace std;

class Node {
public:
    char value; 
    //Define a value with char
    Node* next;
    //pointer to next

    Node(char v) : value(v), next(nullptr)
    {
  
    }
};

class String {
private:
    int size;
    //Define the size to track of number of items
    Node* tail;

public:
    //Default constructor
    String() {
        size = 0;
        tail = nullptr; //If there is no item, then tail should point to nullptr
    }

    //Constructor with a value
    String(char sElement)
    {
      Node* newNode = new Node(sElement); //Make a Node with char variable
      if(tail == nullptr)
      {
        tail = newNode;
        tail->next = tail;
      }

      else
      {
        tail->next = newNode; //tail->next should point to newNode
        tail = newNode; //Update tail to newNode
      }

      size++;
    }


    //Parameterized constructor using an input C-string
    String(const char* cstr)
    {
      size = 0;
      tail = nullptr;

      while(*cstr != '\0') //If C-string is not empty
        {
          append(*cstr);
          
          
        }
    }

    ~String() {

        Node* current = tail->next; //Make a current that points to the very first item in the list
        while (current != tail) { //if there is any item in the list, it iterates
            Node* nextNode = current->next; // Define nextNode that points to the next of current
            delete current; //delete current
            current = nextNode; //current points to the nextNode
        }
        delete tail; //Delete the item at the end 
        tail = nullptr; //tail should be nullptr at the end
        //Iteration terminates when it reached tail, which is now nullptr
    }

    String(const String& str) { //Copy constructor
        size = str.size; //Copy the size of list
        tail = nullptr;

        if (size != 0) {
            Node* newNode; 
            Node* toCopy;
            Node* head;

            toCopy = str.tail->next;

            while (toCopy != tail) {
                newNode = new Node;
                newNode->value = toCopy->value;

                if (tail != nullptr) {
                    tail->next = newNode;
                } else {
                    head = newNode;
                }

                tail = newNode;
                toCopy = toCopy->next;
            }

            newNode = new Node;
            newNode->value = toCopy->value;

            if (tail != nullptr) {
                tail->next = newNode;
                tail = newNode;
                tail->next = head;
            } else {
                tail = newNode;
                tail->next = newNode;
            }
        }
    }

    String(String&& str) noexcept { //Move constructor
        size = str.size;
        tail = str.tail;

        str.size = 0;
        str.tail = nullptr;
    }

    void append(const char* element)
    {
        Node* newNode = new Node; //Create a new NOde

        if (size == 0)
        {
            tail = newNode; //tail assign to newNode
        }

        else
        {
            while(*element) //If there is an element
            {
                newNode->value = *element;
                newNode->next = tail->next;
                tail = newNode;//Make tail = newNode at the end
            }
            size++; //Increment size by 1
            element++; //Move to next char in Cstring to continue iteration
        }

    }

    //void append(string s) //s means string
    //{
    //    Node* newNode = new Node; //Make a new Node to add string item to the list
    //    newNode->value = s; //Store string item into the newNode

    //    if(size == 0)
    //    {
    //        tail = newNode; 
    //        newNode->next = newNode;
    //    }

    //    else
    //    {
    //        newNode->next = tail->next;
    //        tail->next = newNode;
    //        tail = newNode;
    //    }
    //}

    const char* toCstr() const
    {
        if(size == 0)
        {
            throw("No item exist");
        }

        char* cstr = new char[size + 1]; //This allocates memeory dynamically for charactor array.
        Node* current = tail->next; //Make a current that points to the very first item in the list;
      
        int i = 0; //set i to 0

        do 
          {
            cstr[i++] = current->value;//Stores the value of current into the cstr
            current = current->next; //Move to next item
          }
        while(current != tail->next); //Iteration terminates when it reached head.

        cstr[i] = '\0'; //Dealocate at the end

        return cstr; 

    }

    int find(char cValue) const {
        if (size == 0) { //if size is 0, this means that there is no item to return

            throw "There is no item in the list";
        }

        Node* current = tail->next; //If there are items, let current point to tail;
        int index = 0;

        while (current != tail) {
            if (current->value == cValue) { //if input value matches to the value in the list
                return index; //Return that index of value
            }

            current = current->next; // Move to next item
            index++; //Increment index by 1
        }

        throw "There is no such character in this list"; //If iteration done, and there is no such value, throw an error
    }

    int getLength()
    {
        return size;
    }

    void reverse()
    {
        if(size <= 1)
        {
            return; //If the size is less than 1, that means items is already sorted
        }

        else
        {

            Node* prev = nullptr; //Create previous node to reverse all nodes
            Node* next = nullptr;// Create next node 
            Node* current = tail->next; //Make a current node that stores the very first element
            while(current!= tail)
            {
                next = current->next; //next item points to the next current item
                prev = current->next; //Reverse the link
                prev->next = current; //Move previous and 

            }

            tail->next = prev; //Change the tail pointer to the very first element

        }
    }

    void reverseCase()
    {
        Node* current = tail->next; //Let current points to the very first element
        while(current != tail) //Iterate until current reaches to tail
        {
            if(islower(current->value)) //if the current value is lowercase
            {
                current->value = toupper(current->value); // change it to the upper case
            }

            else if(isupper(current->value)) //if the current item is upper case
            {
                current->value = tolower(current->value); //change to lower case
            }

            current = current->next; //move to the next item
        }


    }



    //Operator overloading
    String operator+(const String& other)
    {
        String result; //create a new list to add both two lists of string
        Node* current = this->tail->next; //current should point to next of tail, which is the very first element of the list
        do
        {
            result.append(current->value); //append the value of current;
            current = current->next; //Move current to next item;
        }
        while(current != this->tail->next); //if the current is at tail


        current = other.tail->next; //current points to the other item

        do
        {
            result.append(current->value);
        }
        while(current!= other.tail->next);//if current is not nullptr


        return result; //return the newly created list
    }


    String& operator=(const String& other)
    {
       if(this != &other) //This is a self-assignment check, this prevents the object from assigning to itself
       {
            Node* current = this->tail->next; //Current points to the very first element first

            Node* nextNode; //Make nextNode to hold next item

            do
            {
                nextNode = current->next; //nextNode points to next item of head
                delete current;
                current = nextNode;
            }

            while(current!= this->tail->next); //This iterates until it comes back to the head

            Node* otherCurrent = other.tail->next; //From this part, this allocate new memory and copy the elements
            do
            {
                this->append(otherCurrent->value); //Append items from otherCurrent
                otherCurrent = otherCurrent->next; //Move to next item
            }

            while(otherCurrent!=other.tail->next);
       }

       return *this;

    }

    ostream& operator<<(ostream& os, const String& string)
    {
        if(tail == nullptr)
        {
            os << "{ } " << endl;
        }

        else
        {
            Node* current = tail->next;
            os << "{ ";

            do
            {
                os << "{ ";
                os << current->value << ", ";
                current = current->next;
            }

            while(current != tail->next);
            {
                os << "}";
            }

        }

        return os;
    }

    istream& operator>>(istream& is, String& str)
    {
        Node* newNode = new Node;

        if(str.tail == nullptr) //Check if there is any item
        {
            str.tail = newNode; //tail becomes newNode
            newNode->next = newNode; //newNode should point to itself
        }

        else
        {
            newNode->next = str.tail->next;
            str.tail->next = newNode;
            str.tail = newNode;
        }

        is >> newNode->value;
        str.size++;

        return is;
    }

    char operator[](int index) //Off set operator
    {
        if(tail == nullptr) //If tail is null, this means there is no element
        {
            throw("Underflow");
        }

        if(index < size || index > size) //If index is less than or equal to size
        {
            throw("Invalid Index");
        }

        else
        {
            Node* temp = tail->next; //temporary value points to next head item
            char char_at_index; //Define char that points to index

            for(int i = 0; i < index; temp = temp->next, i++)
            {
               char_at_index = temp->value;
            }

            return char_at_index;
        }


    }

    class Iterator //Define Iterator in string class
    {
        private:
            Node* node;
            Node* stop;

        public:

            typedef Iterator iterator;
            typedef const Iterator const_iterator;

            Iterator(Node* item) //Constructor for the iterator class
            {
                node =  item; //node an item
            }

            char& operator*() //Dereference operator, this retuns a reference to the value of the current node
            {
                return node->value; //*returns node value
            }

            const char& operator*() const //This is the const version of the dereference operator. This also returns a reference to the value of the current node
            {
                return node->value;
            }

            Iterator& operator++() //Pre-increment operator, this moves the iterator to the next node.
            {
                node = node->next; //node points to next item
                return *this;//return itself
            }

            Iterator operator++(int) //This is the post-increment operator. The int parameter is a dummy
                                     //
            {
                Iterator iterator = *this; //This line creates a copy of the current instance of the iterator
                ++(*this);//This increments the current instance of the iterator
                return iterator; 

            }

            bool operator!=(const Iterator& iterator)
            {
                return node != iterator.node; //Check is two items is true or false
            }

    };


Iterator begin()
{
    return Iterator(tail->next); //Return head
}

Iterator end()
{
    return Iterator(tail); //Return tail
}

Iterator cbegin() const //cbegin returns head, but constant
{
    return Iterator(tail->next);
}

Iterator cend() const
{
    return Iterator(tail);
}
};




int main() {
    // Test your String class here
    return 0;
}
