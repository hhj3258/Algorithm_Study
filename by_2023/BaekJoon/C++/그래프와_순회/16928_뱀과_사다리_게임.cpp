#include <bits/stdc++.h>
using namespace std;

void Solve(const vector<int> &board, vector<int> &dice)
{
    queue<int> q;
    q.push(1);
    dice[1] = 0;

    while (!q.empty())
    {
        int pos = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int nextPos = pos + i;

            if (nextPos > 100)
                break;

            // 뱀 or 사다리라면 이동한다.
            nextPos = board[nextPos];

            // 방문한 적 없다면
            if (dice[nextPos] == -1)
            {
                dice[nextPos] = dice[pos] + 1;
                q.push(nextPos);
            }
        }
    }

    cout << dice[100];
}

int main()
{
    vector<int> board(101);
    vector<int> dice(101);
    for (int i = 1; i <= 100; i++)
    {
        board[i] = i;
        dice[i] = -1;
    }

    int N, M;
    cin >> N >> M;

    int start, end;
    for (int i = 0; i < N + M; i++)
    {
        cin >> start >> end;
        board[start] = end;
    }

    Solve(board, dice);
}