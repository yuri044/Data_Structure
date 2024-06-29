#include<iostream>

template<typename T>
class MyIterator
{
    public:

        //Constructor
        MyIterator(T* pointer = nullptr) : p(pointer)
        {

        }

        //
        MyIterator& operator++()
        {
            p++;
            return *this;
        }

        MyIterator operator++(int)
        {
            MyIterator returnIter(*this);
            p++;
            return returnIter;
        }

        bool operator==(const MyIterator& int) const
        {
            return p == MyIterator.p;
        }

        T& operator[] (int index) const 
        //This takes an integer index as an argument and returns a reference to an object type T.
        //
        {
            return *(p + index);
        }
        
        T& operator*() const
        {
            return *p;
        }

        T* operator->() const
        {
            return p;
        }

        MyIterator& operator+=(int n)
        {
            p+=n;
            return *this;

        }
        
    private:
        T* pointer;
    

};


template<typename T>
class MyVector
{
    public:

    MyIterator begin() const
    {
        return MyIterator(start);
    }

    MyIterator end() const
    {
        return MyIterator(start + size);
    }

    private:
        int size;
        int cap;
        T* start;

};