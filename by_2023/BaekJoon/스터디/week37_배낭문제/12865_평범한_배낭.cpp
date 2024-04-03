#include <bits/stdc++.h>
using namespace std;

// 물건 갯수, 버틸 수 있는 무게
int N, K;
// 세로: 물건 종류, 가로: 무게
int table[101][100001];

void Solve(vector<pair<int, int>> &items)
{
    // table[종류][무게]

    // 물건 수
    for (int i = 1; i <= N; i++)
    {
        int now_weight = items[i].first;
        int now_value = items[i].second;

        for (int j = 0; j <= K; j++)
        {
            if (now_weight > j)
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = max(table[i - 1][j], table[i - 1][j - now_weight] + now_value);
        }
    }

    cout << table[N][K];
}

int main()
{
    cin >> N >> K;

    int W, V;
    vector<pair<int, int>> items(N + 1);
    for (int i = 1; i <= N; i++)
    {
        // 무게, 가치
        cin >> W >> V;
        items[i].first = W;
        items[i].second = V;

        table[i][W] = V;
    }

    Solve(items);

    // for (int i = 0; i < table.size(); i++)
    // {
    //     for (int j = 0; j < table[i].size(); j++)
    //     {
    //         cout << table[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}