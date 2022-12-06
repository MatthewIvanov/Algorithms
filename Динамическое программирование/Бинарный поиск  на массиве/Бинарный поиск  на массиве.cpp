
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
struct Node
{
	int Data; //Поле данных
	int index;
	Node* Left; //УКАЗАТЕЛИ на соседние веточки
	Node* Right;
	Node* parent;
};
void Add(Node* val, Node* aNode)
{
	if (aNode->Data < val->Data) {
		if (aNode->Right == nullptr) {
			aNode->Right = val;
			val->parent = aNode;
		}
		else Add(val, aNode->Right);
	}
	else if (aNode->Data > val->Data)
	{
		if (aNode->Left == nullptr) {
			aNode->Left = val;
			val->parent = aNode;
		}

		else
		{
			Add(val, aNode->Left);
		}
	}
	else {
		return;
	}

};
Node* newNode(int value) {
	Node* obj = new Node;
	obj->Data = value;
	obj->Left = nullptr;
	obj->Right = nullptr;
	obj->index = 0;
	obj->parent = nullptr;
	return obj;
}
Node* search(Node* x, int k) {
	if (x == nullptr) {
		return x;
	}
	if (k == x->Data)
		return x;
	if (k < x->Data) {
		return search(x->Left, k);
	}
	else
		return search(x->Right, k);
}
Node* searchR(Node* x, int k) {
	if (x->Data > k && x->Left!=nullptr &&x->Left->Data > k)
		return searchR(x->Left, k);
	if (x->Data > k && x->Left!= nullptr && x->Left->Data < k)
		return x;
	if (x->Data > k && x->Left == nullptr) 
		return x;
	if (x->Data < k && x->Right!= nullptr && x->Right->Data>k)
		return x->Right;
	if (x->Data < k && x->Right!= nullptr && x->Right->Data<k)
		return searchR(x->Right,k);
	if (x->Data < k && x->Right == nullptr)
		return nullptr;
}



int main()
{
	setlocale(LC_ALL, "rus");

	int vel;
	int element;
	int k,n,count_key;
	

	vector <long long> vec;
	vector <long long> keys;
	long long x;
	cin >> n;
	for (size_t i = 0; i < n; i++){
		cin >> x;
		vec.push_back(x);
	
	}
	cin >> count_key;
	for (size_t i = 0; i < count_key; i++){
		cin >> x;
		keys.push_back(x);
	}
	/*for (size_t i = 0; i < keys.size(); i++)
	{
		cout << keys[i] << endl;
	}*/
	
	Node* root = newNode(vec[0]);
	for (int j = 1; j < vec.size(); j++) {
		Node* elem = newNode(vec[j]);
		elem->index = j;
		Add(elem, root);
	}


	for (size_t i = 0; i < count_key; i++){
		Node* cur = search(root, keys[i]);
		if (cur == nullptr) {
			cout << 0 << " ";
			Node* el = searchR(root, keys[i]);
			if (el == nullptr) {
				cout << n << " "<<n;
			}
			else {
				cout << el->index << " "<<el->index;
			}
		}
		else {
			cout << 1 << " ";
			cout << cur->index << " ";
			if (cur->Right != nullptr) {
				cout << cur->Right->Data;
			}
			else if (cur->parent!= nullptr){
				cout << cur->parent->Data;
			}
			else {
				cout << n;
			}
		}
		cout << endl;
	}
	return 0;
}