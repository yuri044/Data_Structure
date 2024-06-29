#include<iostream>

void insertionSort(int list[], int listSize)
{
    for (int i = 1; i < listSize; i++)
    {
        int currentElement = list[i];

        int k;

        for(k = i - 1; k >= 0 && list[k] > currentElement; k--)
        {
            list[k + 1] = list[k];
        }

        //Inserting the current element into list[k + !]
        list[k + 1] = currentElement;

    }
}

void RecursiveInsertionSort(int list[], int listSize)
{
    //Base Case
    if(listSize = 1)
    {
        return;
    }

    else if
}