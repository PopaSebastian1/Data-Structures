#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<char> q1, q2;
    int size;

public:
    Stack()
    {
        size = 0;
    }
    void push(char x)
    {
        size++;
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<char> q = q1;
        q1 = q2;
        q2 = q;
    }
    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        size--;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int get_size()
    {
        return size;
    }
};
int grad(char s)
{
    if (s == '(' || s == ')') return 1;
    else if (s == '[' || s == ']') return 2;
    else if (s == '{' || s == '}') return 3;
}
bool Corecta(std::string s, Stack stack)
{
    if (s.size() % 2 == 1) return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            if (stack.get_size() != 0)
            {
                if (grad(stack.top()) < grad(s[i])) return false;
            }
            stack.push(s[i]);

        }
        else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if (grad(s[i]) != grad(stack.top())) return false;
            stack.pop();

        }
    }
    if (stack.get_size()!= 0) return false;
    return true;
}
int main()
{
    Stack stack;
    std::string s;
    std::cin >> s;
    if (Corecta(s, stack) == true) std::cout << "Corecta";
    else std::cout << "Gresita";
    return 0;
}