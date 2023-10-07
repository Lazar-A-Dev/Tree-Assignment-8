#include<iostream>
#include"Tree.h"
using namespace std;
void main() {
	Tree t;
	
	t.AddToTree(20);
	t.AddToTree(15);
	t.AddToTree(30);
	t.AddToTree(10);
	t.AddToTree(18);
	t.AddToTree(21);
	t.AddToTree(35);
	t.AddToTree(3);
	t.AddToTree(11);
	t.AddToTree(25);
	t.AddToTree(40);
	t.AddToTree(17);
	t.AddToTree(24);
	t.AddToTree(29);
	t.AddToTree(19);
	
	//t.RandomTree();
	t.PreOrder();
	cout << endl;
	cout << "Nadji cvor bez rekurzije: " << t.FindNodeNR(24)->info << endl;
	cout << "Nadji cvor sa rekurzijom: " << t.FindNodeR(25, t.root)->info << endl;
	cout << "Broj lista u stablu: " << t.NumberOfLeaves(t.root) << endl;
	cout << "Broj cvora u stablu: " << t.NumberOfNodes(t.root) << endl;
	cout << "Suma stabla: " << t.SumOfTree(t.root) << endl;
	cout << "Stepen stabla: " << t.StepenStabla(t.root) << endl;
	cout << "Dubina cvora: " << t.Depth(t.root->left->left) << endl;
	cout << "Broj cvora levog podstabla sto su veci od denog: " << t.CountSL(t.root) << endl;
	cout << "Cvorovi samo sa jednim potomkom sto je list: " << t.CountSingleLeafNodes(t.root) << endl;
	cout << "Broj lista u desnom podstablu sto je vise nego u levom: " << t.CountSpecificNodes(t.root) << endl;
	cout << "Closest value leaf: " << t.CloasestValueLeaf(t.root, 26)->info << endl;

	t.PrintByLevels();
	system("pause");
}