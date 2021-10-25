#include <bits/stdc++.h>
using namespace std;

//M: 가로, N: 세로, K: 배추
int M, N, K;

// 동 서 남 북
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void Solve(vector<vector<bool>> &field, int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    field[y][x] = false;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)
                continue;

            if (field[nextY][nextX])
            {
                q.push({nextY, nextX});
                field[nextY][nextX] = false;
            }
        }
    }
}

int main()
{
    int T; // 테스트케이스
    cin >> T;
    vector<int> answer(T);

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;

        int X, Y;
        vector<vector<bool>> field(N, vector<bool>(M));
        for (int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            field[Y][X] = true;
        }

        for (int j = 0; j < field.size(); j++)
        {
            for (int k = 0; k < field[j].size(); k++)
            {
                if (field[j][k])
                {
                    Solve(field, j, k);
                    answer[i]++;
                }
            }
        }
    }

    for (int i : answer)
        cout << i << '\n';
}