#include "Tree.h"


Tree::Tree(){
	this->top = nullptr;
}

void Tree::deleteTree() {
	this->top = nullptr;
}

bool Tree::isoperator(std::string data)
{
	return data == "+" || data == "-" || data == "*" || data == "/" || data == "^";
}

void Tree::pushNode(Node *node){
	if (top == nullptr) {
		top = new Stack(node);
	}
	else {
		Stack* newNode = new Stack(node);
		newNode->next = top;
		top = newNode;
	}
}

Node* Tree::pop()
{
	if (top == nullptr) {
		std::cout << "No elements are in the stack!";
	}
	else {
		Node* node = top->node;
		top = top->next;
		return node;
	}
	return nullptr;
}

Node* Tree::showtop() {
	return top->node;
}

void Tree::insertNode(std::string data) {
	if (!isoperator(data)) {
		Node* newNode = new Node(data);
		pushNode(newNode);
	}
	else if (isoperator(data)) {
		Node* newNode = new Node(data);
		newNode->left = pop();
		newNode->right = pop();
		pushNode(newNode);
	}
	else {
		std::cout << "Invalid character found!" << std::endl;
	}
}

void Tree::buildTree(std::vector<std::string> input){
	for (auto part = input.rbegin(); part != input.rend(); part++) {
		insertNode(*part);
	}
}


double Tree::evaluateNode(Node* node) {
	if (node->left == nullptr && node->right == nullptr)
		return std::stod(node->data);
	else {
		double result = 0.0;
		double l = evaluateNode(node->left);
		double r = evaluateNode(node->right);
		std::string ops = node->data;
		char op = ops[0];
		switch (op)
		{
		case '+':
			result = l + r;
			break;
		case '-':
			result = l - r;
			break;
		case '*':
			result = l * r;
			break;
		case '/':
			result = l / r;
			break;
		case '^':
			result = pow(l, r);
			break;
		}
		return result;
	}
}

double Tree::evaluate() {
	return evaluateNode(showtop());
}

