#include <iostream>
using namespace std;

int board[65][65];

const int WHITE = 0;
const int BLACK = 1;

void Solve(int y, int x, int length)
{
    int white_cnt = 0;
    int black_cnt = 0;

    for (int i = y; i < y + length; i++)
    {
        for (int j = x; j < x + length; j++)
        {
            if (board[i][j] == WHITE)
                white_cnt++;
            if (board[i][j] == BLACK)
                black_cnt++;
        }
    }

    if (white_cnt > 0 && black_cnt > 0)
    {
        cout << "(";

        // 왼쪽 위
        Solve(y, x, length / 2);
        // 오른쪽 위
        Solve(y, x + (length / 2), length / 2);
        // 왼쪽 아래
        Solve(y + (length / 2), x, length / 2);
        // 오른쪽 아래
        Solve(y + (length / 2), x + (length / 2), length / 2);

        cout << ")";
    }
    else if (white_cnt > 0)
        cout << WHITE;
    else if (black_cnt > 0)
        cout << BLACK;
}

int main()
{
    int N;
    cin >> N;

    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        for (int j = 0; j < N; j++)
            board[i][j] = temp[j] - '0';
    }

    Solve(0, 0, N);
}