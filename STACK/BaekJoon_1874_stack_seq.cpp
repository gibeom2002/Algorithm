/*
    문제 설명 : 1~N-1 까지의 수를 스택연산을 통하여 입력된 수열을 만들수 있는가?
    ex) 1 4 3 2
    push 1
    pop 1
    push 2
    push 3
    push 4
    pop 4
    pop 3
    pop 2
    를 하면 1 4 3 2를 만들 수 있음
*/
#include <iostream>
#include <vector>
#include <stack>
#define MAX_SIZE 100000
using namespace std;

stack<int> s;
vector<char> v;
int seq[MAX_SIZE];

void get_answer(int end);
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}
	get_answer(n);
	return 0;
}
void get_answer(int end)
{
	int temp = 1, idx = 0;
	s.push(temp++);
	v.push_back('+');
	while(idx < end)
	{
		// 스택에 push를 지정 값 이상으로 했다 -> 불가능
		if(temp > end + 1)
		{
			cout << "NO\n";
			return;
		}
		// 스택의 top이 입력된 수열과 같다면 pop
		if(!s.empty() && s.top() == seq[idx])
		{
			s.pop();
			v.push_back('-');
			idx++;
		}
		else
		{
			s.push(temp++);
			v.push_back('+');
		}
	}
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}