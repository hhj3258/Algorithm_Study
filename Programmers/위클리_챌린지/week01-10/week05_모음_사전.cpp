#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

set<string> mySet;
vector<char> alp = {'A', 'E', 'I', 'O', 'U'};
vector<char> temp(5);

//중복순열
void DFS_3(int cnt, int m)
{
    if (cnt == m)
    {
        string str = "";
        for (int i = 0; i < m; i++)
            str += temp[i];

        mySet.insert(str);

        return;
    }

    for (int i = 0; i < 5; i++)
    {
        temp[cnt] = alp[i];
        DFS_3(cnt + 1, m);
    }
}

int solution(string word)
{
    for (int i = 1; i <= 5; i++)
        DFS_3(0, i);

    vector<string> vec(mySet.begin(), mySet.end());
    auto lower = lower_bound(vec.begin(), vec.end(), word);
    int answer = lower - vec.begin() + 1;

    return answer;
}

int main()
{
    solution("I");
}