#pragma once
#include "Node.h"
#include <iostream>
#include <vector>
#include <string>
class Stack {
public:
	Node* node;
	Stack* next;

	Stack(Node* node);

};

