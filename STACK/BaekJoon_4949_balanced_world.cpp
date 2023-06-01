// 알맞은 괄호가 들어온 경우 pop
// 아니라면 trash(=A)를 push 하여 
// 스택이 비었다면 균형 잡힌 문자열
// 스택에 비지 않았다면 균형 잡히지 않은 문자열을 의미

#include <iostream>
#include <stack>
#include <string>
#define SIZE 101
using namespace std;
stack<char> s;
string temp;
string input;
int main()
{
	int idx = 0;
	char trash = 'A';
	char temp;
	input = " ";
	while(true)
	{
		getline(cin, input);
        // 들어온 케이스가 '.'만 있을 경우도 균형잡힌 문자열로 취급
		if(input[0] == '.' && input.length() < 2)
		{
			break;
		}
		for(int i = 0; i < input.length(); i++)
		{
            // '(' 와 '[' 가 아닌 문자열은 push 할 필요가 없으므로
			if(input[i] == '(' || input[i] == '[')
			{
				s.push(input[i]);
			}
            // ')' 처리 부분
			else if(input[i] == ')')
			{
				if(!s.empty())
				{
                    // 최상위 값이 짝이 맞다면 pop
					if(s.top() == '(')
					{
						s.pop();
					}
                    // 아니라면 스택에 쓰레기 값을 추가
					else
					{
						s.push(trash);
					}
				}
                // pop할 값이 없다 -> 균형 잡히지 않음
				else
				{
					s.push(trash);
				}
			}
            // ']' 처리 부분
			else if(input[i] == ']')
			{
				if(!s.empty())
				{
					if(s.top() == '[')
					{
						s.pop();
					}	
					else
					{
						s.push(trash);
					}
				}
				else
				{
					s.push(trash);
				}
			}
		}
		if(s.empty())
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		while(!s.empty())
		{
			s.pop();
		}
		input = " ";
	}
	return 0;
}