#include <iostream>
#include <string.h>
#include <stack>
#include <string>

using namespace std;
stack<int> s;

int main(void)
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        // 들어온 명령어가 push 일 경우 처리
        if (!str.compare("push"))
        {
            int a;
            cin >> a;
            s.push(a);
        }
        // 들어온 명령어가 top 일 경우 처리
        else if (!str.compare("top"))
        {
            if (s.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s.top() << "\n";
            }
        }
        // 들어온 명령어가 pop 일 경우 처리
        else if (!str.compare("pop"))
        {
            if (s.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        // 들어온 명령어가 size 일 경우 처리
        else if (!str.compare("size"))
        {
            cout << s.size() << "\n";
        }
        // 들어온 명령어가 empty 일 경우 처리
        else if (!str.compare("empty"))
        {
            cout << s.empty() << "\n";
        }
    }
    return 0;
}