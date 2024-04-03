#include <bits/stdc++.h>
using namespace std;

int N;

void Solve(const vector<vector<int>> &rgb)
{
    vector<vector<int>> dp = rgb;

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + rgb[i][2];
    }

    cout << *min_element(dp[N - 1].begin(), dp[N - 1].end());
}

int main()
{
    cin >> N;

    vector<vector<int>> rgb(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    Solve(rgb);
}