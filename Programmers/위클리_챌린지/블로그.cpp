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

vector<vector<int>> game_board = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
vector<vector<int>> table = {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}};

vector<vector<int>> game_board2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};
vector<vector<int>> table2 = {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}};

vector<vector<int>> game_board3 = {{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1}, {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
vector<vector<int>> table3 = {{1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1}, {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1}};

//-------------------------------------------------------------------------------------------------------------

//메인 실행 함수
int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    // 1) game_board의 원소들을 반전
    GameBoardReversing(game_board);

    // 2) game_board의 빈칸 덩어리들 탐색
    vector<vector<pair<int, int>>> boardBlanks = PuzzleDivision(game_board);

    cout << "<boardBlanks>\n";
    for (int i = 0; i < boardBlanks.size(); i++)
    {
        cout << "빈 칸 덩어리 " << i + 1 << endl;
        for (int j = 0; j < boardBlanks[i].size(); j++)
            cout << "[" << boardBlanks[i][j].first << "," << boardBlanks[i][j].second << "] ";
        cout << "\n\n";
    }
    cout << "----------------\n\n";

    // 3) table의 조각들 탐색
    vector<vector<pair<int, int>>> puzzles = PuzzleDivision(table);

    cout << "<puzzles>\n";
    for (int i = 0; i < puzzles.size(); i++)
    {
        cout << "퍼즐 " << i + 1 << endl;
        for (int j = 0; j < puzzles[i].size(); j++)
            cout << "[" << puzzles[i][j].first << "," << puzzles[i][j].second << "] ";
        cout << "\n\n";
    }
    cout << "----------------\n\n";

    // 4) 3번에서 찾은 조각들을 2번에서 찾은 빈칸들과 비교하며 퍼즐 맞추기
    int answer = PuzzleMatching(boardBlanks, puzzles);

    cout << "answer: " << answer << endl;
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
//PuzzleDivision 함수와 PuzzleRotation 함수에서 사용
vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> puzzles)
{
    //퍼즐 갯수만큼 반복
    for (int i = 0; i < puzzles.size(); i++)
    {
        int minI = 1000;
        int minJ = 1000;

        //각 퍼즐 길이만큼 반복
        for (int j = 0; j < puzzles[i].size(); j++)
        {
            //minI = min(puzzles[i][0]의 행 값 ~ puzzles[i][마지막 값]의 행 값)
            if (puzzles[i][j].first < minI)
                minI = puzzles[i][j].first;

            //minI = min(puzzles[i][0]의 열 값 ~ puzzles[i][마지막 값]의 열 값)
            if (puzzles[i][j].second < minJ)
                minJ = puzzles[i][j].second;
        }

        //각 퍼즐 길이만큼 반복
        for (int j = 0; j < puzzles[i].size(); j++)
        {
            //puzzles[i][j]]의 행 값 -= minI
            puzzles[i][j].first -= minI;
            //puzzles[i][j]]의 열 값 -= minJ
            puzzles[i][j].second -= minJ;
        }
    }

    return puzzles;
}

//퍼즐 나누기
//BFS를 이용해서 탐색
vector<vector<pair<int, int>>> PuzzleDivision(vector<vector<int>> &tables)
{
    //return 해줄 퍼즐을 저장할 것
    vector<vector<pair<int, int>>> result;
    //중복 탐색을 줄여서 탐색 효율 증가
    int last_i = 0;

    while (true)
    {
        vector<pair<int, int>> temp; //퍼즐 한 개를 저장하기 위한 temp
        queue<pair<int, int>> q;     //BFS 탐색을 위한 큐

        //퍼즐의 첫번째 원소를 찾으면 큐에 push
        for (int i = last_i; i < tables.size(); i++)
        {
            for (int j = 0; j < tables.size(); j++)
            {
                if (tables[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    tables[i][j] = 0; //인풋으로 주어진 table을 visited 대용으로 사용
                    last_i = i;       //마지막으로 탐색한 i를 저장하여 다음부터는 last_i부터 탐색
                    break;
                }
            }

            //퍼즐의 첫번째 원소를 찾았다면 break
            if (!q.empty())
                break;
        }

        //퍼즐이 더이상 없다면 탐색 종료
        if (q.empty())
            break;

        while (!q.empty())
        {
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            temp.push_back(q.front()); //퍼즐의 원소들을 저장
            q.pop();

            //퍼즐 원소의 상,하,좌,우를 탐색해보고 존재한다면
            //큐에 push하고 방문한 위치 표시
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

        //퍼즐 한 개의 탐색을 마치면 result에 저장
        result.push_back(temp);
    }

    //모든 퍼즐들의 좌표 변경
    result = PuzzleReduction(result);
    return result;
}

//행렬 회전: -90도 회전(반시계방향)
//퍼즐 하나를 가상으로 정사각 행렬로 치환하여 회전
//PuzzleMatching 함수에서 사용
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
            //-90도 회전한 퍼즐[i, j] = 기존 퍼즐[N - puzzles[i][j]의 j, puzzles[i][j]의 i]
            puzzles[i][j] = make_pair(N - puzzles[i][j].second, puzzles[i][j].first);

        sort(puzzles[i].begin(), puzzles[i].end());
    }

    //모든 퍼즐들의 좌표 변경
    puzzles = PuzzleReduction(puzzles);
    return puzzles;
}

//퍼즐 맞추기
int PuzzleMatching(vector<vector<pair<int, int>>> boardBlanks, vector<vector<pair<int, int>>> puzzles)
{
    cout << "<PuzzleMatching>\n";
    int temp_cnt = 1;
    int answer = 0; //answer = 채워진 칸 수

    //회전 4번만큼 반복
    for (int r = 0; r < 4; r++)
    {
        //board의 빈 칸 덩어리 갯수만큼 반복
        for (int i = 0; i < boardBlanks.size(); i++)
        {
            //퍼즐 갯수만큼 반복
            for (int j = 0; j < puzzles.size(); j++)
            {
                //빈 칸 덩어리 크기와 퍼즐 크기가 같다면 같은지 조사
                if (boardBlanks[i].size() == puzzles[j].size())
                {
                    int k = 0;
                    //빈 칸 덩어리 크기만큼 반복
                    for (k = 0; k < boardBlanks[i].size(); k++)
                        //빈 칸 좌표와 퍼즐 좌표가 하나라도 다르다면 break
                        if (boardBlanks[i][k] != puzzles[j][k])
                            break;

                    //모든 좌표가 동일하다면
                    if (k == boardBlanks[i].size())
                    {
                        cout << "회전: " << r * -90 << "도" << endl;
                        cout << "매칭: boardBlanks " << i + temp_cnt++ << " & puzzle" << endl;
                        cout << "[i,j]: ";
                        for (int x = 0; x < puzzles[j].size(); x++)
                            cout << "[" << puzzles[j][x].first << "," << puzzles[j][x].second << "] ";
                        cout << "\n\n";

                        //해당 빈 칸 덩어리와 퍼즐이 매칭되었으므로 삭제
                        boardBlanks.erase(boardBlanks.begin() + i);
                        puzzles.erase(puzzles.begin() + j);
                        i--;

                        answer += k; //answer += 채워진 칸 수
                        break;
                    }
                }
            } //end_for_j
        }     //end_for_i

        //퍼즐을 회전시키면서 매칭
        puzzles = PuzzleRotation(puzzles);
    } //end_for_r

    return answer;
}

int main()
{
    solution(game_board, table);
}