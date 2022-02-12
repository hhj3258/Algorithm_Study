#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minQ;
priority_queue<int> maxQ;

void swapQTop(const int minTop, const int maxTop)
{
    minQ.pop();
    maxQ.pop();

    minQ.push(maxTop);
    maxQ.push(minTop);
}

void Solve(const int num)
{
    // 예외 상황
    if (maxQ.size() == 0 && minQ.size() == 0)
    {
        maxQ.push(num);
        return;
    }

    // 1. 최대힙의 크기는 항상 최소힙과 같거나 1 크다.
    // 최대힙의 크기가 최소힙의 크기보다 크면
    // 최소힙에 push
    if (maxQ.size() > minQ.size())
        minQ.push(num);
    else
        maxQ.push(num);

    // 2. 최소힙의 원소들은 최대힙의 원소들보다 항상 크다.
    // 최소힙의 top이 최대힙의 top 보다 작으면
    // 두 힙의 top을 swap
    if (minQ.top() < maxQ.top())
        swapQTop(minQ.top(), maxQ.top());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        Solve(num);
        cout << maxQ.top() << "\n";
    }
}