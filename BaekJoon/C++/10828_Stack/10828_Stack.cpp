#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main()
{
	stack<int> my_stack;
	int N;  // 주어지는 명령의 수
	cin >> N;

	string cmd; //명령의 종류
	int num = 0;	//push number

	for (int i = 0; i < N; i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> num;
			my_stack.push(num);
		}

		if (cmd == "pop") {
			if (my_stack.empty()) {   //스택이 비어있다면 -1 출력
				cout << -1 << endl;
			}
			else {
				cout << my_stack.top() << endl; //현재 스택의 가장 윗부분 출력
				my_stack.pop();     // 출력 후 pop()
			}
		}

		if (cmd == "size") {
			cout << my_stack.size() << endl;
		}

		if (cmd == "empty") {
			if (my_stack.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}

		if (cmd == "top") {
			if (my_stack.empty()) {   //스택이 비어있다면 -1 출력
				cout << -1 << endl;
			}
			else {
				cout << my_stack.top() << endl;
			}
		}

	}	//end for
}