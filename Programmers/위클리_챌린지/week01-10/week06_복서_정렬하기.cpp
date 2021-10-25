#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<float> a, vector<float> b)
{
    if (a[0] == b[0])
    {
        if (a[1] == b[1])
        {
            if (a[2] == b[2])
                return a[3] < b[3];
            else
                return a[2] > b[2];
        }
        else
            return a[1] > b[1];
    }
    else
        return a[0] > b[0];
}

vector<int> solution(vector<int> weights, vector<string> head2head)
{
    vector<int> answer(weights.size());
    vector<vector<float>> all(weights.size(), vector<float>(4));

    for (int i = 0; i < all.size(); i++)
    {
        float lose = 0;
        float win = 0;
        int bigger_win = 0;
        for (int k = 0; k < head2head[i].size(); k++)
        {
            if (head2head[i][k] == 'W')
            {
                win++;
                if (weights[k] > weights[i])
                    bigger_win++;
            }

            if (head2head[i][k] == 'L')
                lose++;
        }

        all[i][0] = (win + lose) > 0 ? win / (win + lose) : 0;
        all[i][1] = bigger_win;
        all[i][2] = weights[i];
        all[i][3] = i + 1;
    }

    sort(all.begin(), all.end(), cmp);

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

    vector<int> answer = solution(weights3, head2head3);

    cout << "answer: ";
    for (int i : answer)
        cout << i << ' ';
}