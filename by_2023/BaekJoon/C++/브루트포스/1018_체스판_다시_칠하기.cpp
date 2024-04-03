//M*N 사각형(8<=(M,N)<=50)
//검은색, 흰색 체스판
//8*8 크기로 가공
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ChessBoard(int M, int N, vector<vector<bool>> board)
{
    vector<vector<bool>> perfect_board1(M, vector<bool>(N));
    vector<vector<bool>> perfect_board2(M, vector<bool>(N));
    vector<int> answer1((M - 7) * (N - 7));
    vector<int> answer2((M - 7) * (N - 7));

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                    perfect_board1[i][j] = 1;
                else
                    perfect_board2[i][j] = 1;
            }
            else
            {
                if (j % 2 == 1)
                    perfect_board1[i][j] = 1;
                else
                    perfect_board2[i][j] = 1;
            }
        }
    }

    int idx = 0;
    for (int k = 0; k < (M - 7); k++)
    {
        for (int g = 0; g < (N - 7); g++)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (perfect_board1[i][j] != board[i + k][j + g])
                        answer1[idx]++;
                    if (perfect_board2[i][j] != board[i + k][j + g])
                        answer2[idx]++;
                }
            }
            idx++;
        }
    }

    int min1 = *min_element(answer1.begin(), answer1.end());
    int min2 = *min_element(answer2.begin(), answer2.end());

    if (min1 < min2)
        cout << min1 << endl;
    else
        cout << min2 << endl;
}

int main()
{
    int M, N;
    cin >> M >> N;

    vector<vector<bool>> board(M, vector<bool>(N));

    string temp;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            if (temp[j] == 'W')
                board[i][j] = 1;
        }
    }

    ChessBoard(M, N, board);
}