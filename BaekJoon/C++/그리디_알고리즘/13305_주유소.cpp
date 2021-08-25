#include <iostream>
#include <vector>
using namespace std;

int N;

void Solve(vector<int> dist, vector<int> oil)
{
    long long my_oil = 0;
    long long credit = 0;

    for (int i = 0; i < dist.size(); i++)
    {
        // cout << my_oil << endl;
        if (my_oil == 0)
        {
            if (oil[i] > oil[i + 1])
            {
                credit += oil[i] * dist[i];
                my_oil += dist[i];
            }
            else if (oil[i] <= oil[i + 1])
            {
                credit += oil[i] * (dist[i] + dist[i + 1]);
                my_oil += dist[i] + dist[i + 1];
            }
        }
        // cout << my_oil << endl;
        // cout << endl;
        my_oil -= dist[i];
    }

    cout << credit;
}

int main()
{
    cin >> N;
    vector<int> dist(N - 1);
    vector<int> oil(N);

    for (int i = 0; i < N - 1; i++)
        cin >> dist[i];

    for (int i = 0; i < N; i++)
        cin >> oil[i];

    Solve(dist, oil);
}