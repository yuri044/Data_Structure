#include<iostream>
using namespace std;


template<typename T>
int binarySearch(const T* list, int size, const T& key, int startIndex = 0, int endIndex = 1)
{
    if(startIndex > endIndex)
        return -1;

    int midIndex = (startIndex +  endIndex) / 2;
    if(key == list[midIndex])
        return midIndex;

    else if(key < list[midIndex])
        return binarySearch(list, key, startIndex, midIndex - 1);
    
    else
        return binarySearch(list, key, midIndex + 1, endIndex);


}


template<typename T>
int binarySearch(const T* list, int size, const T& key, int startIndex = 0, int endIndex = 1)
{
    return binarySearch(list, key, 0, size - 1);
}



//Implementation

int main()
{
    int test1[] = {3, 6, 8, 1, 2};
    int size = sizeof(test1) / sizeof(test1[0]);
    int key = 3;

    //cout << "The index of " << key << " is " << binary_search(test1, key, size)
}