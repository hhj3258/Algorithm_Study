#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<int> solution(vector<string> genres, vector<int> plays);

int main()
{
    vector<string> genres1 = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays1 = {500, 600, 150, 800, 2500};

    vector<string> genres2 = {"classic", "pop", "classic", "classic", "pop", "rap", "kpop", "kpop"};
    vector<int> plays2 = {500, 600, 150, 800, 2500, 50, 3000, 10};

    vector<string> genres3 = {"classic", "pop", "pop"};
    vector<int> plays3 = {500, 600, 650};

    vector<int> answer = solution(genres2, plays2);

    cout << "answer: ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}

class Songs
{
public:
    int num;
    int plays;

    Songs(int plays, int num)
    {
        this->num = num;
        this->plays = plays;
    }
};

bool cmp(Songs a, Songs b)
{
    if (a.plays == b.plays)
        return a.num < b.num;
    else
        return a.plays > b.plays;
}

bool cmp2(pair<int, unordered_map<string, vector<Songs>>::iterator> &a,
          pair<int, unordered_map<string, vector<Songs>>::iterator> &b)
{
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    unordered_map<string, vector<Songs>> album;

    for (int i = 0; i < genres.size(); i++)
        album[genres[i]].push_back(Songs(plays[i], i));

    for (auto iter = album.begin(); iter != album.end(); iter++)
        sort((*iter).second.begin(), (*iter).second.end(), cmp);

    vector<pair<int, unordered_map<string, vector<Songs>>::iterator>> order_v;
    for (auto iter = album.begin(); iter != album.end(); iter++)
    {
        auto songs_vec = (*iter).second;
        int plays_sum = 0;
        for (int i = 0; i < songs_vec.size(); i++)
            plays_sum += songs_vec[i].plays;

        order_v.push_back(make_pair(plays_sum, iter));
    }

    sort(order_v.begin(), order_v.end(), cmp2);

    for (int i = 0; i < order_v.size(); i++)
    {
        for (int j = 0; j < (*order_v[i].second).second.size(); j++)
        {
            if (j == 2)
                break;
            answer.push_back((*order_v[i].second).second[j].num);
        }
    }

    return answer;
}