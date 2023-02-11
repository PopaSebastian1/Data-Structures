#include <iostream>
#include <map>
#include <string>
#include <fstream>
void citire(std::map<std::string, int>&frecventa)
{
	std::ifstream fin("Problema7.txt");
	std::string s;
	std::getline(fin, s);
	std::string x = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = tolower(s[i]);
			x = x + s[i];
		}
		else if (s[i] == ' ')
		{
			frecventa[x]++;
			x = "";
		}
		if (i == s.size()-1)
		{
			frecventa[x]++;
		}
	}
}
void afisare(std::map<std::string, int>frecventa)
{
	for (auto it : frecventa)
	{
		std::cout << it.first << " " << it.second;
		std::cout << std::endl;
	}
}
int main()
{
	std::map<std::string, int>frecventa;
	citire(frecventa);
	afisare(frecventa);



}