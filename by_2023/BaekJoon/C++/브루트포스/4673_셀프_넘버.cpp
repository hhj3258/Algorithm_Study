#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
vector<bool> answer(MAX);

void Solve(int n)
{
    string str = to_string(n);

    int idx = n;
    for (int i = 0; i < str.size(); i++)
    {
        idx += str[i] - '0';
    }

    if (idx < MAX)
        answer[idx] = true;
}

int main()
{
    for (int i = 1; i < MAX; i++)
    {
        Solve(i);
    }

    for (int i = 1; i < MAX; i++)
    {
        if (answer[i] == false)
            cout << i << '\n';
    }
}