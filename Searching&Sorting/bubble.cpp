#include <iostream>

template<typename T>
void bubbleSort(T list[], int arraySize)
{
    bool needNextPass = true;

    for(int i = 1; i < arraySize && needNextPass; i++)
    //O(n)
    {
        needNextPass = false;
        for(int k = 0; k < arraySize: k++)
        //O(n)
        {
            if(list[k] > list[k + 1])
            {
                //Define temporal value 
                T temp = list[k];
                list[k] = list[k + 1];
                list[k + 1] = temp;

                needNextPass = true;
                //Next pass still needed
            }
        }
    }
}

//Time complexity of this sorting algorithm is O(n^2);
