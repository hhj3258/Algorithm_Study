#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    // 가지고 있는 숫자 카드의 갯수
    cin >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; i++)
        cin >> cards[i];

    sort(cards.begin(), cards.end());

    int M;
    // 찾고자 하는 숫자 카드의 갯수
    cin >> M;

    vector<int> cardNums(M);
    for (int i = 0; i < M; i++)
    {
        cin >> cardNums[i];

        int card_idx = lower_bound(cards.begin(), cards.end(), cardNums[i]) - cards.begin();

        // card_idx에 해당하는 나의 카드와 cardNums[i]가 동일하지 않으면
        // lower_bound가 정확히 일치하는 값을 찾지 못했다는 뜻과 같다.
        if (cards[card_idx] != cardNums[i])
            cout << "0 ";
        else
            cout << "1 ";
    }
}