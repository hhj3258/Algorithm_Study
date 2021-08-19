#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> dp(501, 1);

void Solve(vector<pair<int, int>> lines)
{
    sort(lines.begin(), lines.end());

    int maxV = -1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (lines[i].second > lines[j].second)
                dp[i] = max(dp[i], dp[j] + 1);

            if (maxV < dp[i])
                maxV = dp[i];
        }
    }

    cout << N - maxV;
}

int main()
{
    cin >> N;
    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; i++)
        cin >> lines[i].first >> lines[i].second;

    Solve(lines);
}