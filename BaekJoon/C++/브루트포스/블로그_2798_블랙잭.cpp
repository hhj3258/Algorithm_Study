#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BlackJack(int N, int M, vector<int> card)
{
    //카드들을 오름차순 정렬
    sort(card.begin(), card.end());

    //오름차순 정렬된 우선순위 큐 선언
    priority_queue<int, vector<int>, less<int>> answer_q;

    //가장 큰 3개 카드의 index
    int big_idx = card.size() - 1;
    int mid_idx = card.size() - 2;
    int sml_idx = card.size() - 3;

    int sum_temp;

    //3장의 카드의 합을 구해야하므로
    //sml_idx=0, mid_idx=1, big_idx=2 일 때까지 반복
    while (big_idx > 1)
    {
        //카드 3장의 합
        sum_temp = card[sml_idx] + card[mid_idx] + card[big_idx];

        //과정 출력
        cout << "idx: [" << sml_idx << " " << mid_idx << " " << big_idx << "] ,  ";
        cout << card[sml_idx] << " + " << card[mid_idx] << " + " << card[big_idx] << " = ";
        cout << sum_temp << endl;

        //카드 3장의 합이 M보다 작으면 answer_q에 넣어줌
        if (sum_temp <= M)
            answer_q.push(sum_temp);

        //sml_idx ==> card.size()-3 ~ 0
        if (sml_idx > 0)
        {
            sml_idx--;
        }
        //mid_idx ==> card.size()-2 ~ 1
        else if (mid_idx > 1)
        {
            mid_idx--;
            sml_idx = mid_idx - 1;
        }
        //big_idx ==> card.size()-1 ~ 2
        else
        {
            big_idx--;
            mid_idx = big_idx - 1;
            sml_idx = mid_idx - 1;
        }
    }

    //정답 출력
    cout << "answer: " << answer_q.top() << endl;
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