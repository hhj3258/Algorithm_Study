#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

unordered_map<string, int> m;
vector<int> List[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query)
{
    m["-"] = 0; //query에서만 쓰임

    m["cpp"] = 1;
    m["java"] = 2;
    m["python"] = 3;

    m["backend"] = 1;
    m["frontend"] = 2;

    m["junior"] = 1;
    m["senior"] = 2;

    m["chicken"] = 1;
    m["pizza"] = 2;

    for (auto str : info)
    {
        stringstream ss(str);
        string a, b, c, d; // 언어, 직군, 경력, 소울푸드
        int score;
        //java backend junior pizza 150
        ss >> a >> b >> c >> d >> score;
        //arr[4] = {2, 1, 1, 2};
        int arr[4] = {m[a], m[b], m[c], m[d]};

        //공집합도 구한다(모든 조건이 '-'인 경우)
        for (int i = 0; i < (1 << 4); i++)
        {
            int idx[4] = {0};
            for (int j = 0; j < 4; j++)
            {
                if ((i & (1 << j)))
                {
                    idx[j] = arr[j];
                }
            }
            for (int x = 0; x < 4; x++)
                cout << idx[x] << ' ';
            cout << score << endl;

            List[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
        }
        cout << endl;
    }

    for (int a = 0; a < 4; a++)
        for (int b = 0; b < 3; b++)
            for (int c = 0; c < 3; c++)
                for (int d = 0; d < 3; d++)
                    sort(List[a][b][c][d].begin(), List[a][b][c][d].end());

    vector<int> answer;

    for (auto str : query)
    {
        stringstream ss(str);
        string a, b, c, d, temp;
        int score;
        ss >> a >> temp >> b >> temp >> c >> temp >> d >> score;

        auto lists = List[m[a]][m[b]][m[c]][m[d]];
        auto lower = lower_bound(lists.begin(), lists.end(), score);

        answer.push_back(lists.end() - lower);
    }

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