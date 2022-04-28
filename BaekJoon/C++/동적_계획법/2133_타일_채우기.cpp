#include <bits/stdc++.h>
using namespace std;

void Solve(int N)
{
    vector<int> dp(N + 1);

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 4; i <= N; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[N];
}

int main()
{
    int N;
    cin >> N;

    Solve(N);
}