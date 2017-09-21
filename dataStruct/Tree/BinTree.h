#pragma once
#include "BinNode.h"

class BinTree {
public:
	BinTree() {
		root = NULL;
		root = createTree(root);
	};
	~BinTree() { destroyTree(root); };
	//递归实现
	void preOrder() { preOrder(this->root); }
	void inOrder() { inOrder(this->root); };
	void postOrder() { postOrder(this->root); };
    //非递归实现
	void levelOrder() { levelOrder(this->root); };
	void preOrderLoop() { preOrderLoop(this->root); }
	void inOrderLoop() { inOrderLoop(this->root); }
	void postOrderLoop() { postOrderLoop(this->root); }
private:
	BinNode* root;
	BinNode * createTree(BinNode *root);

	void preOrderLoop(BinNode *root);
	void inOrderLoop(BinNode *root);
	void postOrderLoop(BinNode *root);

	void destroyTree(BinNode *root);
	void preOrder(BinNode* root);
	void inOrder(BinNode *root);
	void postOrder(BinNode *root);
	void levelOrder(BinNode *root);
};