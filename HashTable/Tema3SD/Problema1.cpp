#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

class HashTable {

	std::list < std::pair < std::string, std::string >> * table;
	int length;
	int numar_elemente;
public:
	HashTable(int length,int numar_elemente)
	{
		this->numar_elemente = numar_elemente;
		this->length = length;
		table = new std::list<std::pair<std::string,std::string>>[length];
	}
	unsigned int fnv_hash(std::string key)
	{
		unsigned long long h = 2166136261;
		for (int i = 0; i < key.size(); i++)
		{
			h = (h * 16777618) ^ key[i];
		}
		return h % length;
	}
	void rehash()
	{
		length = length * 2;
		std::list<std::pair<std::string,std::string>>* new_table = new std::list<std::pair<std::string, std::string>>[length];
		for (int i = 0; i < length/2; i++)
		{
			for (auto it : table[i])
			{
				new_table[fnv_hash(it.first)].push_back(it);
			}
		}
		delete[] table;
		table = new_table;
	}
	std::pair < std::string, std::string> *find(std::string key)
	{
		int index = fnv_hash(key);
		for (auto &it : table[index])
		{
			if (it.first == key)
			{

				//std::cout << "Gasit " << s.second << " la adresa " << index << std::endl;
				return &it;
			}
			
		}
		return nullptr;
	}
	void stergere(std::string key)
	{
		for (int i = 0; i < length; i++)
		{
			for (auto it : table[i])
			{
				if (it.first== key)
				{
					table[i].remove(it);
					numar_elemente--;
					return;
				}
			}
		}


	}
	void insert(std::pair <std::string, std::string>s)
	{
		if (find(s.first) == nullptr) {
			int index = fnv_hash(s.first);
			table[index].push_back(s);
			numar_elemente++;
		}
		if(numar_elemente>length) rehash();
	}
	std::string &operator [](std::string key)
	{
		std::pair<std::string, std::string>* pair = find(key);
		if (pair == nullptr)
		{
			insert(std::make_pair(key, ""));
			pair = find(key);
		}
		return pair->second;
	}
	void print()
	{

		for (int i = 0; i < length; i++)
		{
			std::cout << i << " ";
			for (auto it : table[i])
			{
				std::cout << "-->" << it.second;
			}
			std::cout<<std::endl;
		}
	}
};
void citire(HashTable& Tabel, int& n)
{
	std::ifstream fin("Problema1.txt");
	fin >> n;
	fin.get();
	for (int i = 0; i < n; i++)	
	{
		std::string key, value;
		fin >> key >> value;
		Tabel.insert(std::make_pair(key, value));
	}
	fin.close();
}
int main()
{
	int n;
	HashTable M(10,0);
	citire(M, n);
	//std::cout << M["Rahim"] << std::endl;
	int optiune;
	std::cout << "Alegeti optiunea dorita" << std::endl;
	std::cout << "1.Insert" << std::endl;
	std::cout << "2.Find" << std::endl;
	std::cout << "3.Remove" << std::endl;
	std::cout << "4.Print" << std::endl;
	std::cout << "5.Iesire" << std::endl;
	do {
		std::cin >> optiune;
		switch (optiune)
		{
		case 1:
		{
			std::string key, value;
			std::cout << "Alegeti cheia pe care doriti sa o introduceti \n";
			std::cin >> key;
			std::cout << "Alegeti valoarea pe care doriti sa o introduceti \n";
			std::cin >> value;
			M.insert(std::make_pair(key, value));
			break;
		}
		case 2:
		{			std::string key;
		std::cout << "Alegeti cheia pe care doriti sa o cautati \n";
		std::cin >> key;
		if (M.find(key) != nullptr) std::cout << "gasita";
		else std::cout << "Nu exista";
		break;
		}

		case 3:
		{
			std::string key;
			std::cout << "Alegeti cheia pe care doriti sa o stergeti \n";
			std::cin >> key;
			M.stergere(key);
			break;
		}
		case 4:
		{
			M.print();
			break;
		}
		case 5:
		{
			std::cout << "Ati ales optiunea de iesire";
			break;
		}
		default:
		{
			std::cout << "Optiunea trebuie sa fie intre 1-5";
		}

		}


	} while (optiune != 5);
	
	return 0;
}