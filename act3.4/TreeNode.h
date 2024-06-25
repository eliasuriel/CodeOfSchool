#pragma once
#include <iostream>
using namespace std;
struct bst {
	string dirIP = ""; //Valor de IP en string
	int accesos = 0; //Valor llave, numero de accesos de cada IP
};

class TreeNode
{
public:
	TreeNode(bst);
	void insert(bst);
	TreeNode* leftNode;
	bst data;
	TreeNode* rightNode;
};

