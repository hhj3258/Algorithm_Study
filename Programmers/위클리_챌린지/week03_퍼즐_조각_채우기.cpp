#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> PuzzleDivision2(vector<vector<int>> &tables);
vector<vector<pair<int, int>>> PuzzleRotation(vector<vector<pair<int, int>>> final_table);
vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> test);
int PuzzleMatching(vector<vector<pair<int, int>>> final_board, vector<vector<pair<int, int>>> final_table);
void GameBoardReversing(vector<vector<int>> &my_board);

vector<vector<int>> game_board = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
vector<vector<int>> table = {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}};

vector<vector<int>> game_board2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};
vector<vector<int>> table2 = {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}};

vector<vector<int>> game_board3 = {{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1}, {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
vector<vector<int>> table3 = {{1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1}, {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1}};

//-----------------------------------------------------------------------------------------------------

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    GameBoardReversing(game_board);

    vector<vector<pair<int, int>>> final_table = PuzzleDivision(table);

    vector<vector<pair<int, int>>> final_board = PuzzleDivision(game_board);

    int answer = PuzzleMatching(final_board, final_table);

    return answer;
}

// vector<vector<bool>> visited(table.size(), vector<bool>(table.size()));
vector<vector<pair<int, int>>> PuzzleDivision(vector<vector<int>> &tables)
{
    vector<vector<pair<int, int>>> result;

    while (true)
    {
        vector<pair<int, int>> temp;
        queue<pair<int, int>> q;
        for (int i = 0; i < tables.size(); i++)
        {
            for (int j = 0; j < tables.size(); j++)
            {
                if (tables[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    tables[i][j] = 0;
                    break;
                }
            }
            if (!q.empty())
                break;
        }

        if (q.empty())
            break;

        while (!q.empty())
        {
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            temp.push_back(q.front());
            //cout << q.front().first << "," << q.front().second << endl;
            q.pop();

            if (cur_j < tables.size() - 1 && tables[cur_i][cur_j + 1] == 1)
            {
                q.push(make_pair(cur_i, cur_j + 1));
                tables[cur_i][cur_j + 1] = 0;
            }

            if (cur_j > 0 && tables[cur_i][cur_j - 1] == 1)
            {
                q.push(make_pair(cur_i, cur_j - 1));
                tables[cur_i][cur_j - 1] = 0;
            }

            if (cur_i < tables.size() - 1 && tables[cur_i + 1][cur_j] == 1)
            {
                q.push(make_pair(cur_i + 1, cur_j));
                tables[cur_i + 1][cur_j] = 0;
            }

            if (cur_i > 0 && tables[cur_i - 1][cur_j] == 1)
            {
                q.push(make_pair(cur_i - 1, cur_j));
                tables[cur_i - 1][cur_j] = 0;
            }
        }

        sort(temp.begin(), temp.end());
        result.push_back(temp);
    }

    result = PuzzleReduction(result);

    return result;
}

//반시계방향 회전 90도
vector<vector<pair<int, int>>> PuzzleRotation(vector<vector<pair<int, int>>> final_table)
{
    for (int i = 0; i < final_table.size(); i++)
    {
        int N = -1;
        for (int j = 0; j < final_table[i].size(); j++)
        {
            if (final_table[i][j].first > N)
                N = final_table[i][j].first;
            if (final_table[i][j].second > N)
                N = final_table[i][j].second;
        }

        for (int j = 0; j < final_table[i].size(); j++)
            final_table[i][j] = make_pair(N - final_table[i][j].second, final_table[i][j].first);

        sort(final_table[i].begin(), final_table[i].end());
    }

    final_table = PuzzleReduction(final_table);

    return final_table;
}

//좌표 축소
vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> test)
{
    for (int i = 0; i < test.size(); i++)
    {
        int minI = 100;
        int minJ = 100;

        for (int j = 0; j < test[i].size(); j++)
        {
            if (test[i][j].first < minI)
                minI = test[i][j].first;
            if (test[i][j].second < minJ)
                minJ = test[i][j].second;
        }

        for (int j = 0; j < test[i].size(); j++)
        {
            test[i][j].first -= minI;
            test[i][j].second -= minJ;
        }
    }

    return test;
}

//퍼즐 맞추기
int PuzzleMatching(vector<vector<pair<int, int>>> final_board, vector<vector<pair<int, int>>> final_table)
{
    int result = 0;

    for (int r = 0; r < 4; r++)
    {
        for (int i = 0; i < final_board.size(); i++)
        {
            for (int j = 0; j < final_table.size(); j++)
            {
                if (final_board[i].size() == final_table[j].size())
                {
                    int cnt = 0;
                    for (int k = 0; k < final_board[i].size(); k++)
                    {
                        if (final_board[i][k] == final_table[j][k])
                            cnt++;
                        else
                        {
                            cnt = 0;
                            break;
                        }
                    }

                    if (cnt == final_board[i].size())
                    {
                        final_board.erase(final_board.begin() + i);
                        i--;
                        final_table.erase(final_table.begin() + j);
                        result += cnt;
                        break;
                    }
                }
            }
        }

        final_table = PuzzleRotation(final_table);
    }

    return result;
}

//게임보드 0-1 변환
void GameBoardReversing(vector<vector<int>> &my_board)
{
    for (int i = 0; i < my_board.size(); i++)
    {
        for (int j = 0; j < my_board[i].size(); j++)
        {
            if (my_board[i][j] == 1)
                my_board[i][j] = 0;
            else
            {
                my_board[i][j] = 1;
            }
        }
    }
}

int main()
{
    GameBoardReversing(game_board);

    vector<vector<pair<int, int>>> final_table = PuzzleDivision(table);

    vector<vector<pair<int, int>>> final_board = PuzzleDivision(game_board);

    int answer = PuzzleMatching(final_board, final_table);
    cout << answer << endl;
}