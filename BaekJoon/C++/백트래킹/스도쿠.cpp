#include <iostream>
#include <vector>
#define SPACE 81
using namespace std;

vector<vector<int>> board(SPACE, vector<int>(SPACE));
int zero_cnt = 0;

bool Check(int row, int col)
{
    for (int i = row + 1; i < 9; i++)
    {
        if (board[row][col] == board[row][i])
            return 0;

        if (board[row][col] == board[i][col])
            return 0;
    }

    return 1;
}

void Sudoku(int row)
{
    if (zero_cnt == 0)
        return;

    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == 0)
        {
            for (int n = 1; n < 10; n++)
            {
                board[row][i] = n;

                if (Check(row, i))
                {
                    Sudoku(row + 9);
                }
            }
        }
    }
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
                zero_cnt++;
        }
    }
    cout << endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

    Sudoku(0);
}