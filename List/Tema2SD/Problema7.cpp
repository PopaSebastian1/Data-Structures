#include <iostream>
#include <string>
#include <stack>
#include <vector>
int prec(char c)
{
	if (c == '(' || c == ')') return 0;
	else if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '%') return 2;
	else if (c == '^') return 3;
	else if (c < '0' || c>'9') return 4;
}
double calcul(char c, double x, double y)
{
	switch (c)
	{
	case '+':
		return x + y;
		break;
	case '*':
		return x * y;
		break;
	case '-':
		return x - y;
		break;
	case '%':
		return x / y;
		break;
	case '^':
		return pow(x, y);
		break;
	default:
		break;
	}
}
void FormaPoloneza(std::vector<char>&FP, std::stack<char>OP, std::string s)
{
	int numere = 0, operatori = 0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i] == ' ' || s[i]=='\t') continue;	
		else if ((s[i] > '0' && s[i] <='9')||(s[i]>='a'&&s[i]<='z')) {
			FP.push_back(s[i]);
			numere++;
		}
		else if (s[i] == '(') OP.push(s[i]);
		else if (s[i] == ')')
		{
			while (OP.size() != 0 && OP.top() != '(')
			{
				FP.push_back(OP.top());
				OP.pop();
			}
			if (OP.size() == 0) {
				std::cout << "Parantezare gresita";
				exit(1);
			}
			else OP.pop();
		}
		else
		{
			while (OP.size() != 0 && prec(s[i]) <= prec(OP.top()))
			{   
				FP.push_back(OP.top());
				OP.pop();
			}
			OP.push(s[i]);
		}
		
		if (s[i] == '+' || s[i] == '*' || s[i] == '%' || s[i] == '^' || s[i] == '-') operatori++;
		/*if (prec(s[i]) == 4) {
			std::cout << "Caracter nepermis";
			exit(1);
		}*/
		}
		/*if (operatori >= numere) {
			std::cout << "Prea multi operatori";
			exit(1);
		}*/
	while (OP.size() != 0)
	{
		FP.push_back(OP.top());
		OP.pop();
	}
}
double Rezultat(std::vector<char>FP)
{
	std::stack<double>numere;
	double rezultat = 0;
	double x, y;
	for (int i = 0; i < FP.size(); i++)
	{
		if (FP[i] > '0' && FP[i] <='9')
		{
			numere.push(FP[i] - '0');
		}
		else
		{
			y = numere.top();
			numere.pop();
			x = numere.top();
			numere.pop();
			rezultat = calcul(FP[i], x, y);
			numere.push(rezultat);
		}
	}
	return numere.top();
}
void afisare(std::vector<char>FP)
{
	for (int i = 0; i < FP.size(); i++)
	{
		std::cout << FP[i];
	}
}
int main()
{
	std::vector<char>FP;
	std::stack<char>OP;
	std::string s;
	std::getline(std::cin, s);
	FormaPoloneza(FP, OP, s);
//	std::cout << Rezultat(FP) << std::endl;
	afisare(FP);
}