#include <fstream>
#include<vector>
#include <iostream>
#include <unordered_map>
void citire(std::vector<int>&numere)
{
	int numar;
	std::ifstream fin("Problema6.txt");
	while (fin>>numar)
	{
		numere.push_back(numar);
	}
}
bool verificare(std::vector<int>numere, int distanta)
{
	std::unordered_map<int, int>duplicate;
	int numere_duplicate = 0;
	for (int i = numere.size()-1; i>=0; i--)
	{
		duplicate[numere[i]] = i;
	}
	for (int i = 0; i < numere.size(); i++)
	{
		if (abs(i - duplicate[numere[i]])!= 0 && abs(i - duplicate[numere[i]])<= distanta)
		{
			return true;
		}
		else if (i - duplicate[numere[i]] > distanta) duplicate[numere[i]] = i;
	}

	return false;
}
int main()
{

	int distanta;
	std::cin >> distanta;
	std::vector<int>numere;
	citire(numere);
	if (verificare(numere, distanta)) std::cout << "Da";
	else std::cout << "Nu";



}