//链表
#include <iostream>
using namespace std;

struct Node {
	int value;
	struct Node* next;

	Node(int value, Node *next=NULL) {
		this->value = value;
		this->next = next;
	}
};

class linkedList {
private:
	struct Node head;
	int length;
public:
	linkedList(int a[], int n):head(0) {
		head.next = NULL;
		this->length = 0;

		struct Node *p = NULL;
		Node *tail = &head;

		for (int i = 0; i < n; ++i) {
			p = new struct Node(a[i]);

			tail->next = p;
			tail = p;
			length++;
		}
	}
	~linkedList() {
		Node* current = head.next;
		Node* next = NULL;

		while (current) {
			next = current->next;
			delete current;
			current = next;
		}
	}
	void display() {
		Node * current = head.next;

		for (int i = 0; i < length; ++i) {
			cout << current->value << " ";
			current = current->next;
		}
	}
	int deleteNode(int i) {
		Node *prev = &head;
		int result = 0;

		if (i > 0 && i < length) {
			for (int j = 1; j < i - 1; j++) {
				prev = prev->next;
			}
			Node *willDeleteNode = prev->next;
			prev->next = willDeleteNode->next;
			result = willDeleteNode->value;
			delete willDeleteNode;
			length--;
			willDeleteNode = NULL;


		}
		else throw "outofbounds";

		return result;
	}
	//在尾部插入一个值
	bool insertNode(int value) {
		Node * tail = head.next;

		while (tail->next) {
			tail = tail->next;
		}
		Node *newNode = new Node(value);

		tail->next = newNode;
		length++;

		return true;
	}
	bool insert(int i, int value) {
		if (i >= 1 && i <= length + 1) {
			Node *prev = &head;
			for (int j = 0; j < i - 1; j++) {
				prev = prev->next;
			}
			Node *newNode = new Node(value, prev->next);
			prev->next = newNode;
			length++;
			return true;
		}
		else {
			throw "outofbounds";
		}
	}

};

int main() {
	int array[] = { 1, 3, 4, 5 };
	linkedList a(array, sizeof(array) / sizeof(int));
	a.display();
	cout << endl;
	a.deleteNode(1);
	a.display();
	cout << endl;
	a.insertNode(6);
	a.insert(1, 0);
	a.display();
	cout << endl;

	return 0;
}