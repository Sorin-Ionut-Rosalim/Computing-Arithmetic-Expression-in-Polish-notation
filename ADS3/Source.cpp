#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <vector>
#include "Tree.h"


int main() {
	std::ifstream file("input.txt");
	Tree tree;
    std::vector<std::string> tokenList;
    std::string input, token;
    file.seekg(0, std::ios::end);
    input.reserve(file.tellg());
    file.seekg(0, std::ios::beg);
    input.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::istringstream iss(input);
    while (std::getline(iss, token, ' '))
    {
        tokenList.push_back(token);
    }
    
    tree.buildTree(tokenList);
    std::cout <<"Input: " << input << std::endl;
    std::cout << "Result: " << tree.evaluate();
    
    file.close();
	return 0;
}