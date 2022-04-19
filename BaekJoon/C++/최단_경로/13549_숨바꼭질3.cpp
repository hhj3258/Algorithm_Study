#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int SIZE = 100001;
int distArr[SIZE];

void Solve(int N, int K)
{
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, N);
    distArr[N] = 0;

    while (!pq.empty())
    {
        int nowPos = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if (distArr[nowPos] < dist)
            continue;

        pair<int, int> next[3];
        next[0] = make_pair<int, int>(1, nowPos + 1);
        next[1] = make_pair<int, int>(1, nowPos - 1);
        next[2] = make_pair<int, int>(0, nowPos * 2);

        for (int i = 0; i < 3; i++)
        {
            if (next[i].second >= SIZE || next[i].second < 0)
                continue;

            int cost = next[i].first + dist;

            if (distArr[next[i].second] > cost)
            {
                pq.emplace(-cost, next[i].second);
                distArr[next[i].second] = cost;
            }
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    fill(distArr, distArr + SIZE, INT_MAX);
    Solve(N, K);
    cout << distArr[K];
}