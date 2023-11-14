#include <iostream>
#include<cctype>
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

        Node* newNode = new Node; //Make a new Node to add to the list 
        newNode->value = element; // Insert input value to newNode

        if (size == 0) {

            newNode->next = tail;   //
            tail->next = newNode;

        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int find(char cValue) const {
        if (size == 0) { //if size is 0, this means that there is no item to return

            throw "There is no item in the list";
        }

        Node* current = tail->next; //If there are items, let current point to tail;
        int index = 0;

        while (current != nullptr) {
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

    void reverseCase()
    {
        Node* current = tail->next; //Let current points to the very first element
        while(current! = nullptr) //Iterate until current reaches to nullptr 
        {
            if(islower(curent->value)) //if the current value is lowercase
            {
                current->value = toupper(current->value) // change it to the upper case
            }

            else if(isupper(current->value)) //if the current item is upper case
            {
                current->value = tolower(current->value) //change to lower case
            }

            current = current->next; //move to the next item
        }


    }

    void add(char value)
    {

    }


    //Operator overloading
    String operator+(const String& other)
    {
        String result;
        Node* current = this->tail->next;
        while(current!=nullptr) //if the current is not nullptr
        {
            result.append(current->next); //Reuse append function to add to the new list
            current = current->next; //Move to next item
        }

        current = other.tail->next; //current points to the other item
        while(current!=nullptr) //if current is not nullptr
        {
            result.append(current->value); //add current item to the result
        }

        return result; //return the newly created list
    }



int main() {
    // Test your String class here
    return 0;
}
