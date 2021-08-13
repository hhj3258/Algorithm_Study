#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[300];

void Solve(vector<int> stair)
{
    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0], stair[1]) + stair[2];

    for (int i = 3; i < N; i++)
        dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];

    cout << dp[N - 1];
}

int main()
{

    cin >> N;
    vector<int> stair(N);

    for (int i = 0; i < N; i++)
        cin >> stair[i];

    Solve(stair);
}