#include <iostream>
#include <vector>
using namespace std;

int T, N, M;
long long dp[30][30];

long long Solve(int n, int r)
{
    if (dp[n][r] > 0)
        return dp[n][r];

    if (r == 0 || n == r)
        return dp[n][r] = 1;

    return dp[n][r] = Solve(n - 1, r - 1) + Solve(n - 1, r);
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        cout << Solve(M, N) << '\n';
    }
}