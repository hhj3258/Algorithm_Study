#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<vector<int>> game_board = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
vector<vector<int>> table = {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}};

vector<vector<int>> game_board2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};
vector<vector<int>> table2 = {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}};

vector<vector<int>> test_table = {{0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}};

void Prints(vector<vector<int>> game_board);
void Prints(vector<vector<bool>> game_board);

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = -1;
    return answer;
}

int puzzle_idx = 0;
vector<set<pair<int, int>>> PuzzleDiv(vector<vector<int>> &tables)
{
    vector<set<pair<int, int>>> test(table.size() * table.size());
    for (int i = 0; i < tables.size(); i++)
    {
        for (int j = 0; j < tables[i].size(); j++)
        {
            if (tables[i][j] == 1)
            {
                test[puzzle_idx].insert(make_pair(i, j));

                for (auto iter = test[puzzle_idx].begin(); iter != test[puzzle_idx].end(); iter++)
                {
                    int nowI = (*iter).first;
                    int nowJ = (*iter).second;

                    if (nowJ < tables.size() - 1 && tables[nowI][nowJ + 1] == 1)
                        test[puzzle_idx].insert(make_pair(nowI, nowJ + 1));

                    if (nowJ > 0 && tables[nowI][nowJ - 1] == 1)
                        test[puzzle_idx].insert(make_pair(nowI, nowJ - 1));

                    if (nowI < tables.size() - 1 && tables[nowI + 1][nowJ] == 1)
                        test[puzzle_idx].insert(make_pair(nowI + 1, nowJ));

                    if (nowI > 0 && tables[nowI - 1][nowJ] == 1)
                        test[puzzle_idx].insert(make_pair(nowI - 1, nowJ));
                }

                for (auto iter = test[puzzle_idx].begin(); iter != test[puzzle_idx].end(); iter++)
                    tables[(*iter).first][(*iter).second] = 0;

                puzzle_idx++;
            }
        }
    }

    return test;
}

int main()
{
    // Prints(game_board);
    // Prints(table);
    Prints(table);

    vector<set<pair<int, int>>> test = PuzzleDiv(table);

    cout << "main\n";
    for (int i = 0; i < puzzle_idx; i++)
    {
        for (auto iter = test[i].begin(); iter != test[i].end(); iter++)
            cout << (*iter).first << ' ' << (*iter).second << endl;
        cout << endl;
    }

    Prints(table);
}

void Prints(vector<vector<int>> game_board)
{
    int zero_cnt = 0;

    cout << "<Print>\n";
    for (int i = 0; i < game_board.size(); i++)
    {
        for (int j = 0; j < game_board[i].size(); j++)
        {
            if (game_board[i][j] == 0)
                zero_cnt++;
            cout << game_board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "zero_cnt: " << zero_cnt << endl;
    cout << endl;
}

void Prints(vector<vector<bool>> game_board)
{
    int zero_cnt = 0;

    cout << "<Visit>\n";
    for (int i = 0; i < game_board.size(); i++)
    {
        for (int j = 0; j < game_board[i].size(); j++)
        {
            if (game_board[i][j] == 0)
                zero_cnt++;
            cout << game_board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "zero_cnt: " << zero_cnt << endl;
    cout << endl;
}