#include <iostream>
#include <stack>
int grad(char s)
{
	if (s == '(' || s == ')') return 1;
	else if (s == '[' || s == ']') return 2;
	else if (s == '{' || s == '}') return 3;
}
bool Corecta(std::string s, std::stack<char>&Stack)
{
	if (s.size() % 2 == 1) return false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
		{
			if (Stack.size() != 0)
			{
				if (grad(Stack.top()) < grad(s[i])) return false;
			}
			Stack.push(s[i]);
			
		}
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
		{
			if (grad(s[i]) != grad(Stack.top())) return false;
			Stack.pop();
			
		}
	}
	if (Stack.size() != 0) return false;
	return true;
}

int main()
{
	std::string s;
	std::cin >> s;
	std::stack<char>Stack;
	if (Corecta(s, Stack)==true) std::cout << "Corecta";
	else std::cout << "Gresita";


}