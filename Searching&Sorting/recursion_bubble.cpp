#include<iostream>
using namespace std;

template<typename T>
void bubbleSortRecursive(T list[], int size)
{
    //Base Case
    if(size == 1)
    {
        return;
    }

    //One pass of bubble sort
    //
    for(int i = 0; i < size-1; i++)
    {
        if(list[i] > list[i+1])
        {
            swap(list[i], list[i+1]);
        }
    }

    bubbleSortRecursive(list, size - 1);

    


}