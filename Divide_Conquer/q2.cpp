#include<iostream>
using namespace std;

template<typename T>
class Node
{
    public:
        T value;
        Node<T>* next;
};

template<typename T>
T max(T value1, T value2)
{
    return (value1 > value2) ? value1 : value2;
}

template<typename T>
T ConRecursiveFunction(T arr[], int low, int high)
{
    if(low == high)
    {
        return arr[low];
    }

    return max(arr[low], ConRecursiveFunction(arr, low + 1, high));
}

template<typename T>
T LinkedRecursiveFunction(Node<T>* node)
{
    if(node->next == nullptr)
    {
        return node->value;
    }

    else
    {
        return max(node->value, LinkedRecursiveFunction(node->next));
    }
}
