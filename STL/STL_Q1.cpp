#include<iostream>
#include<algorithm>
#include<vector>

class Factorial 
{
    public:
        int operator()(int x)
        {
            if(x < 2)
            {
                return 1;
            }

            else
            {
                return x * (x - 1);
            }
        }
};

int main()
{
    vector<int> v;

    transform(v.begin(), v.end(), v.begin(), Factorial());
}
    