#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Prints(vector<vector<int>> game_board);
void Prints(vector<vector<bool>> game_board);
vector<set<pair<int, int>>> PuzzleDiv(vector<vector<int>> &tables);
vector<vector<pair<int, int>>> PuzzleReduction(vector<set<pair<int, int>>> test);

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
//조각 나누기
vector<set<pair<int, int>>> PuzzleDiv(vector<vector<int>> &tables)
{
    puzzle_idx = 0;
    vector<set<pair<int, int>>> test;
    for (int i = 0; i < tables.size(); i++)
    {
        for (int j = 0; j < tables[i].size(); j++)
        {
            if (tables[i][j] == 1)
            {
                set<pair<int, int>> temp;
                temp.insert(make_pair(i, j));
                test.push_back(temp);

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

//좌표 축소
vector<vector<pair<int, int>>> PuzzleReduction(vector<set<pair<int, int>>> test)
{
    vector<vector<pair<int, int>>> tempV;

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

//반시계방향 회전 90도
vector<vector<pair<int, int>>> TableRotation(vector<vector<pair<int, int>>> final_table)
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
    }

    return final_table;
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

    vector<vector<pair<int, int>>> final_table = PuzzleReduction(puzzles);
    final_table = TableRotation(final_table);

    cout << "<puzzles>\n";
    for (int i = 0; i < final_table.size(); i++)
    {
        for (int j = 0; j < final_table[i].size(); j++)
            cout << final_table[i][j].first << ' ' << final_table[i][j].second << endl;
        cout << endl;
    }

    //게임보드 0-1 변환
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

    vector<set<pair<int, int>>> boardBlanks = PuzzleDiv(game_board);
    vector<vector<pair<int, int>>> final_board = PuzzleReduction(boardBlanks);

    cout << "<board>\n";
    for (int i = 0; i < final_board.size(); i++)
    {
        for (int j = 0; j < final_board[i].size(); j++)
        {
            cout << final_board[i][j].first << ' ' << final_board[i][j].second << endl;
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