#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

bool check(vector<int> answer, int subset)
{
    //최소성 검사
    //지금까지 들어온 answer가 유일성 검사를 통과한 subset의 부분집합인지 확인
    for (int i = 0; i < answer.size(); i++)
    {
        //부분집합이라면 최소성 검사 실패
        if ((answer[i] & subset) == answer[i])
            return false;
    }

    return true;
}

int solution(vector<vector<string>> relation)
{
    vector<int> answer;
    //열에서의 부분집합의 경우의 수 = 1 << relation[0].size()
    for (int i = 1; i < (1 << relation[0].size()); i++)
    {
        set<string> mySet;
        //유일성 검사
        //모든 행을 돌며 검사
        for (int j = 0; j < relation.size(); j++)
        {
            string temp = "";

            for (int k = 0; k < relation[0].size(); k++)
            {
                // (1<<k) = 0001,0010,0100,1000
                // i = 0001,0010,0011,0100,0101 ...
                if (i & (1 << k))
                    temp += relation[j][k];
            }

            mySet.insert(temp);
        }

        //유일성 검사를 통과했다면
        if (mySet.size() == relation.size())
        {
            //최소성 검사를 통과했다면
            if (check(answer, i))
                //answer를 하나 늘려줌
                answer.push_back(i);
        }
    }

    return answer.size();
}

int main()
{
    vector<vector<string>> relation = {{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}};

    cout << solution(relation);
}