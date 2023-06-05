#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
int N, num;
string cmd;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int temp;
	for(int i = 0; i < N; i++)
	{
		cin >> cmd;
        // push 연산 수행
		if(!cmd.compare("push"))
		{
			cin >> num;
			q.push(num);
		}
        // pop 연산 수행
		else if(!cmd.compare("pop"))
		{
			if(!(q.empty()))
			{
				temp = q.front();
				q.pop();
				cout << temp << "\n";
			}
            // pop 할 데이터가 없을 때 -1 출력
			else
			{
				cout << "-1\n";
			}
		}
        // size 연산 수행
        else if(!cmd.compare("size"))
		{
			cout << q.size() << "\n";
		}
        // empty 연산 수행
        else if(!cmd.compare("empty"))
		{
			cout << q.empty() << "\n";
		}
        // front 연산 수행
        else if(!cmd.compare("front"))
		{
			if(!(q.empty()))
			{
				cout << q.front() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
        // back 연산 수행
        else if(!cmd.compare("back"))
		{
			if(!(q.empty()))
			{
				cout << q.back() << "\n";
			}
            // back 할 데이터가 없을 때 -1 출력
			else
			{
				cout << "-1\n";
			}
		}
	}
	return 0;
}