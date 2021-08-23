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

vector<vector<string>> TableOrganize(vector<string> table)
{
    vector<vector<string>> new_table(5);

    for (int i = 0; i < table.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < table[i].size(); j++)
        {
            if (table[i][j] == ' ')
            {
                new_table[i].push_back(temp);
                temp = "";
                continue;
            }

            temp += table[i][j];
        }
        new_table[i].push_back(temp);
    }

    return new_table;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    string answer = "";
    vector<vector<string>> new_table = TableOrganize(table);

    vector<int> scores(5);
    //조사할 언어만큼 반복
    for (int l = 0; l < languages.size(); l++)
        //5개 직업군만큼 반복
        for (int i = 0; i < new_table.size(); i++)
            //5개 언어 종류만큼 반복
            for (int j = 0; j < new_table[i].size(); j++)
                if (new_table[i][j] == languages[l])
                    scores[i] += preference[l] * (6 - j);

    int maxV = *max_element(scores.begin(), scores.end());

    vector<string> temp;
    for (int i = 0; i < 5; i++)
        if (scores[i] == maxV)
            temp.push_back(new_table[i][0]);

    sort(temp.begin(), temp.end());

    answer = temp[0];
    return answer;
}

int main()
{
    cout << solution(table, languages, preference);
}