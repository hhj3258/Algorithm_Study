#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Prints(vector<vector<int>> game_board);
void Prints(vector<vector<bool>> game_board);
vector<set<pair<int, int>>> PuzzleDiv(vector<vector<int>> &tables);
vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> tempV, vector<set<pair<int, int>>> test);

vector<vector<int>> game_board = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
vector<vector<int>> table = {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}};

vector<vector<int>> game_board2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};
vector<vector<int>> table2 = {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}};

vector<vector<int>> test_table = {{0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}};

//-----------------------------------------------------------------------------------------------------

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = -1;
    return answer;
}

int puzzle_idx = 0;
vector<set<pair<int, int>>> PuzzleDiv(vector<vector<int>> &tables)
{
    vector<set<pair<int, int>>> test;
    for (int i = 0; i < tables.size(); i++)
    {
        for (int j = 0; j < tables[i].size(); j++)
        {
            if (tables[i][j] == 1)
            {
                set<pair<int, int>> temp;
                test.push_back(temp);
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

vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> tempV, vector<set<pair<int, int>>> test)
{
    for (int i = 0; i < puzzle_idx; i++)
    {
        tempV.push_back(vector<pair<int, int>>(0));
        for (auto iter = test[i].begin(); iter != test[i].end(); iter++)
            tempV[i].push_back(*iter);

        int minI = 100;
        int minJ = 100;
        for (int j = 0; j < tempV[i].size(); j++)
        {
            if (tempV[i][j].first < minI)
                minI = tempV[i][j].first;
            if (tempV[i][j].second < minJ)
                minJ = tempV[i][j].second;
        }
        for (int j = 0; j < tempV[i].size(); j++)
        {
            tempV[i][j].first -= minI;
            tempV[i][j].second -= minJ;
        }
    }

    return tempV;
}

int main()
{
    // Prints(game_board);
    // Prints(table);
    Prints(game_board);

    vector<set<pair<int, int>>> puzzles = PuzzleDiv(table);

    cout << "main\n";

    // for (int i = 0; i < puzzle_idx; i++)
    // {
    //     for (auto iter = puzzles[i].begin(); iter != puzzles[i].end(); iter++)
    //         cout << (*iter).first << ' ' << (*iter).second << endl;
    //     cout << endl;
    // }

    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < N; j++)
    //         temp_arr[i][j] = arr[N - j - 1][i];

    vector<vector<pair<int, int>>> tempV;
    tempV = PuzzleReduction(tempV, puzzles);

    cout << "<puzzles>\n";
    for (int i = 0; i < tempV.size(); i++)
    {
        for (int j = 0; j < tempV[i].size(); j++)
            cout << tempV[i][j].first << ' ' << tempV[i][j].second << endl;
        cout << endl;
    }

    for (int i = 0; i < game_board.size(); i++)
    {
        for (int j = 0; j < game_board[i].size(); j++)
        {
            if (game_board[i][j] == 1)
                game_board[i][j] = 0;
            else
                game_board[i][j] = 1;
        }
    }
    cout << "chk1";
    vector<set<pair<int, int>>> boardBlanks = PuzzleDiv(game_board);
    cout << "chk2";
    vector<vector<pair<int, int>>> boardBlanksReduct;
    cout << "chk3";
    boardBlanksReduct = PuzzleReduction(boardBlanksReduct, boardBlanks);
    cout << "chk4";
    cout << "<board>\n";

    for (int i = 0; i < boardBlanksReduct.size(); i++)
    {
        for (int j = 0; j < boardBlanksReduct[i].size(); j++)
        {
            cout << "ij: " << i << " " << j << endl;
            cout << boardBlanksReduct[i][j].first << ' ' << boardBlanksReduct[i][j].second << endl;
        }
        cout << endl;
    }

    Prints(game_board);
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