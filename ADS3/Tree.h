#pragma once
#include "Node.h"
#include "Stack.h"
#include <iostream>
#include <vector>
#include <string>
class Tree {
private:
	Stack* top;
public:

	Tree();
	bool isoperator(std::string data);
	void deleteTree();
	Node* pop();
	Node* showtop();
	void pushNode(Node* node);
	void insertNode(std::string data);
	void buildTree(std::vector<std::string>);
	double evaluateNode(Node* node);
	double evaluate();

};