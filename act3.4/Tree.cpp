#include <iostream>
using namespace std;
#include "Tree.h"

Tree::Tree() {
	root = nullptr;
}

void Tree::insertNode(bst data) {
	if (root == NULL) {
		root = new TreeNode(data);
	}
	else {
		root->insert(data);
	}
}

void Tree::inorderTraversal()
{
	int limite = 5;
	cout << "ip con mayores accesos " << endl;
	inorderHelper(root, limite);
	cout << endl;
}
void Tree::inorderHelper(TreeNode* node,int &limit)
{
	if (node != NULL && limit > 0)
	{
		inorderHelper(node->rightNode, limit);
		if (limit > 0) {
			limit--;
			cout << " Ip: " << node->data.dirIP<<"Accesos: "<< node->data.accesos<< endl;
		}
		if (limit > 0) {
			inorderHelper(node->leftNode, limit);
		}
	}
}
