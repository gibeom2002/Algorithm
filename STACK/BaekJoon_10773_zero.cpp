#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int get_sum();
int main()
{
    int n, val;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        if(val != 0)
        {
            s.push(val);
        }
        else
        {
            s.pop();
        }
    }
    cout << get_sum() << "\n";
    return 0;
}
int get_sum()
{
    int res = 0;
    while(!s.empty())
    {
        res += s.top();
        s.pop();
    }
    return res;
}