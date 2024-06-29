#include<iostream>
#include <string>
using namespace std;

string reverseString(string s, int length)
{
    if(length == 0)
        return " ";

    else
    {
        return s[length - 1] + reverseString(s, length - 1);
    }

}

int main() {
    string inputString;
    
    cout << "Enter a string: ";
    cin >> inputString;
    
    int length = inputString.length();
    
    string reversed = reverseString(inputString, length);
    
    cout << "Reversed string: " << reversed << endl;
    
    return 0;
}
