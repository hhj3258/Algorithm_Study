#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<vector<int>> mans(3, vector<int>(answers.size()));
    vector<int> mans_cnt(3);

    vector<int> man1 = {1, 2, 3, 4, 5};
    vector<int> man2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> man3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for (int i = 0; i < answers.size(); i++)
    {
        //1번째 수포자
        if (mans_cnt[0] > man1.size() - 1)
            mans_cnt[0] = 0;
        mans[0][i] = man1[mans_cnt[0]++];

        //2번째 수포자
        if (mans_cnt[1] > man2.size() - 1)
            mans_cnt[1] = 0;
        mans[1][i] = man2[mans_cnt[1]++];

        //3번째 수포자
        if (mans_cnt[2] > man3.size() - 1)
            mans_cnt[2] = 0;
        mans[2][i] = man3[mans_cnt[2]++];
    }

    vector<int> score(3);
    for (int i = 0; i < mans.size(); i++)
    {
        for (int j = 0; j < mans[i].size(); j++)
        {
            if (answers[j] == mans[i][j])
                score[i]++;
        }
    }

    int max_v = *max_element(score.begin(), score.end());
    for (int i = 0; i < 3; i++)
    {
        if (score[i] == max_v)
            answer.push_back(i + 1);
    }

    return answer;
}

int main()
{
    vector<int> answers1 = {1, 2, 3, 4, 5};
    vector<int> answers2 = {1, 3, 2, 4, 2};
    vector<int> answers3 = {1, 3, 2, 4, 2, 1, 3, 2, 4, 2, 1, 3, 2, 4, 2};

    vector<int> answer = solution(answers2);

    cout << "answer: [";
    for (int i : answer)
        cout << i << ", ";
    cout << "]" << endl;
}