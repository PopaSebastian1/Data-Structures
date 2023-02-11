#include <iostream>
#include <queue>
#include <vector>

struct Node
{
	int data;
	Node* stanga;
	Node* dreapta;
	Node* parinte;
	Node(int data)
	{
		this->data = data;
		stanga = nullptr;
		dreapta = nullptr;
		parinte = nullptr;
	}
};
class BSTree {
	Node* root = nullptr;
public:
	Node* get_root()
	{
		return root;
	}
	void insert(int key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return;
		}
		Node* aux = root;
		while (aux != nullptr)
		{
			if (key == aux->data) return;
			if (aux->data <key)
			{
				if (aux->dreapta == nullptr)
				{
					aux->dreapta = new Node(key);
					aux->dreapta->parinte = aux;
					return;
				}
				aux = aux->dreapta;
			}
			if (aux->data> key)
			{
				if (aux->stanga == nullptr)
				{
					aux->stanga = new Node(key);
					aux->stanga->parinte = aux;
					return;
				}
				aux = aux->stanga;
			}
		}

	}
	Node* find(int key)
	{
		if (root == nullptr) return nullptr;
		Node* aux = root;
		while (aux != nullptr)
		{
			if (key == aux->data) return aux;
			if (aux->data > key) aux=aux->stanga;
			if (aux->data < key) aux = aux->dreapta;
		}
		return nullptr;
	}
	Node* maxim(Node* x)
	{
		if (x == nullptr) return nullptr;
		while (x->dreapta != nullptr) x = x->dreapta;
		return x;
	}
	Node* minim(Node* x)
	{
		if (x == nullptr) return nullptr;
		while (x->stanga != nullptr) x = x->stanga;
		return x;
	}
	Node* succesor(Node* x)
	{
		Node* y;
		if (x->dreapta != nullptr) return minim(x->dreapta);
			y = x->parinte;
			while (y != nullptr && x == y->dreapta)
			{
				x = y;
				y = y->parinte;
			}
		return y;
	}
	Node* predecesor(Node* x)
	{
		Node* y;
		if (x->stanga != nullptr) return maxim(x ->stanga);
		y = x->parinte;
		while (y != nullptr && x == y->stanga)
		{
			x = y;
			y = y->parinte;
		}
		return y;

	}
	void transplant(Node* z, Node* y)
	{
		if (z->parinte == nullptr) root = y;
		else if (z == z->parinte->stanga) z->parinte->stanga = y;
		else z->parinte->dreapta = y;
		if (y != nullptr) y->parinte = z->parinte;
	
	}
	void remove(int key)
	{
		Node* aux = find(key);
		if (aux == nullptr) return;
		if (aux->stanga == nullptr)
		{
			transplant(aux, aux->dreapta);
		}
		else if (aux->dreapta == nullptr)
			transplant(aux, aux->stanga);
		else {
			Node* succ = succesor(aux);
			if (succ != aux->dreapta)
			{
				transplant(succ, succ->dreapta);
				succ->dreapta = aux->dreapta;
				aux->dreapta->parinte = succ;
			}
			transplant(aux, succ);
			succ->stanga = aux->stanga;
			aux->stanga->parinte = succ;
		}
	}
	void erase(Node* aux)
	{

		if (aux == nullptr) return;
		if (aux->stanga == nullptr)
		{
			transplant(aux, aux->dreapta);
		}
		else if (aux->dreapta == nullptr)
			transplant(aux, aux->stanga);
		else {
			Node* succ = succesor(aux);
			if (succ != aux->dreapta)
			{
				transplant(succ, succ->dreapta);
				succ->dreapta = aux->dreapta;
				aux->dreapta->parinte = succ;
			}
			transplant(aux, succ);
			succ->stanga = aux->stanga;
			aux->stanga->parinte = succ;
		}
		delete aux;

	}
	void clear()
	{
		std::queue<Node*>q;
		if (root == nullptr) return;
		q.push(root);
		while (q.size() > 0)
		{
			Node* aux = q.front();
			q.pop();
			if (aux->stanga != nullptr) q.push(aux->stanga);
			if (aux->dreapta != nullptr) q.push(aux->dreapta);
			delete aux;
		}
		root = nullptr;
	}
	bool empty()
	{
		if (root == nullptr) return true;
		return false;
	}
	void construct(std::vector<int>numere)
	{
		for (int i = 0; i < numere.size(); i++)
		{
			insert(numere[i]);
		}
	}
	void print_preorder(Node* node) {
		if (node == nullptr) return;
		std::cout << node->data << " ";
		print_preorder(node->stanga);
		print_preorder(node->dreapta);

	}
	void print_inorder(Node* nod)
	{
		if (nod == nullptr)
		{
			return;
		}
		print_inorder(nod->stanga);
		std::cout << nod->data << " ";
		print_inorder(nod->dreapta);
	}
	void print_postorder(Node* nod)
	{
		if (nod == nullptr)
		{
			return;
		}
		print_postorder(nod->stanga);
		print_postorder(nod->dreapta);
		std::cout << nod->data << " ";
	}
	void print_pe_niveluri()
	{
		Node* parinte;
		std::queue<Node*>coada;
		coada.push(root);
		while (coada.size() != 0)
		{
			std::cout << coada.front()->data << " ";
			if (coada.front()->stanga != nullptr)
			{
				coada.push(coada.front()->stanga);
			}
			if (coada.front()->dreapta != nullptr)
			{
				coada.push(coada.front()->dreapta);
			}
			coada.pop();
		}
	}

	void print_tree(Node* root, int space = 0, int height = 10)
	{
		if (root == nullptr)
		{
			return;
		}
		space += height;
		print_tree(root->dreapta, space);
		std::cout << std::endl;
		for (int i = height; i < space; i++)
		{
			std::cout << " ";
		}
		std::cout << root->data << std::endl;
		print_tree(root->stanga, space);
	}
};
int main()
{
	BSTree A;
	Node* aux;
	int x;
	std::vector<int>numere;
	for (int i = 0; i < numere.size(); i++)
	{
		A.insert(numere[i]);
	}
	std::cout << "1.Insert Element \n" << "2.Insert Multiple Elements\n" << "3.Element Maxim\n"<<"4.Succesor\n"<<"5.Predecesor\n" <<"6.Eliminare element(Delete)\n"<<
	"7.Eliminare element(Erase)\n" <<"8.Empty\n"<<"9.Clear\n"<<"10.Print\n"<<"11.Iesire" << "\n";
	int element;
	int optiune;
	do {
		std::cin >> optiune;
		switch (optiune)
		{
		case 1:
			std::cout << "Alegeti elementul pe care vreti sa-l introduceti:\n";
			std::cin >> x;
			A.insert(x);
			break;
		case 2:
			std::cout << "Da-ti dimensiunea vectorului:\n";
			int n;
			std::cin >> n;
			std::cout << "Introduceti elementele\n";
			for (int i = 0; i < n; i++)
			{
				std::cin >> x;
				numere.push_back(x);
			}
			A.construct(numere);
			break;
		case 3:
			std::cout << "Da-ti radacina subarborelui\n";
			std::cin >> element;
			std::cout << "Elementul maxim\n";
			std::cout << A.maxim(A.find(element))->data;
			break;
		case 4:
			std::cout << "Da-ti elementul:\n";
			std::cin >> element;
			if(A.succesor(A.find(element))==nullptr) std::cout<<"Nu exista";
			else {
				std::cout << "Succesorul lui " << element << " este " << A.succesor(A.find(element))->data;
			}
			break;
		case 5:		
			std::cout << "Da-ti elementul:\n";
			std::cin >> element;
			if (A.predecesor(A.find(element)) == nullptr) std::cout << "Nu exista";
			else {
				std::cout << "Predecesorul lui " << element << " este " << A.predecesor(A.find(element))->data;
			}
			break;
		case 6:
			std::cout << "Da-ti elementul pe care doriti sa-l stergeti\n";
			std::cin >> element;
			A.remove(element);
			break;
		case 7:
			std::cout << "Da-ti elementul pe care doriti sa-l stergeti\n";
			std::cin >> element;
			aux = A.find(element);
			A.erase(aux);
			break;
		case 8:
			if (A.empty() == true) std::cout << "Gol";
			else std::cout << "Nu este gol";
			break;
		case 9:
			A.clear();
			break;
		case 10:
			std::cout << "Alegeti optiunea:\n"; 
			int afisare;
			std::cout << "1.Inorder\t" << "2.Preorder\t" << "3.Postorder\t" << "4.Niveluri\t" << "5.Arbore\n";
			std::cin >> afisare;
			if (afisare == 1)
			{
				A.print_inorder(A.get_root());
			}
			if (afisare == 2)
			{
				A.print_preorder(A.get_root());
			}
			if (afisare == 3)
			{
				A.print_postorder(A.get_root());
			}
			if (afisare == 4)
			{
				A.print_pe_niveluri();
			}
			if (afisare == 5)
			{
				A.print_tree(A.get_root(), 0, 10);
			}
			break;
		case 11:
			std::cout << "Ati ales sa iesiti";
			break;
		default:
			std::cout << "Optiunea trebuie sa fie intre 1-12";
			break;
		}
	} while (optiune != 11);



}