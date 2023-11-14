#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    char value;
    //Define a value with char
    Node* next;
    //pointer to next
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
        tail = nullptr;
    }

    //Constructor with a value
    String(char sElement) {
        Node* newNode = new Node;
        //Make a Node with char variable
        newNode->value = sElement;
        //value = sElement 
        newNode->next = nullptr;  //newNode next is nullptr
        tail = newNode;
        size = 1; //set the size increase by 1
    }

    ~String() {
        
        Node* current = tail->next; //Make a current that points to the very first item in the list
        while (current != nullptr) { //if there is any item in the list, it iterates
            Node* nextNode = current->next; // Define nextNode that points to the next of current
            delete current; 
            current = nextNode; 
        }
        delete tail; //Delete the item at the end 
        tail = nullptr; //let tail = delete so that it stops looping
    }

    String(const String& str) { //Copy constructor
        size = str.size; //Copy the size of list
        tail = nullptr;

        if (size != 0) {
            Node* newNode;
            Node* toCopy;
            Node* head;

            toCopy = str.tail->next;

            while (toCopy != nullptr) {
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

    String(String&& str) noexcept {
        size = str.size;
        tail = str.tail;

        str.size = 0;
        str.tail = nullptr;
    }

    void append(char element) {
        Node* newNode = new Node;
        newNode->value = element;

        if (size == 0) {
            newNode->next = tail;
            tail->next = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int find(char cValue) const {
        if (size == 0) {
            throw "There is no item in the list";
        }

        Node* current = tail->next;
        int index = 0;

        while (current != nullptr) {
            if (current->value == cValue) {
                return index;
            }

            current = current->next;
            index++;
        }

        throw "There is no such character in this list";
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
            Node* current = tail->next; //Make a current node that stores the very first element¥
            while(current!= nullptr)
            {
                next = current->next; //next item points to the next current item
                current->next = prev; //Reverse the link
                prev = current; //Move previous and 

            }

            tail->next = prev; //Change the tail pointer to the very first element
           
        }
    }

};



int main() {
    // Test your String class here
    return 0;
}
