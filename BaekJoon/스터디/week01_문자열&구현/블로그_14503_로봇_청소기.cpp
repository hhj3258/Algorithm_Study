#include <bits/stdc++.h>
using namespace std;

int N, M;
int y, x, dir;

// 다음으로 청소할 공간 체크
bool CanGo(int y, int x, const vector<vector<int>> &room)
{
    // 청소가 안되어 있다면 true
    if (room[y][x] == 0)
        return true;
    // 청소가 되어있거나 벽이라면 false
    else
        return false;
}

void Solve(vector<vector<int>> &room)
{
    // 0: 북, 1: 동, 2: 남, 3: 서

    // 방향에 따른 청소기의 전진
    int dy[] = {0, -1, 0, 1};
    int dx[] = {-1, 0, 1, 0};

    // 방향에 따른 청소기의 후진
    int back_dy[] = {1, 0, -1, 0};
    int back_dx[] = {0, -1, 0, 1};

    while (true)
    {
        //현재 위치 청소
        room[y][x] = 2;

        // 동서남북이 모두 청소 전인지 체크
        bool isAllCleaned = true;
        for (int i = 0; i < 4; i++)
            if (room[y + dy[i]][x + dx[i]] == 0)
                isAllCleaned = false;

        // 모두 청소가 되어있다면
        if (isAllCleaned)
        {
            // 후진
            y = y + back_dy[dir];
            x = x + back_dx[dir];

            // 후진하고 보니 벽이라면 종료
            if (room[y][x] == 1)
                break;
            // 벽이 아니라면 1번 조건으로 돌아가자
            else
                continue;
        }

        // 방향에 따른 청소기의 다음 목적지를 임시 세팅
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        // 전진이 가능하다면
        if (CanGo(nextY, nextX, room))
        {
            // 청소기의 다음 목적지 세팅
            y = nextY;
            x = nextX;
        }

        // 왼쪽으로 방향 변경: 북 -> 서 -> 남 -> 동 -> 북 -> ...
        if (dir == 0)
            dir += 3;
        else
            dir--;
    }

    // 청소한 공간 갯수 검사
    int answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (room[i][j] == 2)
                answer++;

    cout << answer;
}

int main()
{
    cin >> N >> M;
    cin >> y >> x >> dir;

    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    Solve(room);
}