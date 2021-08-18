#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

void GameBoardReversing(vector<vector<int>> &my_board);
vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> puzzles);
vector<vector<pair<int, int>>> PuzzleDivision(vector<vector<int>> &tables);
vector<vector<pair<int, int>>> PuzzleRotation(vector<vector<pair<int, int>>> puzzles);
int PuzzleMatching(vector<vector<pair<int, int>>> boardBlanks, vector<vector<pair<int, int>>> puzzles);

//메인 실행 함수
int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    // 1) game_board의 원소들을 반전
    GameBoardReversing(game_board);

    // 2) game_board의 빈칸 덩어리들 탐색
    vector<vector<pair<int, int>>> boardBlanks = PuzzleDivision(game_board);

    // 3) table의 조각들 탐색
    vector<vector<pair<int, int>>> puzzles = PuzzleDivision(table);

    // 4) 3번에서 찾은 조각들을 2번에서 찾은 빈칸들과 비교하며 퍼즐 맞추기
    int answer = PuzzleMatching(boardBlanks, puzzles);

    return answer;
}

//게임보드 0-1 반전
void GameBoardReversing(vector<vector<int>> &my_board)
{
    for (int i = 0; i < my_board.size(); i++)
    {
        for (int j = 0; j < my_board[i].size(); j++)
        {
            if (my_board[i][j])
                my_board[i][j] = 0;
            else
                my_board[i][j] = 1;
        }
    }
}

//보드의 빈칸 덩어리들과 퍼즐들의 좌표를 [0,0] 기준으로 변경
vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> puzzles)
{
    for (int i = 0; i < puzzles.size(); i++)
    {
        int minI = 1000;
        int minJ = 1000;

        for (int j = 0; j < puzzles[i].size(); j++)
        {
            if (puzzles[i][j].first < minI)
                minI = puzzles[i][j].first;

            if (puzzles[i][j].second < minJ)
                minJ = puzzles[i][j].second;
        }

        for (int j = 0; j < puzzles[i].size(); j++)
        {
            puzzles[i][j].first -= minI;
            puzzles[i][j].second -= minJ;
        }
    }

    return puzzles;
}

//퍼즐 나누기
vector<vector<pair<int, int>>> PuzzleDivision(vector<vector<int>> &tables)
{
    vector<vector<pair<int, int>>> result;
    int new_i = 0;

    while (true)
    {
        vector<pair<int, int>> temp;
        queue<pair<int, int>> q;

        for (int i = new_i; i < tables.size(); i++)
        {
            for (int j = 0; j < tables.size(); j++)
            {
                if (tables[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    tables[i][j] = 0;
                    new_i = i;
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
            q.pop();

            if (cur_i > 0 && tables[cur_i - 1][cur_j]) //상
            {
                q.push(make_pair(cur_i - 1, cur_j));
                tables[cur_i - 1][cur_j] = 0;
            }
            if (cur_i < tables.size() - 1 && tables[cur_i + 1][cur_j]) //하
            {
                q.push(make_pair(cur_i + 1, cur_j));
                tables[cur_i + 1][cur_j] = 0;
            }
            if (cur_j > 0 && tables[cur_i][cur_j - 1]) //좌
            {
                q.push(make_pair(cur_i, cur_j - 1));
                tables[cur_i][cur_j - 1] = 0;
            }
            if (cur_j < tables.size() - 1 && tables[cur_i][cur_j + 1]) //우
            {
                q.push(make_pair(cur_i, cur_j + 1));
                tables[cur_i][cur_j + 1] = 0;
            }
        }

        sort(temp.begin(), temp.end());

        result.push_back(temp);
    }

    result = PuzzleReduction(result);
    return result;
}

//행렬 회전: -90도 회전(반시계방향)
vector<vector<pair<int, int>>> PuzzleRotation(vector<vector<pair<int, int>>> puzzles)
{
    for (int i = 0; i < puzzles.size(); i++)
    {
        int N = -1;
        //N = max(puzzles[i][j].first || puzzles[i][j].second)
        for (int j = 0; j < puzzles[i].size(); j++)
        {
            if (puzzles[i][j].first > N)
                N = puzzles[i][j].first;

            if (puzzles[i][j].second > N)
                N = puzzles[i][j].second;
        }

        for (int j = 0; j < puzzles[i].size(); j++)
            puzzles[i][j] = make_pair(N - puzzles[i][j].second, puzzles[i][j].first);

        sort(puzzles[i].begin(), puzzles[i].end());
    }

    puzzles = PuzzleReduction(puzzles);
    return puzzles;
}

//퍼즐 맞추기
int PuzzleMatching(vector<vector<pair<int, int>>> boardBlanks, vector<vector<pair<int, int>>> puzzles)
{
    int temp_cnt = 1;
    int answer = 0;

    for (int r = 0; r < 4; r++)
    {
        for (int i = 0; i < boardBlanks.size(); i++)
        {
            for (int j = 0; j < puzzles.size(); j++)
            {
                if (boardBlanks[i].size() == puzzles[j].size())
                {
                    int k = 0;
                    for (k = 0; k < boardBlanks[i].size(); k++)
                        if (boardBlanks[i][k] != puzzles[j][k])
                            break;

                    if (k == boardBlanks[i].size())
                    {
                        boardBlanks.erase(boardBlanks.begin() + i);
                        puzzles.erase(puzzles.begin() + j);
                        i--;

                        answer += k;
                        break;
                    }
                }
            } //end_for_j
        }     //end_for_i

        puzzles = PuzzleRotation(puzzles);
    } //end_for_r

    return answer;
}