#include <iostream>
#include <vector>
using namespace std;

void Solve(int n, vector<int> dp)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    Solve(n, dp);
}