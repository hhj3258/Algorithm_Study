#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void Solve(vector<int> card, vector<int> num)
{
    sort(card.begin(), card.end());

    for (int i = 0; i < num.size(); i++)
    {
        int key = num[i];

        auto left = lower_bound(card.begin(), card.end(), key);
        auto right = upper_bound(card.begin(), card.end(), key);

        cout << right - left << ' ';
    }
}

int main()
{
    cin >> N;
    vector<int> card(N);
    for (int i = 0; i < N; i++)
        cin >> card[i];

    cin >> M;
    vector<int> num(M);
    for (int i = 0; i < M; i++)
        cin >> num[i];

    Solve(card, num);
}