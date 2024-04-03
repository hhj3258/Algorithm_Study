#include <iostream>
using namespace std;

class Stack
{
public:
	void push(int number);
	void pop();
	int size() { return _size; }
	bool empty() { return (_size == 0); }
	int top();

private:
	int _size = 0;
	int *_data = new int[10001];
};

void Stack::push(int number)
{
	_data[_size] = number;
	_size++;
}

void Stack::pop()
{
	if (_size > 0)
	{
		cout << top() << '\n';
		_size--;
	}
	else
	{
		cout << "-1" << '\n';
	}
}

int Stack::top()
{
	if (_size <= 0)
		return -1;
	else
		return _data[_size - 1];
}

int main()
{
	Stack myStack;

	int N;
	cin >> N;

	string cmd;
	int number;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;

		if (cmd == "push")
		{
			cin >> number;
			myStack.push(number);
		}
		else if (cmd == "pop")
			myStack.pop();
		else if (cmd == "size")
			cout << myStack.size() << '\n';
		else if (cmd == "empty")
			cout << myStack.empty() << '\n';
		else if (cmd == "top")
			cout << myStack.top() << '\n';
	}
}