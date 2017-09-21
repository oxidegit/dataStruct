#include <iostream>
#include "BinTree.h"

using namespace std;

class Stack
{
public:
	Stack() { top = -1; };
	BinNode *pop() {
		if (!isEmpty()) {
			return data[top--];
		}
	};
	void push(BinNode *v, int f = 0) { data[++top] = v; flag[top] = f; };
	void destroy() { top = -1; };
	bool isEmpty() {
		if (this->top == -1) {
			return true;
		}
		else {
			return false;
		}
	};
	BinNode *get() {
		if (!isEmpty()) {
			return data[top];
		}
	};
	int getFlag() {
		if (!isEmpty()) {
			return flag[top];
		}
	}
	void setFlag(int f) {
		flag[top] = f;
	}
private:
	BinNode *data[20];
	int flag[20];
	int top;
};


BinNode * BinTree::createTree(BinNode *root) {
	char c;
	cin >> c;

	if (c != '#') {
		root = new BinNode();
		root->value = c;
		root->leftChild = createTree(root->leftChild);
		root->rightChild = createTree(root->rightChild);
	}

	return root;
}
void BinTree::destroyTree(BinNode *root) {
	if (root) {
		destroyTree(root->leftChild);
		destroyTree(root->rightChild);
		delete root;
	}
}
void BinTree::preOrder(BinNode* root) {
	if (root) {
		cout << root->value << " ";
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}
void BinTree::preOrderLoop(BinNode *root) {
	Stack s;
	BinNode *current = root;

	while (current || !s.isEmpty()) {//当 当前树不为空树 或者还有 树没有访问的时候
		//存在两种情况
		//1.树不空栈空
		//2.树空栈不空
		//需要判断一下

		while (current) {
			cout << current->value << " ";
			s.push(current);
			current = current->leftChild;
		}
		if (!s.isEmpty()) {
			current = s.pop()->rightChild;
		}
	}

}
void BinTree::inOrder(BinNode *root) {
	if (root) {
		preOrder(root->leftChild);
		cout << root->value << " ";
		preOrder(root->rightChild);
	}
}
void BinTree::inOrderLoop(BinNode *root) {
	Stack s;
	BinNode *current = root;

	while (current || !s.isEmpty()) {
		while (current) {
			s.push(current);
			current = current->leftChild;
		}
		if (!s.isEmpty()) {
			cout << s.get()->value << " ";
			current = s.pop()->rightChild;
		}
	}
}
void BinTree::postOrder(BinNode *root) {
	if (root) {
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		cout << root->value << " ";
	}
}
void BinTree::postOrderLoop(BinNode *root) {
	Stack s;
	BinNode *current = root;

	while (current || !s.isEmpty()) {
		while (current) {
			s.push(current);
			current = current->leftChild;
		}

		if (!s.isEmpty()) {

			while (!s.isEmpty() && s.getFlag() == 1) {
				cout << s.pop()->value << " ";
			}
			if (!s.isEmpty()) {
				current = s.get()->rightChild;
				s.setFlag(1);
			}
		}

	}
}
void BinTree::levelOrder(BinNode *root) {
	BinNode *pQueue[20];
	BinNode *current = NULL;
	int front = -1;
	int rear = -1;

	if (root) {
		pQueue[++rear] = root;
	}
	while (rear != front) {
		current = pQueue[++front];
		cout << current->value << " ";

		if (current->leftChild) {
			pQueue[++rear] = current->leftChild;
		}
		if (current->rightChild) {
			pQueue[++rear] = current->rightChild;
		}
	}
}

