#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
//struct comparator
//{
//	bool operator()(const Node* a, const Node* b) const
//	{
//	   a->frecv
//	}
//}
std::unordered_map<char,int> frecventa(std::string s)
{
	std::unordered_map<char, int>frecv;
	for (int i = 0; i < s.size(); i++)
	{
		frecv[s[i]]++;
	}
	return frecv;
}
struct Node
{
	char valoare;
	int frecv;
	Node* stanga;
	Node* dreapta;
	Node* parinte;
	Node(char valoare, int frecv)
	{
		this->valoare = valoare;
		this->frecv = frecv;
		stanga = dreapta = parinte = nullptr;
	}
};
struct comparator
{
	bool operator()(const Node* a, const Node* b) const
	{
		return a->frecv > b->frecv;
	}
};
class Cod
{
	//std::string s;
public:
	Node* root;
	std::unordered_map<char, int>frecv;
	std::unordered_map<char, std::string>coduri;
	void set_frecv(std::string s)
	{
		frecv = frecventa(s);
	}
	std::priority_queue<Node*, std::vector<Node*>, comparator> creare_pq()
	{
		std::priority_queue<Node*, std::vector<Node*>, comparator>queue;
		for (auto it : frecv)
		{
			Node* elem = new Node(it.first, it.second);
			queue.push(elem);
		}
		return queue;
	}
	void creare()
	{
		std::priority_queue<Node*, std::vector<Node*>, comparator>queue = creare_pq();
		while (queue.size() > 1)
		{
			Node* stanga = queue.top();
			queue.pop();
			Node* dreapta = queue.top();
			queue.pop();
			Node* parinte = new Node(' ', stanga->frecv + dreapta->frecv);
			parinte->stanga = stanga;
			parinte->dreapta = dreapta;
			stanga->parinte = parinte;
			dreapta->parinte = parinte;
			queue.push(parinte);
		}
		root = queue.top();
	}
	void codurile ()
	{
		std::queue<Node*>q;
		q.push(root);
		while (!q.empty())
		{
			Node* elem = q.front();
			q.pop();
			if (elem->dreapta != nullptr)
			{
				q.push(elem->dreapta);
			}
			if (elem->stanga != nullptr)
			{
				q.push(elem->stanga);
			}
			if (elem->stanga == nullptr && elem->dreapta == nullptr)
			{
				Node* aux = elem;
				std::string cod;
				while (aux->parinte != nullptr)
				{
					if (aux->parinte->dreapta == aux)
					{
						cod = '1' + cod;
					}
					if (aux->parinte->stanga == aux)
					{
						cod = '0' + cod;
					}
					aux = aux->parinte;
				}
				coduri[elem->valoare] = cod;
			}
		}
	}
	void afisare_coduri()
	{
		for (auto it : coduri)
		{
			std::cout << it.first << " " << it.second << std::endl;
		}
	}
	void text(std::string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			std::cout << coduri[s[i]];
		}
		std::cout << std::endl;
	}
};
int main()
{
	std::string expresie;
	std::getline(std::cin, expresie);
	Cod H;
	H.set_frecv(expresie);
	H.creare();
	H.codurile();
	H.afisare_coduri();
	H.text(expresie);
}