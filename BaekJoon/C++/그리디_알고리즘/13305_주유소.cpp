#include <iostream>
#include <vector>
using namespace std;

long long N;

void Solve(vector<long long> dist, vector<long long> oil)
{
    long long temp = oil[0];
    long long credit = temp * dist[0];

    for (int i = 1; i < N - 1; i++)
    {
        if (temp > oil[i])
            temp = oil[i];

        credit += temp * dist[i];
    }

    cout << credit;
}

int main()
{
    cin >> N;
    vector<long long> dist(N - 1);
    vector<long long> oil(N);

    for (int i = 0; i < N - 1; i++)
        cin >> dist[i];

    for (int i = 0; i < N; i++)
        cin >> oil[i];

    Solve(dist, oil);
}