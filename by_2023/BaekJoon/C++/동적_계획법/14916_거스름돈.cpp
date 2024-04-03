#include <bits/stdc++.h>
using namespace std;

int n;

void Solve()
{
    vector<int> dp(100001, INT_MAX);
    dp[2] = dp[5] = 1;
    dp[4] = 2;

    for (int i = 6; i <= n; i++)
    {
        dp[i] = min(dp[i - 2], dp[i - 5]) + 1;
    }

    if (dp[n] == INT_MAX)
        cout << -1;
    else
        cout << dp[n];
}

int main()
{
    // 거스름돈 액수
    cin >> n;

    Solve();
}