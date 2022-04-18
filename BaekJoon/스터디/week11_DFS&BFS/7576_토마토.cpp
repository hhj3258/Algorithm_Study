#include <bits/stdc++.h>
using namespace std;

struct POINT
{
    POINT(int _y, int _x) : y(_y), x(_x)
    {
    }
    int y;
    int x;
};

int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int zero_cnt = 0;
int answer = 1;

void Solve(queue<POINT> q, vector<vector<int>> &box)
{
    while (!q.empty())
    {
        POINT now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            POINT next(now.y + dy[i], now.x + dx[i]);

            if (next.y < 0 || next.x < 0)
                continue;
            if (next.y >= box.size() || next.x >= box[0].size())
                continue;

            if (box[next.y][next.x] == 0)
            {
                q.emplace(next);
                box[next.y][next.x] = box[now.y][now.x] + 1;

                answer = max(answer, box[next.y][next.x]);
                zero_cnt--;
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> M >> N;

    // 1=익은 토마토
    // 0=익지 않은 토마토
    // -1=비어있는 칸
    vector<vector<int>> box(N, vector<int>(M));
    queue<POINT> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];

            if (box[i][j] == 1)
            {
                // 익은 토마토 저장
                q.emplace(POINT(i, j));
            }

            if (box[i][j] == 0)
                zero_cnt++;
        }
    }

    Solve(q, box);

    if (zero_cnt == 0)
        cout << (answer - 1);
    else
        cout << -1;
}