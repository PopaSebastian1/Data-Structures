#include <iostream>
#include <vector>
class priority_queue {

private:
	std::vector<int>data;
public:
	void insert(int val)
	{
		data.push_back(val);
		increase_key(data.size()-1, val);
	}
	void increase_key(int i, int val)
	{
		int p;
		if (val >= data[i])
		{
			data[i] = val;
			p = (i - 1) / 2;
			while (i > 0 && data[p] < val)
			{
				data[i] = data[p];
				i = p;
				p = (i - 1) / 2;
			}
			data[i] = val;
		}
	}
	void max_heapfy(int i)
	{
		int st = 2 * i + 1;
		int dr = 2 * i + 2;
		int imax = i;
		if (st<data.size() && data[st]>data[imax])
			imax = st;
		if (dr<data.size() && data[dr]>data[imax])
			imax = dr;
		if (imax != i)
		{
			std::swap(data[i], data[imax]);
			max_heapfy(imax);
		}
	}
	int priority_max()
	{
		if (data.size() == 0) std::cout << "Nu se poate";
		else
		{
		return data[0];
		}
	}
	void extract_max()
	{
		if (data.size() <0) std::cout << "Nu se poate";
		else {
			data[0] = data.back();
			data.pop_back();
			max_heapfy(0);
		}
	}
	bool empty() {
		return data.empty();
	}
	void print()
	{	
		for (int i = 0; i <= data.size() - 1; i++)
			std::cout << data[i] << " ";
	}
};
void print(priority_queue A) {
	while (!A.empty()) {
		std::cout << A.priority_max()<< " ";
		A.extract_max();
	}
	std::cout << std::endl;
}

int main()
{
	priority_queue A;
	std::cout << "1.Insert\n" << "2.Elementul maxim\n" << "3.Extragerea elem de prioritate max\n" << "4.Afisare\n" << "5.Iesire";
	int optiune;
	do {
		std::cin >> optiune;
		switch (optiune)
		{
		case 1:
			std::cout << "Inserati un element:";
			int element;
			std::cin >> element;
			A.insert(element);
			break;

		case 2:
			std::cout << " Elementul maxim este:";
			std::cout<<A.priority_max();
			break;
		case 3:
			std::cout << "Elemetnul de prioritate maxima a fost extras";
			A.extract_max();
			break;
		case 4:
			print(A);
			break;
		case 5:
			std::cout << "Ati ales optiunea de iesire";
			break;
		default:
			 std::cout << "Optiunea trebuie sa fie intre 1-5";
			 break;
		}
	} while (optiune != 5);
}