#include <bits/stdc++.h>
using namespace std;

void Knabsack(vector<vector<int>> &dp, vector<pair<int, int>> &items, int N, int K)
{
    for (int i = 1; i <= N; i++)
    {
        int wi = items[i].first;
        int vi = items[i].second;

        for (int j = 0; j <= K; j++)
        {
            // wi = 현재 물건 무게
            if (wi > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wi] + vi);
            }
        }
    }
}

// 효율성은 (가방에 담긴 물건의 가치의 합) / (가방이 견딜 수 있는 최대 무게)
int CalcEfficiency(vector<vector<int>> &dp, vector<int> &bags, int N)
{
    float max_eff = 0;
    int answer = 1;
    for (int i = 0; i < bags.size(); i++)
    {
        float efficiency = static_cast<float>(dp[N][bags[i]]) / bags[i];
        if (efficiency > max_eff)
        {
            max_eff = efficiency;
            answer = i + 1;
        }
    }

    return answer;
}

int main()
{
    // 물건 수, 가방 수
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> items(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int W, V;
        cin >> W >> V;

        items[i] = make_pair(W, V);
    }

    // 가방이 버틸 수 있는 최대 무게
    vector<int> bags(M);
    int max_w = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> bags[i];
        max_w = max(max_w, bags[i]);
    }

    vector<vector<int>> dp(N + 1, vector<int>(max_w + 1));
    Knabsack(dp, items, N, max_w);
    cout << CalcEfficiency(dp, bags, N);
}