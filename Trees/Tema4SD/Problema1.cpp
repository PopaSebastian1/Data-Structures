#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>


struct Node{

	char val;
	Node* stanga;
	Node* dreapta;
	Node* parinte;
	Node(char val)
	{
		this->val = val;
		stanga = nullptr;
		dreapta = nullptr;
		//parinte = nullptr;
	}
};
class Tree {
public:
	Node* radacina;
	int prec(char c)
	{
		if (c == '(' || c == ')') return 0;
		else if (c == '+' || c == '-') return 1;
		else if (c == '*' || c == '%') return 2;
		else if (c == '^') return 3;
	//	else if (c < '0' || c>'9'||) return 4;
	}
	void FormaPoloneza(std::vector<char>& FP, std::stack<char>OP, std::string s)
	{
		int numere = 0, operatori = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ' || s[i] == '\t') continue;
			else if ((s[i] > '0' && s[i] <= '9')||(s[i]>='a'&&s[i]<='z')) {
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
		}
		while (OP.size() != 0)
		{
			FP.push_back(OP.top());
			OP.pop();
		}
	}
	
	Node* Rezultat(std::vector<char>FP)
	{
		//Node* ultim_parinte = nullptr;
		std::stack<Node*>numere;
	
			for (int i=0;i<FP.size();i++)
			{
				Node* nod;
				if (FP[i] == '+' || FP[i] == '-' || FP[i] == '*' || FP[i] == '/')
				{
					Node* x = numere.top();
					numere.pop();
					Node* y = numere.top();
					numere.pop();
					nod = new Node(FP[i]);
					nod->stanga = x;
					nod->dreapta = y;
					x->parinte = nod;
					y->parinte = nod;
				}
				else {
					nod = new Node(FP[i]);
				}
				numere.push(nod);
			}
			return numere.top();
	}
	void parcurgere_niveluri()
	{
		std::queue<Node*>c;
		c.push(radacina);
		while (!c.empty())
		{
			Node* elem = c.front();
			c.pop();
			std::cout << elem->val << "\n";
			if (elem->stanga != nullptr)
				c.push(elem->dreapta);
			if (elem->dreapta != nullptr)
				c.push(elem->stanga);
		}
	}
	void print_tree(Node* root, int space = 0, int height = 10)
	{
		if (root == nullptr)
		{
			return;
		}
		space += height;
		print_tree(root->stanga, space);
		std::cout << std::endl;
		for (int i = height; i < space; i++)
		{
			std::cout << " ";
		}
		std::cout << root->val << std::endl;
		print_tree(root->dreapta, space);
	}
};
int main()
{
	Tree a;
	std::string s;
	std::vector<char>FP;
	std::stack<char>OP;
	std::getline(std::cin, s);
	a.FormaPoloneza(FP, OP, s);
	//for (int i = 0; i < FP.size(); i++)
	//{
	//	std::cout << FP[i];
	//}
	a.radacina= a.Rezultat(FP);
	a.print_tree(a.radacina, 0, 10);
	//a.parcurgere_niveluri();
}