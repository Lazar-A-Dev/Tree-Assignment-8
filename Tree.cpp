#include "Tree.h"
Tree::Tree() {
	root = NULL;
	size = 0;
}

Tree::~Tree() {

}

void Tree::AddToTree(int p) {
	if (root == NULL) {
		Node* tmp = new Node(p, NULL, NULL, NULL);
		root = tmp;
	}
	else {
		Node* prev = NULL;
		Node* current = root;

		while (current != NULL) {
			prev = current;
			if (current->info > p)
				current = current->left;
			else if (current->info < p)
				current = current->right;
		}

		if (prev->info > p) {
			prev->left = new Node(p, NULL, NULL, prev);
			size++;
		}
		else if (prev->info < p) {
			prev->right = new Node(p, NULL, NULL, prev);
			size++;
		}
	}
}

Node* Tree::FindNodeNR(int p) {
	Node* tmp = root;
	while (tmp != NULL && tmp->info != p) {
		if (tmp->info < p)
			tmp = tmp->right;
		else if (tmp->info > p)
			tmp = tmp->left;
	}
	return tmp;
}

Node* Tree::FindNodeR(int p, Node* tmp) {
	if (tmp == NULL)
		return NULL;
	else if (tmp != NULL && tmp->info == p)
		return tmp;
	else if (tmp->left != NULL && tmp->left->info == p)
		return tmp->left;
	else if (tmp->right != NULL && tmp->right->info == p)
		return tmp->right;

	Node* p1 = FindNodeR(p, tmp->left);
	Node* p2 = FindNodeR(p, tmp->right);

	if (p1 != NULL && p1->info == p)
		return p1;
	else if (p2 != NULL && p2->info == p)
		return p2;
		
}

int Tree::Depth(Node* p) {
	if (p == root)
		return NULL;
	else
		return 1 + Depth(p->parent);
}

int Tree::Higth(Node* p) {
	if (p == NULL)
		return NULL;
	int l = 1 + StepenStabla(p->left);
	int r = 1 + StepenStabla(p->right);

	if (l > r)
		return l;
	else return r;
}

int Tree::StepenStabla(Node* p) {
	if (p == NULL)
		return NULL;
	int l = 1 + StepenStabla(p->left);
	int r = 1 + StepenStabla(p->right);

	if (l > r)
		return l;
	else return r;
}

bool Tree::Max(int a, int b) {
	if (a >= b)
		return true;
	return false;
}

int Tree::NumberOfLeaves(Node* p) {
	if (p == NULL)
		return NULL;
	
	if (p->left == NULL && p->right == NULL)
		return 1;

	return NumberOfLeaves(p->left) + NumberOfLeaves(p->right);
}

int Tree::NumberOfNodes(Node* p) {
	if (p == NULL)
		return NULL;

	return 1 + NumberOfNodes(p->left) + NumberOfNodes(p->right);
}

int Tree::SumOfTree(Node* p) {
	if (p == NULL)
		return NULL;

	return p->info + SumOfTree(p->left) + SumOfTree(p->right);
}

int Tree::LargestRightSubtree(Node* p) {
	if (p == NULL)
		return NULL;

	int l = LargestRightSubtree(p->left);
	int r = LargestRightSubtree(p->right);

	if (l < NumberOfNodes(p->right))
		l = NumberOfNodes(p->right);
	else if (r < NumberOfNodes(p->right))
		r = NumberOfNodes(p->right);

	if (l >= r)
		return l;
	else return r;
}

int Tree::largestLeftSubtree(Node* p) {
	if (p == NULL)
		return NULL;

	int l = LargestRightSubtree(p->left);
	int r = LargestRightSubtree(p->right);

	if (l < NumberOfNodes(p->left))
		l = NumberOfNodes(p->left);
	else if (r < NumberOfNodes(p->left))
		r = NumberOfNodes(p->left);

	if (l >= r)
		return l;
	else return r;
}

void Tree::PreOrder() {
	PreOrder(root);
}

void Tree::PreOrder(Node* p) {
	if (p != NULL) {
		cout << "[" << p->info << "] ";
		PreOrder(p->left);
		PreOrder(p->right);
	}
}

void Tree::InOrder() {
	InOrder(root);
}

void Tree::InOrder(Node* p) {
	if (p != NULL) {
		InOrder(p->left);
		cout << "[" << p->info << "] ";
		InOrder(p->right);
	}
}

void Tree::PostOrder() {
	PostOrder(root);
}

