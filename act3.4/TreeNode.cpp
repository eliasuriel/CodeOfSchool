#include "TreeNode.h"
TreeNode::TreeNode(bst nodeData)
{
	data = nodeData;
	leftNode = rightNode = NULL;
}

void TreeNode::insert(bst insertValue)
{
	if (insertValue.accesos < data.accesos) {
		if (leftNode == NULL)
			leftNode = new TreeNode(insertValue);
		else
			leftNode->insert(insertValue);
	}
	else if (insertValue.accesos > data.accesos) {
		if (rightNode == NULL)
			rightNode = new TreeNode(insertValue);
		else
			rightNode->insert(insertValue);
	}
	else if (insertValue.accesos == data.accesos && insertValue.accesos > 1) {
		if (rightNode == NULL)
			rightNode = new TreeNode(insertValue);
		else
			rightNode->insert(insertValue);
	}
}