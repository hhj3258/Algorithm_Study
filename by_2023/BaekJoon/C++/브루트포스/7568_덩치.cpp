#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BigRanking(vector<pair<int, int>> humans)
{
    vector<int> ranking(humans.size(), 1);

    for (int i = 0; i < humans.size(); i++)
    {
        int temp_kg = humans[i].first;
        int temp_cm = humans[i].second;

        for (int j = 0; j < humans.size(); j++)
        {
            if (humans[j].first > temp_kg && humans[j].second > temp_cm)
            {
                ranking[i]++;
            }
        }
    }

    for (int i : ranking)
        cout << i << " ";
}

int main()
{
    int n;
    cin >> n;

    int x, y;
    vector<pair<int, int>> humans;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        humans.push_back(make_pair(x, y));
    }

    BigRanking(humans);
}