void Tree::PostOrder(Node* p) {
	if (p != NULL) {
		PostOrder(p->left);
		PostOrder(p->right);
		cout << "[" << p->info << "] ";
	}
}

void Tree::PrintByLevels() {
	Node* tmp = root;
	Node** stack = new Node*[size];
	int position = 1;
	int indeks = 0;
	stack[indeks++] = tmp;

	while (position <= size) {
		if (tmp->left != NULL)
			stack[indeks++] = tmp->left;

		if (tmp->right != NULL)
			stack[indeks++] = tmp->right;

		tmp = stack[position++];
	}
	cout << "Tree by levels: " << endl;
	for (int i = 0; i < size; i++) {
		cout << "[" << stack[i]->info << "] ";
	}
	cout << endl;
}

void Tree::RandomTree() {

	Node* p1 = new Node(6, NULL, NULL, NULL);
	Node* p2 = new Node(1, NULL, NULL, NULL);
	Node* p3 = new Node(14, NULL, NULL, NULL);
	Node* p4 = new Node(8, NULL, NULL, NULL);
	Node* p5 = new Node(15, NULL, NULL, NULL);
	Node* p6 = new Node(11, NULL, NULL, NULL);
	Node* p7 = new Node(20, NULL, NULL, NULL);
	Node* p8 = new Node(2, NULL, NULL, NULL);
	Node* p9 = new Node(3, NULL, NULL, NULL);
	Node* p10 = new Node(5, NULL, NULL, NULL);

	Node* tmp = new Node(7, p1, p2, NULL);
	root = tmp;
	p1->left = p3;
	p1->right = p4;
	p1->parent = root;

	p2->left = p5;
	p2->right = p6;
	p2->parent = root;

	p3->left = p7;
	p3->right = p8;
	p3->parent = p1;

	p4->parent = p1;

	p5->parent = p2;

	p6->left = p9;
	p6->right = p10;
	p6->parent = p2;

	p7->parent = p3;

	p8->parent = p3;

	p9->parent = p6;

	p10->parent = p6;
}

int Tree::CountSL(Node* p) {
	if (p == NULL)
		return NULL;

	if (SumOfTree(p->left) > SumOfTree(p->right))
		return 1 + CountSL(p->left) + CountSL(p->right);

	return CountSL(p->left) + CountSL(p->right);
}

int Tree::CountSingleLeafNodes(Node* p) {
	if (p == NULL)
		return NULL;

	if (p->left != NULL && p->right == NULL && p->left->left == NULL && p->left->right == NULL)
		return 1 + CountSingleLeafNodes(p->left) + CountSingleLeafNodes(p->right);
	else if(p->left == NULL && p->right != NULL && p->right->left == NULL && p->right->right == NULL)
		return 1 + CountSingleLeafNodes(p->left) + CountSingleLeafNodes(p->right);
	else return CountSingleLeafNodes(p->left) + CountSingleLeafNodes(p->right);
}

int Tree::CountSpecificNodes(Node* p) {
	if (p == NULL)
		return NULL;

	if (NumberOfLeaves(p->right) > NumberOfLeaves(p->left))
		return 1 + CountSpecificNodes(p->left) + CountSingleLeafNodes(p->right);

	return CountSpecificNodes(p->left) + CountSingleLeafNodes(p->right);
}

Node* Tree::CloasestValueLeaf(Node* p, int tmp) {
	if (p == NULL)
		return NULL;
	else if (p->left == NULL && p->right == NULL)
		return p;

	Node* left = CloasestValueLeaf(p->left, tmp);
	Node* right = CloasestValueLeaf(p->right, tmp);

	if (left == NULL && right != NULL) {
		int rightRez = abs(right->info - tmp);
		int pRez = abs(p->info - tmp);

		if (rightRez <= pRez && rightRez >= 0)
			return right;
		else if (pRez <= rightRez && pRez >= 0)
			return p;
	}
	else if (right == NULL && left != NULL) {
		int leftRez = abs(left->info - tmp);
		int pRez = abs(p->info - tmp);

		if (leftRez <= pRez && leftRez >= 0)
			return left;
		else if (pRez <= leftRez && pRez >= 0)
			return p;
	}
		

	int leftRez = abs(left->info - tmp);
	int rightRez = abs(right->info - tmp);
	int pRez = abs(p->info - tmp);

	if (leftRez <= rightRez && leftRez <= pRez && leftRez >= 0)
		return left;
	else if (rightRez <= leftRez && rightRez <= pRez && rightRez >= 0)
		return right;
	else if (pRez <= leftRez && pRez <= rightRez && pRez >= 0)
		return p;
}