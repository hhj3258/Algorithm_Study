#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int Solve(const vector<vector<int>> &cave)
{
    vector<vector<int>> dist(cave.size(), vector<int>(cave.size(), INT_MAX));

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-cave[0][0], make_pair(0, 0)});
    dist[0][0] = cave[0][0];

    while (!pq.empty())
    {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[y][x] < cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= cave.size() || nextX >= cave.size())
                continue;

            int nextCost = cost + cave[nextY][nextX];

            if (dist[nextY][nextX] > nextCost)
            {
                dist[nextY][nextX] = nextCost;
                pq.push({-nextCost, make_pair(nextY, nextX)});
            }
        }
    }

    return dist[cave.size() - 1][cave.size() - 1];
}

int main()
{
    int cnt = 1;
    while (true)
    {
        int N;
        cin >> N;

        if (N == 0)
            break;

        vector<vector<int>> cave(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> cave[i][j];

        int answer = Solve(cave);
        cout << "Problem " << cnt++ << ": ";
        cout << answer << '\n';
    }
}