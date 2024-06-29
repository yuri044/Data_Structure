#include<iostream>

template<typename T>
void mergeSort(T list[], int arraySize)
{
    if(arraySize > 1)
    {
        int* firstHalf = new int[arraySize / 2];
        arraycopy(list, 0, firstHalf, 0, arraySize / 2);
        mergeSort(firstHalf, arraySize / 2);

        //Merge sort the second half
        int secondHalfLength = (arraySize - arraySize / 2);
        int* secondHalf = new int[secondHalf];
        arraycopy(list, arraySize / 2, secondHalf, 0 , secondHalfLength);
        mergeSort(secondHalf, secondHalfLength);

        //Merge firstHalf with secondHalf
        merge(firstHalf, arraySize / 2, secondHalf, secondHalfLength, list);

        delete[] firstHalf;
        delete[] secondHalf;
    }
}

template<typename T>
void merge(T list1[], int list1Size, T list2[], int list2Size, int tem[])
{
    int index1 = 0;
    int index2 = 0;
    int index3 = 0; 

    while(index1 < list1Size && index2 < list2Size)
    {
        if(list1[index1] < list2[index2])
        {
            temp[index3++] = list1[index1++]; 
        }

        else 
        {
            temp[index3++] = list2[index2++];
        }
    }

    while(index1 < list1Size)
    {
        temp[index3++] = list1[index1++];
    }

    while(index2 < list2Size)
    {
        temp[index3++] = list2[index2++];
    }
}