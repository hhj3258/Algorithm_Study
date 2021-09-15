#include <bits/stdc++.h>
using namespace std;

int N, M;
int r, c, d;
//d = 0:북, 1:동, 2:남, 3:서

void Solve(vector<vector<int>> &room)
{
    room[r][c] = 2; // 초기 위치 청소

    while (true)
    {
        // 사방이 모두 빈 공간이 아니라면
        if (room[r][c - 1] != 0 && room[r - 1][c] != 0 && room[r][c + 1] != 0 && room[r + 1][c] != 0)
        {
            //방향에 따른 후진
            if (d == 0)
                r += 1;
            else if (d == 1)
                c -= 1;
            else if (d == 2)
                r -= 1;
            else
                c += 1;

            //후진하고보니 벽이라면 종료
            if (room[r][c] == 1)
                break;

            continue;
        }

        //북쪽을 보고 있다면
        if (d == 0)
        {
            //서쪽 칸이 빈 공간이라면
            if (room[r][c - 1] == 0)
            {
                //서쪽 칸 청소
                room[r][--c] = 2;
                //청소기 방향을 서쪽으로 변경
                d = 3;
            }
            //서쪽 칸이 벽 또는 청소한 곳이라면
            else
                //방향만 변경
                d = 3;
        }
        else if (d == 1)
        {
            if (room[r - 1][c] == 0)
            {
                room[--r][c] = 2;
                d = 0;
            }
            else
                d = 0;
        }
        else if (d == 2)
        {
            if (room[r][c + 1] == 0)
            {
                room[r][++c] = 2;
                d = 1;
            }
            else
                d = 1;
        }
        else if (d == 3)
        {
            if (room[r + 1][c] == 0)
            {
                room[++r][c] = 2;
                d = 2;
            }
            else
                d = 2;
        }
    }

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
    cin >> r >> c >> d;

    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    Solve(room);
}