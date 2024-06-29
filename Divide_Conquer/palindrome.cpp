#include<iostream>
#include<string>

bool isPalindrome(const string& s)
{
    if(s.size() <= 1)
    //base case
        return true;

    else if (s[0] != s[s.size() -1])
    //Base Case
        return false;

    else
        return isPalindrome(s.substr(1, s.size() - 2));

}