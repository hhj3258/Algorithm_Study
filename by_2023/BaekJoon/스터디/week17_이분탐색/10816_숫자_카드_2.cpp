#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; i++)
        cin >> cards[i];
    sort(cards.begin(), cards.end());

    int M;
    cin >> M;
    int keyCard;
    for (int i = 0; i < M; i++)
    {
        cin >> keyCard;
        int cardCount = upper_bound(cards.begin(), cards.end(), keyCard) - lower_bound(cards.begin(), cards.end(), keyCard);

        cout << cardCount << ' ';
    }
}