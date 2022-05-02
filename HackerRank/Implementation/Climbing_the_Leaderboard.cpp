#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<pair<int, int>> RealRanking(const vector<int> &ranked)
{
    set<int> rank_set;
    for (const auto &it : ranked)
        rank_set.insert(it);

    vector<pair<int, int>> real_rank(rank_set.size());

    int idx = 0;
    int human_num = rank_set.size();
    for (const auto &it : rank_set)
    {
        real_rank[idx].first = it;
        real_rank[idx].second = human_num - idx;
        idx++;
    }

    cout << "<Rank>" << endl;
    for (const auto &it : real_rank)
        cout << it.first << ", " << it.second << endl;
    cout << endl;

    return real_rank;
}

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first < b.first;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    auto real_rank = RealRanking(ranked);

    vector<int> answer;
    for (const auto &it : player)
    {

        auto lower = lower_bound(real_rank.begin(), real_rank.end(), make_pair(it, 0), comp);
        auto upper = upper_bound(real_rank.begin(), real_rank.end(), make_pair(it, 0), comp);

        int idx = lower - real_rank.begin();
        int count = upper - lower;

        cout << "player score: " << it << ", ";
        cout << idx << ", ";
        cout << real_rank[idx].second << ", ";
        cout << "count: " << count << endl;

        int temp = real_rank[idx].second;
        if (count == 1)
            answer.emplace_back(temp);
        else
            answer.emplace_back(temp + 1);
    }

    return answer;
}