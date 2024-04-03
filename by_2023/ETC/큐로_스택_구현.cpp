#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
public:
    void push(int value);
    void pop();
    int size();
    bool empty();
    int top();

private:
    queue<int> mainQ;
    queue<int> subQ;
};

void QueueStack::push(int value)
{
    while (!mainQ.empty())
    {
        subQ.push(mainQ.front());
        mainQ.pop();
    }

    mainQ.push(value);

    while (!subQ.empty())
    {
        mainQ.push(subQ.front());
        subQ.pop();
    }
}

int QueueStack::top()
{
    return mainQ.front();
}

void QueueStack::pop()
{
    if (!mainQ.empty())
        mainQ.pop();
}

bool QueueStack::empty()
{
    if (!mainQ.empty())
        return false;
    else
        return true;
}

int QueueStack::size()
{
    return mainQ.size();
}

int main()
{
    QueueStack qStack;

    qStack.push(1);
    qStack.push(2);
    qStack.push(3);

    cout << "size: " << qStack.size() << endl;

    while (!qStack.empty())
    {
        cout << qStack.top() << ' ';
        qStack.pop();
    }
    cout << endl;

    qStack.push(5);

    cout << "size: " << qStack.size() << endl;
}