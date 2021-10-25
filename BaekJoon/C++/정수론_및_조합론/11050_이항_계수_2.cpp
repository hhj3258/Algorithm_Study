#include <iostream>
#include <vector>
using namespace std;

int N, K;

int Binomial(int n, int r, vector<vector<int>> &dp)
{
    if (dp[n][r] > 0)
        return dp[n][r];

    if (r == 0 || n == r)
        return dp[n][r] = 1;

    return dp[n][r] = (Binomial(n - 1, r - 1, dp) + Binomial(n - 1, r, dp)) % 10007;
}

int main()
{
    cin >> N >> K;
    vector<vector<int>> dp(N + 1, vector<int>(K + 1));
    cout << Binomial(N, K, dp);
}