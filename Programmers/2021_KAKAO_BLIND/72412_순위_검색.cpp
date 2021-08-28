//info "개발언어 3, 직군 2, 경력 2, 소울푸드 2, 점수" -> 공백으로 구분

//[조건]은 "개발언어 and 직군 and 경력 and 소울푸드" 형식의 문자열
//'-' 표시는 해당 조건을 고려하지 않겠다는 의미입니다.
//ex)  "cpp and - and senior and pizza 500"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer(query.size());

    vector<vector<string>> new_info(info.size());
    for (int i = 0; i < new_info.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < info[i].size(); j++)
        {
            if (info[i][j] == ' ')
            {
                new_info[i].push_back(temp);
                temp.clear();
            }
            else
            {
                temp += info[i][j];
            }
        }
        new_info[i].push_back(temp);
    }

    // for (int i = 0; i < new_info.size(); i++)
    // {
    //     for (int j = 0; j < new_info[i].size(); j++)
    //     {
    //         cout << new_info[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    vector<vector<string>> new_query(query.size());
    for (int i = 0; i < new_query.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < query[i].size(); j++)
        {
            if (query[i][j] == ' ')
            {
                new_query[i].push_back(temp);
                temp.clear();
            }
            else
            {
                temp += query[i][j];
            }
        }
        new_query[i].push_back(temp);
    }

    for (int i = 0; i < new_query.size(); i++)
    {
        for (int j = 0; j < new_query[i].size(); j++)
        {
            if (new_query[i][j] == "and")
            {
                new_query[i].erase(new_query[i].begin() + j);
                j--;
            }
        }
    }

    // for (int i = 0; i < new_query.size(); i++)
    // {
    //     for (int j = 0; j < new_query[i].size(); j++)
    //     {
    //         cout << new_query[i][j] << ", ";
    //     }
    //     cout << endl;
    // }

    //개발팀 행 크기
    for (int i = 0; i < new_query.size(); i++)
    {
        vector<string> now_q = new_query[i];

        for (int a = 0; a < new_info.size(); a++)
        {
            bool flag = false;
            for (int b = 0; b < new_info[a].size(); b++)
            {
                if (b == new_info[a].size() - 1)
                {
                    int x = stoi(new_info[a][b]);
                    int y = stoi(now_q[b]);
                    if (x >= y)
                        flag = true;
                    else
                        flag = false;
                }
                else if (new_info[a][b] == now_q[b] || now_q[b] == "-")
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                // cout << i << endl;
                // for (int x = 0; x < new_info[a].size(); x++)
                // {
                //     cout << new_info[a][x] << ' ';
                // }
                // cout << endl;
                // for (int x = 0; x < new_info[a].size(); x++)
                // {
                //     cout << now_q[x] << ' ';
                // }
                // cout << endl
                //      << endl;

                answer[i]++;
            }
        }
    }

    // for (int a = 0; a < new_info.size(); a++)
    // {
    //     for (int b = 0; b < new_info[a].size(); b++)
    //     {
    //         if (new_info[a][b] == new_query[i][j])
    //         {
    //         }
    //     }
    // }

    return answer;
}

int main()
{
    vector<string> info = {"java backend junior pizza 150",
                           "python frontend senior chicken 210",
                           "python frontend senior chicken 150",
                           "cpp backend senior pizza 260",
                           "java backend junior chicken 80",
                           "python backend senior chicken 50"};

    vector<string> query = {"java and backend and junior and pizza 100",
                            "python and frontend and senior and chicken 200",
                            "cpp and - and senior and pizza 250",
                            "- and backend and senior and - 150",
                            "- and - and - and chicken 100",
                            "- and - and - and - 150"};

    vector<int> answer = solution(info, query);
    cout << "\nanswer\n";
    for (int i : answer)
        cout << i << ' ';
    cout << endl;
}