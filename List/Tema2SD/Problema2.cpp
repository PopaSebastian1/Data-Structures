#include <iostream>
#include<forward_list>
#include <fstream>
#include <algorithm>
#include <vector>
void citire(std::vector<float>&numere, int &lungime)
{
	std::ifstream fin("Problema2.txt");
	float x;
	fin >> lungime;
	for (int i = 0; i < lungime; i++)
	{
		fin >> x;
		numere.push_back(x);
	}
}
std::vector<float> BucketSort(std::vector<float>&numere)
{

	std::vector < std::forward_list<float>>bucket(numere.size());
	for (int i = 0; i < numere.size(); i++)
	{
		int bi = numere[i]*numere.size();
		bucket[bi].push_front(numere[i]);
 }
	for (int i = 0; i < numere.size(); i++)
	{
		bucket[i].sort();
	}
	std::vector<float>altvector;
	int index = 0;
	for (int i = 0; i < numere.size(); i++)
		for (float x : bucket[i])
		{
			altvector.push_back(x);
		}
	return altvector;

}
int main()
{
	std::vector<float>numere;
	int lungime;
	citire(numere, lungime);
	numere=BucketSort(numere);
	for (int i = 0; i < lungime; i++)
		std::cout << numere[i] << " ";


}