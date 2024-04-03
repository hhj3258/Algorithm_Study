#include <bits/stdc++.h>
using namespace std;

int N;

long long dp[101][101];

// 동, 남
int dy[] = {0, 1};
int dx[] = {1, 0};

long long Solve(vector<vector<int>> &board, int y, int x)
{
    // 오직 목표점에 도달했을 때만 1 리턴
    if (y == N - 1 && x == N - 1)
    {
        return 1;
    }

    // 이미 방문했던 곳은 다시 방문할 필요가 없다.
    // 만약 방문했던 곳이 목표점에 도달할 수 있는 경로였다면 1을 반환할 것이고
    // 목표점에 도달할 수 없는 경로라면 0을 리턴할 것이다.
    if (dp[y][x] != -1)
        return dp[y][x];

    // 방문한 곳은 0으로 표시한다.
    dp[y][x] = 0;

    for (int i = 0; i < 2; i++)
    {
        int nextY = y + dy[i] * board[y][x];
        int nextX = x + dx[i] * board[y][x];

        if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
            continue;

        dp[y][x] += Solve(board, nextY, nextX);
    }

    return dp[y][x];
}

int main()
{
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            dp[i][j] = -1;
        }

    cout << Solve(board, 0, 0);
}