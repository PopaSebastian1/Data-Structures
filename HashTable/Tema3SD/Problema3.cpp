#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <unordered_map>
void citire(std::string &s, std::unordered_map<char, int>&aparitii)
{
	std::ifstream fin("Problema3.txt");
	std::getline(fin, s);
	for (int i = 0; i < s.size(); i++)
	{
		aparitii[s[i]]++;
	}
}
	std::list<char> palindrom(std::unordered_map<char, int>aparitii)
{
	int i = 0;
	int numar_ap_impare = 0, caractere = 0;
	std::list<char> pali;
	for (auto it : aparitii)
	{
		if (it.second % 2 == 1) {
			numar_ap_impare++;
			while (it.second > 0)
			{
				pali.push_back(it.first);
				it.second--;
			}
		}
	}
	
	if (numar_ap_impare > 1) {
		pali.clear();
		return pali;
	}
	else
	{
		for (auto it : aparitii)
		{
			while (it.second % 2 == 0&&it.second>0)
			{
				pali.push_back(it.first);
				pali.push_front(it.first);
				it.second -= 2;
			}
		}
	}
	return pali;

 }



int main()
{
	std::string s;
	std::list<char> pal;
	std::unordered_map<char,int> aparitii;
	citire(s, aparitii);
	/*for (auto it : aparitii)
	{
		std::cout << it.second << " " << it.first;
	}*/
	pal = palindrom(aparitii);
	for (auto it : pal)
	{
		std::cout << it;
	}
	



}
