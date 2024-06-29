#include<iostream>

using namespace std;

template<typename T>
T sumArray(const int array[], int start, int end)
{
    if(start > end)
    {
        return 0;
    }

    else if (start == end)
    {
        return array[start;]
    }

    else
    {
        int mid = (start + end ) / 2;

        return sumArray(array, start, mid) + sumArray(array, mid + 1, end);
    }
}