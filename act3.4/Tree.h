#pragma once
#include "TreeNode.h"
class Tree
{
public:
	Tree();
	void insertNode(bst );
	void inorderTraversal();
private:
	TreeNode* root;
	void inorderHelper(TreeNode* ,int &);
};
