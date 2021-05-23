#include "Node.h"
#include <string>

Node::Node(std::string data) {
	this->data = data;
	this->left = this->right = NULL;
}
