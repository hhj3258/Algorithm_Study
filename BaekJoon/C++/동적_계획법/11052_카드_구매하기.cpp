#include <bits/stdc++.h>
using namespace std;

void Solve(int N, vector<int> &packs)
{
    vector<int> dp(N + 1);

    dp[1] = packs[1];
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[i - j] + packs[j]);
    }

    cout << dp[N];
}

int main()
{
    int N;
    // 구매하려는 카드의 수
    cin >> N;

    // 카드팩의 종류 N
    vector<int> packs(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> packs[i];

    Solve(N, packs);
}