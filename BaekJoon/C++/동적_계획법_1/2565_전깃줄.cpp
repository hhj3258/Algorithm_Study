#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
int Solve(vector<pair<int, int>> lines)
{

    // cout << "<sorted lines\n";
    // for (int i = 0; i < lines.size(); i++)
    // {
    //     cout << lines[i].first << ", " << lines[i].second << endl;
    // }
    set<pair<int, int>> del_lines;

    //cout << "<for¹®>\n";
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (lines[i].second < lines[j].second)
            {
                // cout << "i=" << i << ": " << lines[i].first << ", " << lines[i].second << endl;
                // cout << "j=" << j << ": " << lines[j].first << ", " << lines[j].second << endl;
                // cout << endl;
                del_lines.insert(lines[j]);
            }
        }
    }

    // cout << "<del>\n";
    // for (auto iter = del_lines.begin(); iter != del_lines.end(); iter++)
    // {
    //     cout << (*iter).first << ", " << (*iter).second << endl;
    // }

    return del_lines.size();
}

int main()
{
    cin >> N;
    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; i++)
        cin >> lines[i].first >> lines[i].second;

    sort(lines.begin(), lines.end());
    int one = Solve(lines);

    sort(lines.begin(), lines.end(), greater<pair<int, int>>());
    int two = Solve(lines);

    cout << min(one, two);
}