#include <bits/stdc++.h>
using namespace std;

int N;
bool dp[31][15001]; // dp[개수][무게]

void Solve(vector<int> &weight, int i, int w)
{
    if (i > N || dp[i][w])
        return;

    dp[i][w] = true;

    // 추를 안올린다
    Solve(weight, i + 1, w);
    // 추가 올려진 쪽에 추를 더 올린다
    Solve(weight, i + 1, w + weight[i]);
    // 추가 없는 쪽에 추를 올린다
    Solve(weight, i + 1, abs(w - weight[i]));
}

int main()
{
    cin >> N;

    // 주어지는 추
    vector<int> weight(N);
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }

    Solve(weight, 0, 0);

    int T;
    cin >> T;
    // 무게를 알고자 하는 추
    int target;
    for (int i = 0; i < T; i++)
    {
        cin >> target;

        // 최대 추의 개수=30, 최대 추의 무게=500 ==> 30*500=15000
        // target의 무게가 15000을 넘기면 비교할 수 없음
        if (target > 15000)
            cout << "N ";
        else if (dp[N][target])
            cout << "Y ";
        else
            cout << "N ";
    }
}