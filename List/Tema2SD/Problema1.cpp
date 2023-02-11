#include <iostream>
#include <vector>

	struct Node {
		double valoare;
		Node* next;
		Node* prev;
		Node(double valoare)
		{
			this->valoare = valoare;
			next = nullptr;
			prev = nullptr;
		}
	};
class List {
public:

	Node* first=nullptr;
	Node* last = nullptr;
	int length = 0;
public:

	void push_front(double val)
	{
		Node* elem = new Node(val);
		elem->next = first;
		elem->prev = nullptr;
		if (length>0)
		{
			first->prev = elem;
		}
		if (first == nullptr) {
			last = elem;
		}
		first = elem;
		length++;
	}
	void push_back(double val)
	{
		Node* elem = new Node(val);
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
			std::cout << "Vida" << std::endl;
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
	void pop_back()
	{
		Node* elem = last;
		if (length == 0)
		{
			std::cout << "Este vida" << std::endl;
			return;
		}
		else {
			last = elem->prev;
		}
		if (elem->prev != nullptr)
		{
			elem->prev->next = elem->next;
		}
		delete elem;
		length--;

	}
	Node* find(double valoare)
	{
		Node* elem = first;
		if (first == nullptr)
		{
			return nullptr;
			std::cout << "Lista este vida";
		}
		while (elem != NULL)
		{
			if (elem->valoare == valoare) return elem;
			else elem = elem->next;
		}
		std::cout << "Elementul nu exita";
		return nullptr;
	}
	void erase(Node* elem)
	{
		if (elem == nullptr) {
			return;
			std::cout << "Nu exista";
		}
		if (elem->prev != nullptr)
		{
			elem->prev->next = elem->next;
		}
		else
		first = elem->next;
		if (elem->next != nullptr)
		{
			elem->next->prev = elem->prev;
		}
		length--;
	}
	void remove(double valoare)
	{

		Node* elem = first;
		while (elem != nullptr)
		{
			if (elem->valoare == valoare)
				erase(elem);
			elem = elem->next;
		}
	}
	void insert(Node* elem, double valoare)
	{
		Node* adaugat = new Node(valoare);
		if (elem->prev == nullptr)
		{
			elem->prev = adaugat;
			adaugat->next = elem;

	    }
		else {
			elem->prev->next = adaugat;
			elem->prev = adaugat;
			adaugat->next = elem;
			adaugat->prev = elem->prev;
		}
		length++;
	}
	int getSize()
	{
		return length;
	}
	void empty()
	{
		if (length == 0) std::cout << "Lista este vida";
	}
	void clear()
	{
		Node* elem = first;
		while (elem != nullptr)
		{
			Node* x = elem;
			elem= elem->next;
			delete x;
			length--;
		}
		first = nullptr;
		last = nullptr;
		
	}
	Node* getFirst()
	{
		return first;
	}
	Node* getNext(Node* elem)
	{
		if (elem->next == nullptr) return nullptr;
		else return elem->next;
	}
    Node* getLast()
	{
		return last;
	}
	
	void print()
	{
		Node* elem = first;
		if (length == 0) std::cout << "Este vida";
		while (elem!=NULL)
		{
			std::cout << elem->valoare << " ";
			elem = elem->next;
		}
	}
};
bool Verifpalindrom(List lista, std::vector<double>&Palindrom)
{
	Node* primul = lista.getFirst();
	
	if (lista.getSize() == 1) return true;
	while (primul!=nullptr)
	{
		Palindrom.push_back(primul->valoare);
		primul = lista.getNext(primul);
	}
	for (int i = 0; i < Palindrom.size() / 2 - 1; i++)
		for (int j = Palindrom.size() - 1; j > Palindrom.size() / 2 + 1; j--)
			if (Palindrom[i] != Palindrom[j]) return false;
	return true;

}
bool Comparare(List lista1, List lista2)
{
	Node* primul1 = lista1.getFirst();
	Node* primul2 = lista2.getFirst();
	if (lista1.getSize() != lista2.getSize()) return false;
	while (primul1 != nullptr)
	{
		if (primul1->valoare != primul2->valoare) return false;
		primul1= lista1.getNext(primul1);
		primul2= lista2.getNext(primul2);
	}
	return true;

}
int main()
{
	List lista, Compar1, Compar2, Pal;
	std::vector<double>Palindrom;
	int optiune, n, m, i, j, x;
	double valoare;
		std::cout << "Alegti optiunea dorita" << std::endl;
		std::cout << " 1:Adaugati un element la inceput" << std::endl;
		std::cout << " 2:Adaugati un element la final" << std::endl;
		std::cout << " 3:Stergeti un element de la inceput" << std::endl;
		std::cout << " 4:Stergeti un element de la final" << std::endl;
		std::cout << " 5.Afisare Lista" << std::endl;
		std::cout << " 6.Gasiti adresa unui element" << std::endl;
		std::cout << " 7.Stergeti un element" << std::endl;
		std::cout << " 8:Stergeti toate aparitile unui element" << std::endl;
		std::cout << " 9.Inserati un element" << std::endl;
		std::cout << " 10.Goliti lista" << std::endl;
		std::cout << " 11.Verificati daca este palindrom" << std::endl;
		std::cout << " 12.Comparati 2 liste " << std::endl;
		std::cout << " 13.Iesire" << std::endl;
	do {
		std::cin >> optiune;
		switch (optiune) {
		case 1:
			std::cout << " 1:Adaugati un element la inceput" << std::endl;
			std::cin >> valoare;
			lista.push_front(valoare);
			std::cout << "Elementul"<<" "<<valoare<<" "<< "a fost adaugat" << std::endl;
			break;
		case 2:
			std::cout << " 2:Adaugati un element la final" << std::endl;
			std::cin >> valoare;
			lista.push_back(valoare);
			std::cout << "Elementul" <<" "<< valoare <<" "<<"a fost adaugat" << std::endl;
			
			break;
		case 3:
			if (lista.getSize() != 0)
			{
				std::cout << " 3:Stergeti un element de la inceput" << std::endl;
				lista.pop_front();
				std::cout << std::endl;
				std::cout << "Elementul a fost sters" << std::endl;
			}
			else std::cout << "Este vida" << std::endl;
			break;
		case 4:
			if (lista.getSize() != 0)
			{
				std::cout << " 4:Stergeti un element de la final" << std::endl;
				lista.pop_back();
				std::cout << std::endl;
				std::cout << "Elementul a fost sters" << std::endl;
			}
			else std::cout << "Lista este vida" << std::endl;
			break;
		case 5:
			if (lista.getSize() == 0) {
				std::cout << "Lista este vida" << std::endl;

			}
			else {
				lista.print();
				std::cout << std::endl;
			}
			break;
		case 6:
			std::cout << " 6.Gasiti adresa unui element" << std::endl;
			std::cin >> valoare;
			std::cout << lista.find(valoare) << std::endl;
		
		case 7:
			std::cout << " 7.Stergeti un element" << std::endl;
			std::cin >> valoare;
			lista.erase(lista.find(valoare));
			break;
		case 8:
			std::cout << " 8:Stergeti toate aparitile unui element" << std::endl;
			std::cin >> valoare;
			lista.remove(valoare);
			break;
		case 9:
			std::cout << " 9.Inserati un element" << std::endl;
			double valoare2;
			std::cin >> valoare >> valoare2;
			lista.insert(lista.find(valoare), valoare2);
			break;
		case 10:
			std::cout << " 10.Goliti lista" << std::endl;
			lista.clear();
			break;
		case 11:
			std::cout << " 11.Verificati daca este palindrom" << std::endl;
			std::cout << "Numarul de elemente este:" << std::endl;
			std::cin >> n;
			if (n == 0) std::cout << "Lista Vida";
			while (n > 0)
			{
				int i;
				std::cin >> i;
				Pal.push_back(i);
				n--;
			}
				if (Verifpalindrom(Pal, Palindrom)) std::cout << "Este palindrom" << std::endl;
				else if (!Verifpalindrom(Pal, Palindrom)) std::cout << "Nu este" << std::endl;
			break;
		case 12:
			std::cout << " 12.Comparati 2 liste " << std::endl;
			std::cout << "Numarul de elemente al primei liste este" << std::endl;
			std::cin >> m;
			while (m > 0)
			{
				std::cin >> i;
				Compar1.push_back(i);
				m--;
			}
			std::cout << " Numarul de elemente a celei de doua liste este" << std::endl;
			std::cin >> x;
			while (x > 0)
			{
				std::cin >> j;
				Compar2.push_back(j);
				x--;
			}
			if (Comparare(Compar1, Compar2)) std::cout << "Listele sunt egale" << std::endl;
			else std::cout << "Listele nu sunt egale" << std::endl;
			break;
		case 13:
		{
			std::cout << "Ati ales optiune de iesire" << std::endl;
			break;
		}
		default:
			std::cout << "Optiunea aleasa trebuie sa fie in intervalul 1-13";
			break;	
		}
	} while (optiune != 13);
	return 0;

}