#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> table = {"SI JAVA JAVASCRIPT SQL PYTHON C#",
                        "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
                        "HARDWARE C C++ PYTHON JAVA JAVASCRIPT",
                        "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
                        "GAME C++ C# JAVASCRIPT C JAVA"};
vector<string> languages = {"PYTHON", "C++", "SQL"};
vector<int> preference = {7, 5, 5};

vector<vector<string>> TableOrganize(vector<string> table);
string FindHighScoreJob(vector<vector<string>> new_table, vector<string> languages, vector<int> preference);

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    //테이블 재구성
    vector<vector<string>> new_table = TableOrganize(table);

    for (int i = 0; i < new_table.size(); i++)
    {
        for (int j = 0; j < new_table[i].size(); j++)
        {
            cout << new_table[i][j] << ", ";
        }
        cout << endl;
    }

    //가장 높은 점수를 얻은 직업군 탐색
    string answer = FindHighScoreJob(new_table, languages, preference);

    return answer;
}

//{SI, JAVA, JAVASCRIPT, SQL, PYTHON, C#}, ... 공백 기준으로 열을 잘라서 재구성
vector<vector<string>> TableOrganize(vector<string> table)
{
    //재구성할 테이블 원소들을 담을 2차원 배열
    vector<vector<string>> new_table(5);

    //table 행 길이만큼 반복
    for (int i = 0; i < table.size(); i++)
    {
        string temp = "";
        //table 열 길이만큼 반복
        for (int j = 0; j < table[i].size(); j++)
        {
            //table[i][j]가 공백이 아니라면
            if (table[i][j] != ' ')
                //temp에 table[i][j]를 더해줌
                temp += table[i][j];
            else
            {
                //table[i][j]가 공백이라면 새로운 테이블에 temp를 넣어주고
                new_table[i].push_back(temp);
                //temp를 비워줌
                temp = "";
            }
        }
        //table[i]의 마지막 원소가 공백이 아니므로 따로 1점짜리 언어를 넣어줌
        new_table[i].push_back(temp);
    }

    return new_table;
}

string FindHighScoreJob(vector<vector<string>> new_table, vector<string> languages, vector<int> preference)
{
    vector<int> scores(5);

    //조사할 언어만큼 반복
    for (int l = 0; l < languages.size(); l++)
        //5개 직업군만큼 반복
        for (int i = 0; i < new_table.size(); i++)
            //5개 언어 종류만큼 반복
            for (int j = 1; j < new_table[i].size(); j++)
                // ex1) new_table[0][4]==languages[0]
                // ex1) PYTHON==PYTHON
                if (new_table[i][j] == languages[l])
                    // ex1) scores[0] += 7 * (6 - 4);
                    scores[i] += preference[l] * (6 - j);

    //maxV = 직업군별 점수 중 가장 높은 점수
    int maxV = *max_element(scores.begin(), scores.end());

    vector<string> temp;
    //가장 높은 점수가 2개 이상일 수 있으므로
    //5개 직업군만큼 반복하며 maxV와 같은 scores[i] 값이 있다면 temp에 저장
    for (int i = 0; i < 5; i++)
        if (scores[i] == maxV)
            temp.push_back(new_table[i][0]);

    //temp에 저장된 값 중 가장 작은 값(사전 순으로 가장 빠른 직업군) return
    return *min_element(temp.begin(), temp.end());
}

int main()
{
    cout << solution(table, languages, preference);
}