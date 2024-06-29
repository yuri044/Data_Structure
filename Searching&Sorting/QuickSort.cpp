#include<iostream>
using namespace std;

template<typename T>
int Partition(T list[], int low, int high)
{
    T pivot = list[high];
    //Define pivot as last element of element:
    int i = low - 1;

    for(int j = low; j <= high - 1; j++)
    {
        if(list[j] < pivot)
        {
            i++;
            swap(list[i], list[j]);

        }
    }

    swap(list[i + 1], list[high]);

    return i + 1;
}

template<typename T>
void QuickSort(T list[], int low, int high)
{
    if(low < high)
    {
        int pivot = Partition(list, low, high);
        QuickSort(list , low, pivot - 1);
        QuickSort(list, pivot + 1, high);
    }
}

