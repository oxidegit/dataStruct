#pragma once
class Stack
{
public:
	Stack();
	~Stack();
	char pop();
	void push(char v);
	void destroy();
	bool isEmpty();
	char get();
private:
	char data[20];
	int top;
};

