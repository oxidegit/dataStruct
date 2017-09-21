#include "Stack.h"



Stack::Stack()
{
	top = -1;
}

Stack::~Stack()
{
}

char Stack::pop() {
	if (!isEmpty()) {
		return data[top--];
	}
}
void Stack::push(char v) {
	data[++top] = v;
}
void Stack::destroy() {
	top = -1;
}
bool Stack::isEmpty() {
	if (this->top == -1) {
		return true;
	}
	else {
		return false;
	}
}

char Stack::get() {
	if (!isEmpty()) {
		return data[top];
	}
}
