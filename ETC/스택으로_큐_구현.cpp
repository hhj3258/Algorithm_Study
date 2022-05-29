#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
public:
    void push(int value);
    int size();
    void pop();
    bool empty();
    int front();

private:
    stack<int> mainS;
    stack<int> subS;
};

/*
case 1
1) 메인 스택이 비어있으면 메인 스택에 push
case 2
1) 메인 스택이 비어있지 않으면 메인 스택의 모든 원소를 서브 스택으로 옮김
2) 메인 스택에 value 를 push
3) 서브 스택의 모든 원소를 메인 스택으로 옮김
*/
void StackQueue::push(int value)
{
    if (mainS.empty())
    {
        mainS.push(value);
    }
    else
    {
        while (!mainS.empty())
        {
            subS.push(mainS.top());
            mainS.pop();
        }

        mainS.push(value);

        while (!subS.empty())
        {
            mainS.push(subS.top());
            subS.pop();
        }
    }
}

void StackQueue::pop()
{
    if (!mainS.empty())
        mainS.pop();
}

int StackQueue::front()
{
    return mainS.top();
}

int StackQueue::size()
{
    return mainS.size();
}

bool StackQueue::empty()
{
    return mainS.empty();
}

int main()
{
    StackQueue sQ;

    sQ.push(1);
    sQ.push(2);
    sQ.push(3);

    cout << "size: " << sQ.size() << endl;

    while (!sQ.empty())
    {
        cout << sQ.front() << ' ';
        sQ.pop();
    }
    cout << endl;

    sQ.push(5);

    cout << "size: " << sQ.size() << endl;

    cout << sQ.front() << endl;
    sQ.push(6);
    cout << sQ.front() << endl;
}