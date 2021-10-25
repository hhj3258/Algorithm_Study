#include <bits/stdc++.h>
using namespace std;

int N;

// 동 서 남 북
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int Solve(vector<vector<int>> &aparts, int y, int x)
{
    queue<pair<int, int>> q;

    q.push({y, x});
    aparts[y][x] = 0;
    int cnt = 1;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            if (aparts[ny][nx] != 0)
            {
                q.push({ny, nx});
                aparts[ny][nx] = 0;
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    cin >> N;

    vector<string> temp(N);
    vector<vector<int>> aparts(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        cin >> temp[i];

        for (int j = 0; j < N; j++)
            aparts[i][j] = temp[i][j] - '0';
    }

    vector<int> answer;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (aparts[i][j] != 0)
            {
                answer.push_back(Solve(aparts, i, j));

                // for (int i = 0; i < N; i++)
                // {
                //     for (int j = 0; j < N; j++)
                //         cout << aparts[i][j] << ' ';
                //     cout << endl;
                // }
                // cout << endl;
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (int i : answer)
        cout << i << '\n';
}