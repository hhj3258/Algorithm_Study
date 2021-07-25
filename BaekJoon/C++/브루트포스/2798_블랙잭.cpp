#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BlackJack(int N, int M, vector<int> card)
{
    priority_queue<int, vector<int>, less<int>> answer_q;
    sort(card.begin(), card.end());

    int big_idx = card.size() - 1;
    int mid_idx = card.size() - 2;
    int sml_idx = card.size() - 3;

    int sum_temp;

    while (big_idx > 1)
    {
        sum_temp = card[sml_idx] + card[mid_idx] + card[big_idx];

        if (sum_temp <= M)
            answer_q.push(sum_temp);

        if (sml_idx > 0)
        {
            sml_idx--;
        }
        else if (mid_idx > 1)
        {
            mid_idx--;
            sml_idx = mid_idx - 1;
        }
        else
        {
            big_idx--;
            mid_idx = big_idx - 1;
            sml_idx = mid_idx - 1;
        }
    }

    cout << answer_q.top() << endl;
}

int main()
{
    int N, M;

    cin >> N >> M;
    vector<int> card(N);

    for (int i = 0; i < card.size(); i++)
    {
        cin >> card[i];
    }

    BlackJack(N, M, card);
}