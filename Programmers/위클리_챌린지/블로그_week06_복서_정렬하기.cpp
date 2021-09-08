#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//정렬 조건
bool cmp(vector<float> a, vector<float> b)
{
    // 승률이 같다면 -> 2번 조건
    if (a[0] == b[0])
    {
        // 자신보다 무거운 사람 이긴 횟수가 같다면 -> 3번 조건
        if (a[1] == b[1])
        {
            // 몸무게가 같다면 -> 4번 조건
            if (a[2] == b[2])
                // 4. 번호가 작은 순 (번호는 같은 경우가 없다)
                return a[3] < b[3];
            // 3. 몸무게가 큰 순
            else
                return a[2] > b[2];
        }
        // 2. 1이 같다면 -> 자신보다 무거운 사람 이긴 횟수
        else
            return a[1] > b[1];
    }
    // 1. 승률
    else
        return a[0] > b[0];
}

vector<int> solution(vector<int> weights, vector<string> head2head)
{
    vector<int> answer(weights.size());

    // 행 길이: input으로 받아질 weights.size() -> 복서 수
    // 열: [승률, 자신보다 무거운 사람 이긴 횟수, 몸무게, 번호]
    vector<vector<float>> all(weights.size(), vector<float>(4));

    //복서 수만큼 반복
    for (int i = 0; i < all.size(); i++)
    {
        float lose = 0;
        float win = 0;
        int bigger_win = 0; //자신보다 무거운 사람 이긴 횟수

        //각 복서의 head2head 만큼 반복
        for (int k = 0; k < head2head[i].size(); k++)
        {
            if (head2head[i][k] == 'W')
            {
                //이긴 횟수 + 1
                win++;

                //ex) head2head[i].size()=4고, i=0이라면
                //ex) weights[0~4] > weights[0]
                if (weights[k] > weights[i])
                    //자신보다 무거운 사람 이긴 횟수 + 1
                    bigger_win++;
            }

            if (head2head[i][k] == 'L')
                //진 횟수 + 1
                lose++;
        }

        //경기 수가 0보다 크다면 all[i][0] = 승률 = 이긴 횟수/(이긴 횟수 + 진 횟수)
        //경기 수가 0과 같다면 all[i][0] = 승률 = 0% -> 문제의 1번 조건에서 명시
        all[i][0] = (win + lose) > 0 ? win / (win + lose) : 0;

        //all[i][1] = 자신보다 무거운 사람 이긴 횟수
        all[i][1] = bigger_win;

        //all[i][2] = 몸무게
        all[i][2] = weights[i];

        //all[i][3] = 선수 번호
        all[i][3] = i + 1;
    }

    cout << "[정렬 전]\n";
    cout << "승률      BigWin  몸무게  번호\n";
    for (int i = 0; i < all.size(); i++)
    {
        for (int j = 0; j < all[i].size(); j++)
            cout << all[i][j] << "     ";
        cout << endl;
    }
    cout << endl;

    // 문제의 정렬 조건에 따라 정렬
    sort(all.begin(), all.end(), cmp);

    cout << "[정렬 후]\n";
    cout << "승률      BigWin  몸무게  번호\n";
    for (int i = 0; i < all.size(); i++)
    {
        for (int j = 0; j < all[i].size(); j++)
            cout << all[i][j] << "     ";
        cout << endl;
    }
    cout << endl;

    //return 값 = 선수 번호 = all[i][3]
    for (int i = 0; i < answer.size(); i++)
        answer[i] = all[i][3];

    return answer;
}

int main()
{
    vector<int> weights1 = {50, 82, 75, 120};
    vector<string> head2head1 = {"NLWL", "WNLL", "LWNW", "WWLN"};

    vector<int> weights2 = {145, 92, 86};
    vector<string> head2head2 = {"NLW", "WNL", "LWN"};

    vector<int> weights3 = {60, 70, 60};
    vector<string> head2head3 = {"NNN", "NNN", "NNN"};

    vector<int> answer = solution(weights1, head2head1);

    cout << "answer: ";
    for (int i : answer)
        cout << i << ", ";
}