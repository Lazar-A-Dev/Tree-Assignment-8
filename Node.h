#pragma once
#include<iostream>
using namespace std;
class Node {
public:
	Node* left, * right, * parent;
	int info;

public:
	Node() {
		left = right = parent = NULL;
		info = 0;
	}

	Node(int info, Node* left, Node* right, Node* parent) {
		this->left = left;
		this->right = right;
		this->parent = parent;
		this->info = info;
	}

	~Node() {}
};