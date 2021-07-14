#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<vector<int>> mans(answers.size(), vector<int>(3));

    vector<int> mans_cnt = {0, 0, 0};

    vector<int> man1 = {1, 2, 3, 4, 5};
    vector<int> man2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> man3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for (int i = 0; i < mans.size(); i++)
    {
        //1번째 수포자
        if (mans_cnt[0] > man1.size() - 1)
            mans_cnt[0] = 0;
        mans[i][0] = man1[mans_cnt[0]++];

        //2번째 수포자
        if (mans_cnt[1] > man2.size() - 1)
            mans_cnt[1] = 0;
        mans[i][1] = man2[mans_cnt[1]++];

        //3번째 수포자
        if (mans_cnt[2] > man3.size() - 1)
            mans_cnt[2] = 0;
        mans[i][2] = man3[mans_cnt[2]++];
    }

    vector<pair<int, int>> score;
    for (int i = 1; i < 4; i++)
        score.push_back(make_pair(0, i));

    for (int i = 0; i < answers.size(); i++)
        for (int j = 0; j < 3; j++)
            if (answers[i] == mans[i][j])
                score[j].first++;

    sort(score.begin(), score.end());

    int max_v = score[2].first;

    for (int i = 0; i < score.size(); i++)
        if (max_v == score[i].first)
            answer.push_back(score[i].second);

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<int> answers1 = {1, 2, 3, 4, 5};
    vector<int> answers2 = {1, 3, 2, 4, 2};
    vector<int> answers3 = {1, 3, 2, 4, 2, 1, 3, 2, 4, 2, 1, 3, 2, 4, 2};

    vector<int> answer = solution(answers3);

    cout << "answer: [";
    for (int i : answer)
        cout << i << ", ";
    cout << "]" << endl;
}