#include <bits/stdc++.h>
using namespace std;

void Solve(int N)
{
    vector<long long> dp(N + 1);

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout << dp[N];
}

int main()
{
    int N;
    cin >> N;

    Solve(N);
}