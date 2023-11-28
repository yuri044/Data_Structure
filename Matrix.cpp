#include<iostream>
using namespace std;

class Matrix
{
  public:

    int value;
    int size;
    Matrix* root;
    Matrix* nextinRow;
    Matrix* nextInColumn;
    
    //Default constructor with no value
    Matrix()
    {
      value = 0;
      size = 0;
      root = nullptr;
      nextInColumn = nullptr;
      nextInColumn = nullptr;
      
    }

    Matrix(int val) //Defualt constructor with single value
    {
      root = nullptr;
      value = val;
      size++;
      nextInColumn = nullptr;
      nextinRow = nullptr;
    }

    //Paraterized constructor
    Matrix(int matrix[][3], int columns, int rows)
    {
       size = columns * rows; //Total size is rows * columns
       
       root = nullptr; //Make a root that points to nullptr
       Matrix* head[rows]; //Expand the # of rows
       Matrix* rightTemp, *newPtr; //Make a pointer and rightTemp pointers
       for(int i= 0; i < rows; ++i)//Iterate the number of rows
         {
           head[i] = nullptr;//
           for(int j = 0; j < columns; ++j) //Iterate the number of columns O(n)
             {
               newPtr = new Matrix(matrix[i][j]); //NewPtr make the number of columns and rows

               if(!root) //If the root is null; 
               {
                 root = newPtr; //Make a root newPtr
               }

               if(!head[i]) //If the current rows head is null
               {
                 head[i] = newPtr;//Make the head of the current row point to the newPtr;
               }

               else //f the head is null
               {
                 rightTemp->nextinRow = newPtr; //NextRow points to newPtr;
               }

               rightTemp = newPtr;
             }
         }

        for(int i = 0; i < columns-1; ++i) //Iterate over the columns
          {
            Matrix *temp1 = head[i]; //
            Matrix *temp2 = head[i + 1];
            while(temp1 && temp2)
              {
                temp1->nextInColumn = temp2;
                temp1 = temp1->nextinRow;
                temp2 = temp2->nextinRow;
              }
          }
    }

  ~Matrix()
  {
    if(size != 0) //If we have any item to delete
      {
        Matrix* tempRow = root; //Make a pointer that points to nullptr
        Matrix* tempCol; //Pointer that holds col;
        Matrix* delPtr; //Pointer that holds variable to delete 

        while(tempRow != nullptr) //while there are items
          {
            tempCol = tempRow; //Make tempCol point at the same as a tempRow;
            while(tempCol != nullptr)
              {
                delPtr = tempCol; //delete tempCol;
                tempCol = tempCol->nextinRow; //Move to next row:
                delete delPtr; //Delete the delPtr;
              }

            tempRow = tempRow->nextInColumn;
          }
      }

     else
    {
      return; //If size is 0, there is nothing to delete 
    }
  }

  int findRow(int indexRow)
  {
    if(size == 0)
    {
      throw("Specified row does not exist");
    }

    else
    {
      
    }
  };

  void print()//Utility function 
  {
    Matrix* tempRow = nullptr;
    Matrix* temoCol = nullptr;
  }
    
  
};

class Iterator
{
    public:
      Matrix* current;

      Iterator(Matrix* start) //Default constructor
      {
        current = start; 
      }

      int operator* () //Dereference operator
      {
        return current->value;
        
      }

      Iterator& operator++()
      {
        if(current != nullptr) //if there is a item in a matrix
        {
          current = current->nextinRow; //Return next item in the row
        }

        return *this;
      }

      Iterator operator++(int) //post-increment operator
      {
        Iterator temp = *this; //Make a temporal variable to post incremenent
        ++(*this);
        return temp;
      }

    bool operator==(const Iterator& other)
    {
      return current == other.current;
    }

    bool operator!=(const Iterator& other)
    {
      return current != other.current;
    }

    
};

int main()
{
  int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Matrix matrix(array, 3, 3);
  
}
