#include <iostream>
#include <vector>
using namespace std;

int N;

void Solve(vector<long long> dp)
{
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 15746;
    }

    cout << dp[N];
}

int main()
{
    cin >> N;
    vector<long long> dp(N + 1);
    Solve(dp);
}