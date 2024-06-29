#include<stack>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool ifNumber(char x)
{
    if(isdigit(x))
    {
        return true;
    }

    else

    {
        return false;
    }
}

bool ifOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    {
        return true;
    }

    else
    {
        return false;
    }
}

float postfixEvaluation(string x)
{
    float a, b;
    stack<float> stack1;

    for(int i = 0; i < x.length(); i++)
    {
        if(ifNumber(x[i]))
        {
            stack1.push(x[i] - '0'); // convert char to int
        }

        else if(ifOperator(x[i]))
        {
            b = stack1.top(); //take out one element from stack
            stack1.pop();
            a = stack1.top(); //take out one element from stack
            stack1.pop();

            if(x[i] == '+')
            {
                stack1.push(a + b);
            }

            else if(x[i] == '-')
            {
                stack1.push(a - b);
            }

            else if(x[i] == '*')
            {
                stack1.push(a * b);
            }

            else if(x[i] == '/')
            {
                stack1.push(a / b);
            }
        }
    }

    return stack1.top(); //Return the top because all items are evaluated at the end
}

int main()
{

    vector<int> v1;
    vector<int> v2;

    auto i = v1.rbegin(); //P1
    auto j = v2.begin(); // P2
    while(i != v1.rend()) //P3
    {
        *j = *i; //P4;P5;
        i++; //P6
        j--;
    }

    ostream_iterator<int> out(cout);
    for(auto i = v2.begin(); i!=v2.end(); i++)
    {
        *out = *i;
        //cout << *i << " "; Same as this code
    }

    string x;
    cout << "Enter the expression: ";
    cin >> x;

    cout << "The result is: " << postfixEvaluation(x) << endl;

    return 0;
}
