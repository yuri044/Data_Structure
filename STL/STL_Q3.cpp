#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    const int SIZE = 10;
    vector<int> vector1(SIZE);

    cout << "Enter: " << SIZE << " integers " << endl;
    for(auto i = vector1.begin(); i != vector1.end(); i++)
    {
        cin >> *i;
    }

    cout << "Enter the increment factor: " << endl;
    int increment;
    cin >> increment;

    for_each(vector1.begin(), vector1.end(), increment
    {
        x += increment;
    });

    for_each(vector1.rbegin(), vector.rend(), (int x)
    {
        cout << x << endl;
    })
    

    return 0;
}
