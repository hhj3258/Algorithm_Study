#include <iostream>
#include <vector>
using namespace std;

int N, K;

void Solve(vector<int> W, vector<int> V, vector<vector<int>> dp)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (W[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            }
        }
    }

    cout << dp[N][K];
}

int main()
{
    cin >> N >> K;
    vector<int> W(N + 1);
    vector<int> V(N + 1);
    vector<vector<int>> dp(N + 1, vector<int>(K + 1));

    for (int i = 1; i <= N; i++)
    {
        cin >> W[i] >> V[i];
    }

    Solve(W, V, dp);
}