#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<pair<int, int>> zeroV;

int zero_cnt = 0;
bool complete = false;

bool Check(int row, int col)
{
    int nineX = row / 3;
    int nineY = col / 3;

    for (int i = nineX * 3; i < nineX * 3 + 3; i++)
    {
        for (int j = nineY * 3; j < nineY * 3 + 3; j++)
        {
            if (board[row][col] == board[i][j])
                if (i != row && j != col)
                    return 0;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (i != row && board[row][col] == board[i][col])
            return 0;

        if (i != col && board[row][col] == board[row][i])
            return 0;
    }

    return 1;
}

void Sudoku(int idx)
{
    if (zero_cnt == idx)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';

        complete = true;
        return;
    }

    for (int n = 1; n < 10; n++)
    {
        board[zeroV[idx].first][zeroV[idx].second] = n;

        if (Check(zeroV[idx].first, zeroV[idx].second))
            Sudoku(idx + 1);

        if (complete)
            return;
    }

    board[zeroV[idx].first][zeroV[idx].second] = 0;
}

int main()
{
    int input;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> input;
            board[i][j] = input;

            if (input == 0)
            {
                zero_cnt++;
                zeroV.push_back(make_pair(i, j));
            }
        }
    }

    Sudoku(0);
}