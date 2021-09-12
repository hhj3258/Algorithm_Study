#include <bits/stdc++.h>
using namespace std;

int T, N;

int Solve(int N)
{
    unordered_map<string, int> wears;

    string a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        wears[b]++;
    }

    int answer = 1;
    for (auto it : wears)
        answer *= (it.second + 1);
    answer -= 1;

    return answer;
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << Solve(N) << '\n';
    }
}