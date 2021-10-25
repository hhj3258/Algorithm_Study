#include <iostream>
#include <vector>
using namespace std;

int N;

void Solve(vector<vector<int>> rgb)
{
    vector<vector<int>> dp(N, vector<int>(3));

    for (int j = 0; j < 3; j++)
        dp[0][j] = rgb[0][j];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][j];
            else if (j == 1)
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][j];
            else if (j == 2)
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][j];
        }
    }

    int answer = min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));

    cout << answer;
}

int main()
{
    cin >> N;
    vector<vector<int>> rgb(N, vector<int>(3));

    for (int i = 0; i < rgb.size(); i++)
        for (int j = 0; j < rgb[i].size(); j++)
            cin >> rgb[i][j];

    Solve(rgb);
}