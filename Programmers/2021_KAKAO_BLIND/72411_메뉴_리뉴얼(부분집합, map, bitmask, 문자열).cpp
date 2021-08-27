#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.first.size() < b.first.size())
        return true;
    else if (a.first.size() == b.first.size())
        return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    unordered_map<string, int> my_map;

    for (int k = 0; k < orders.size(); k++)
    {
        sort(orders[k].begin(), orders[k].end());

        for (int i = 1; i < (1 << orders[k].size()); i++)
        {
            string temp = "";
            for (int j = 0; j < orders[k].size(); j++)
            {
                if ((i & (1 << j)) != 0)
                    temp += orders[k][j];
            }

            for (int s = 0; s < course.size(); s++)
            {
                if (temp.size() == course[s])
                {
                    //cout << temp << endl;
                    my_map[temp]++;
                    break;
                }
            }
        }
    }

    vector<pair<string, int>> vec(my_map.begin(), my_map.end());
    sort(vec.begin(), vec.end(), cmp);

    int new_j = 0;
    for (int i = 0; i < course.size(); i++)
    {
        for (int j = new_j; j < vec.size(); j++)
        {
            if (vec[j].first.size() > course[i])
            {
                new_j = j;
                break;
            }

            if (vec[j].second >= 2)
                if (vec[j].second == vec[new_j].second)
                    answer.push_back(vec[j].first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2, 3, 4};

    vector<string> orders2 = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<int> course2 = {2, 3, 5};

    vector<string> orders3 = {"XYZ", "XWY", "WXA"};
    vector<int> course3 = {2, 3, 4};

    solution(orders3, course3);
}