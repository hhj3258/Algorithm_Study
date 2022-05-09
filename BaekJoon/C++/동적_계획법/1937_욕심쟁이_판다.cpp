#include <bits/stdc++.h>
using namespace std;

int n;

// 동, 서, 남, 북
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int dp[501][501];

int Solve(vector<vector<int>> &board, int y, int x)
{
    if (dp[y][x] != 0)
        return dp[y][x];

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n)
            continue;

        if (board[nextY][nextX] > board[y][x])
        {
            dp[y][x] = max(dp[y][x], Solve(board, nextY, nextX) + 1);
        }
    }

    return dp[y][x];
}

int main()
{
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            answer = max(answer, Solve(board, i, j));
        }

    cout << answer;
}