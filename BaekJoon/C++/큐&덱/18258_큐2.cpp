#include <iostream>
using namespace std;

class Queue
{
private:
    const int MaxSize = 2000000;
    int *queue = new int[MaxSize];
    int left = 0;
    int right = 0;

public:
    void push(int n);
    int pop();
    int size();
    int empty();
    int front();
    int back();
};

void Queue::push(int n)
{
    queue[right++] = n;
}

int Queue::pop()
{
    if (left == right)
        return -1;
    else
    {
        int idx = left++;
        return queue[idx];
    }
}

int Queue::size()
{
    return (right - left);
}

int Queue::empty()
{
    if (size() == 0)
        return 1;
    else
        return 0;
}

int Queue::front()
{
    if (empty())
        return -1;
    else
        return queue[left];
}

int Queue::back()
{
    if (empty())
        return -1;
    else
        return queue[right - 1];
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    Queue q;

    string cmd;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (cmd == "pop")
            cout << q.pop() << '\n';
        else if (cmd == "size")
            cout << q.size() << '\n';
        else if (cmd == "empty")
            cout << q.empty() << '\n';
        else if (cmd == "front")
            cout << q.front() << '\n';
        else if (cmd == "back")
            cout << q.back() << '\n';
    }
}