#include <bits/stdc++.h>
using namespace std;

int dp[11][11];

int Solve(int n, int r)
{
    if (dp[n][r] != 0)
        return dp[n][r];

    if (r == 0 || n == r)
        return dp[n][r] = 1;

    return dp[n][r] = Solve(n - 1, r - 1) + Solve(n - 1, r);
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << Solve(N, K);
}