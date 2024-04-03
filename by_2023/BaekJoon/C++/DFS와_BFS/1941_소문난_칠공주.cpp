#include <bits/stdc++.h>
using namespace std;

const int Size = 5;
int answer = 0;

vector<string> Input(Size);

int GetOriginMemCnt(vector<pair<int, int>> &data)
{
    int ret = 0;

    for (int i = 0; i < data.size(); i++)
    {
        int y = data[i].first;
        int x = data[i].second;

        if (Input[y][x] == 'S')
            ret++;
    }

    return ret;
}

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<vector<int>> dataTwoArr(Size, vector<int>(Size));
vector<vector<bool>> visited(Size, vector<bool>(Size));

bool IsAllAdjacent(vector<pair<int, int>> &data)
{
    queue<pair<int, int>> q;
    q.push(data[0]);

    fill(dataTwoArr.begin(), dataTwoArr.end(), vector<int>(Size, -1));
    for (int i = 0; i < data.size(); i++)
        dataTwoArr[data[i].first][data[i].second] = i;

    fill(visited.begin(), visited.end(), vector<bool>(Size, false));
    visited[data[0].first][data[0].second] = true;

    int cnt = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (cnt == 7)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= Size || nextX >= Size)
                continue;

            if (dataTwoArr[nextY][nextX] != -1 && !visited[nextY][nextX])
            {
                visited[nextY][nextX] = true;
                int idx = dataTwoArr[nextY][nextX];
                q.push(data[idx]);
                cnt++;
            }
        }
    }

    return false;
}

void Combination(const vector<pair<int, int>> &classMate, vector<pair<int, int>> &data, int idx, int depth)
{
    // 25명 중 7명을 뽑았고
    if (depth == 7)
    {
        // 7명 중 4명 이상이 원년 이다솜파라면
        if (GetOriginMemCnt(data) >= 4)
            // 이 7명이 모두 인접해있는지 탐색한다.
            if (IsAllAdjacent(data))
                answer++;

        return;
    }

    for (int i = idx; i < Size * Size; i++)
    {
        data[depth] = classMate[i];
        Combination(classMate, data, i + 1, depth + 1);
    }
}

int main()
{
    for (int i = 0; i < Size; i++)
        cin >> Input[i];

    vector<pair<int, int>> classMate(Size * Size);
    for (int i = 0; i < Size * Size; i++)
        classMate[i] = make_pair(i / 5, i % 5);

    vector<pair<int, int>> data(7);
    Combination(classMate, data, 0, 0);

    cout << answer;
}