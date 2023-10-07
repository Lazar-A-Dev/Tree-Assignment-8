#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
class Tree
{
public:
	Node* root;
	int size;
public:

	Tree();
	~Tree();

	void AddToTree(int p);

	Node* FindNodeNR(int p);
	Node* FindNodeR(int p, Node* tmp);

	int Depth(Node* p);
	int Higth(Node* p);
	int StepenStabla(Node* p);
	bool Max(int a, int b);

	int NumberOfLeaves(Node* p);
	int NumberOfNodes(Node* p);

	int SumOfTree(Node* p);
	int LargestRightSubtree(Node* p);
	int largestLeftSubtree(Node* p);

	void PreOrder();
	void PreOrder(Node* p);
	void InOrder();
	void InOrder(Node* p);
	void PostOrder();
	void PostOrder(Node* p);
	void PrintByLevels();

	void RandomTree();
	int CountSL(Node* p);
	int CountSingleLeafNodes(Node* p);
	int CountSpecificNodes(Node* p);
	Node* CloasestValueLeaf(Node* p, int tmp);
};

