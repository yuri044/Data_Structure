#include <iostream>
using namespace std;

int MAX_SIZE = 100;

template<typename T>
class Stack
{
    private:
        int Array[MAX_SIZE];
        int top;
        T* value;
        int capacity;

    public:
        //constructor
        Stack()
        {
            top = -1
            //If top is -1, then it is empty 
            //Set default as empty
        }

        void push(int value)
        {
            if(top == MAX_SIZE - 1)
            {
                cout << "Stack Overflow " << endl;
                return;
            }

            else
            {
                Array[top++] = value;
            }
        }

        void pop()
        {
            if(top == -1)
            {
                cout << "There is no element to remove " << endl;
                return;
            }

            //remove top
            top--;
        }

        int peek()
        {
            return top;
        }

        int isEmpty()
        {
            if(top == -1)
            {
                return 1;
            }

            else
            {
                return 0;
            }
        }
};

int main()
{
    Stack<int> S;

    S.push(1);
    S.peek();

}