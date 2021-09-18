#include <bits/stdc++.h>
using namespace std;

void Solve(int &K)
{
    stack<int> nums;
    int num;

    for (int i = 0; i < K; i++)
    {
        cin >> num;

        if (num != 0)
            nums.push(num);
        else
            nums.pop();
    }

    int answer = 0;
    while (!nums.empty())
    {
        answer += nums.top();
        nums.pop();
    }

    cout << answer;
}

int main()
{
    int K;
    cin >> K;
    Solve(K);
}