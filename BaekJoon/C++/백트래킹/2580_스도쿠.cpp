#include <iostream>
#include <vector>

#define SPACE 81
#define COL 9
using namespace std;

vector<int> board(SPACE);
int temp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int zero_cnt = 0;

bool Check(int k)
{
    for (int i = k + 1; i < COL; i++)
    {
        //가로
        if (board[k] == board[i])
            return 0;
        //세로
        if (board[k] == board[i + 8 * i])
            return 0;
    }

    return 1;
}

void Sudoku(int cnt, int num)
{
    if (zero_cnt == 0)
    {
        return;
    }

    for (int i = cnt; i < (COL + cnt); i++)
    {
        if (board[i] == 0)
        {
            for (int n = 1; n < 10; n++)
            {
                //cout << i + cnt << ' ';
                board[i] = n;

                if (Check(i))
                {
                    zero_cnt--;
                    Sudoku(cnt + COL, 1);
                    break;
                }
            }
        }
    }
}

int main()
{
    int num;
    vector<int> aa;
    for (int i = 0; i < SPACE; i++)
    {
        cin >> num;
        board[i] = num;
        if (num == 0)
        {
            zero_cnt++;
            aa.push_back(i);
        }
    }
    cout << endl;
    cout << "zeros: ";
    for (int i : aa)
        cout << i << ' ';
    cout << endl
         << endl;

    // for (int i = 0; i < SPACE; i++)
    // {
    //     if (i % 9 == 0)
    //         cout << '\n';
    //     cout << i << ' ';
    // }

    Sudoku(0, 1);

    cout << endl;
    for (int i = 0; i < SPACE; i++)
    {
        if (i % 9 == 0)
            cout << '\n';
        cout << board[i] << ' ';
    }
}