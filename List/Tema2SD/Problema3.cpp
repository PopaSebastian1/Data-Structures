#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Queue {

	struct Node
	{
		std::string nume;
		Node* prev;
		Node* next;
		Node(std::string nume)
		{
			this->nume = nume;
			next = nullptr;
			prev = nullptr;
		}
	};

	Node* first = nullptr;
	Node* last = nullptr;
	int length = 0;
public:
	void push_back(std::string nume)
	{
		Node* elem = new Node(nume);
		elem->prev = last;
		elem->next = nullptr;
		if (length > 0)
		{
			last->next = elem;
		}
		if (last == nullptr)
		{
			first = elem;
		}
		last = elem;
		length++;
	}
	void pop_front()
	{
		Node* elem = first;
		if (length == 0)
		{
			return;
		}
		else
		{
			first = elem->next;

		}
		if (elem->next != nullptr)
		{
			elem->next->prev = elem->prev;
		}
		delete elem;
		length--;

	}
	Node* getfirst()
	{
		return first;
	}
	Node* getLast()
	{
		return last;
	}
	void empty()
	{
		if (length == 0) std::cout << "Este vida";
		else std::cout << "Nu este";
	}
	void clear()
	{
		Node* elem = first;
		while (elem != nullptr)
		{
			Node* x = elem;
			elem = elem->next;
			delete x;
			length--;
		}
		first = nullptr;
		last = nullptr;

	}
	int getSize()
	{
		return length;
	}
	void print()
	{
		std::ofstream fout("Problema3.txt",std::ofstream::app);
		Node* elem = first;
		if (length == 0) fout << "Nu mai exista candidati";
		else {
			while (elem != NULL)
			{
				fout << elem->nume << std::endl;
				elem = elem->next;
			}
		}
		fout.close();
	}
};
void citire(Queue& Coada, int& n, int& x, std::vector<int>&timp)
{
	srand(time(NULL));
	std::ifstream fin("Problema3.in");
	std::string s;
	fin >> x;
	fin >> n;
	while (!fin.eof())
	{
		int k = rand() % 11 + 5;
		timp.push_back(k);
		std::getline(fin, s);
		Coada.push_back(s);
	}
	fin.close();
}
void EleviRamasi(Queue&Coada, std::vector<int>&timp,int x,int n)
{
	int i = 0;
	x = x * 60;
	while (i<timp.size())
	{
		while (x - timp[i] > 0) {
			Coada.pop_front();
			x = x - timp[i];
		}
		i++;
	}
}
int main()
{
	Queue coada;
	std::vector<int>Timp;
	srand(time(NULL));
	std::string s;
	int n, x;
	citire(coada, n,x,Timp);
	EleviRamasi(coada, Timp, x,n);
	coada.print();
}