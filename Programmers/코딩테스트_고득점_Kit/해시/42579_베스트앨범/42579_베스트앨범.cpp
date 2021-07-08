#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;
vector<int> solution(vector<string> genres, vector<int> plays);

int main()
{
    vector<string> genres1 = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    vector<int> answer = solution(genres1, plays);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}

// bool cmp(const pair<int, int> &a, const pair<int, int> &b)
// {
//     if (a.second == b.second)
//         return a.first < b.first;
//     return a.second < b.second;
// }

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, map<int, int>> album;

    for (int i = 0; i < genres.size(); i++)
    {
        album[genres[i]][i] = plays[i];

        //cout << album[genres[i]][i] << endl;
    }
    cout << endl;

    vector<int> temp;
    cout << endl;
    for (auto iter = album.begin(); iter != album.end(); iter++)
    {
        for (int i = 0; i < 5; i++)
            cout << i << ": " << (iter->second)[i] << endl;
        cout << endl;
    }
    // for (int f = 0; f < genres.size(); f++)
    // {
    //     vector<int> temp;

    //     for (int i = 0; i < album[genres[f]].size(); i++)
    //     {
    //         temp.push_back(album[genres[f]][i]);
    //     }

    //     sort(temp.begin(), temp.end(), greater<int>());

    //     for (int i = 0; i < album[genres[f]].size(); i++)
    //     {
    //         album[genres[f]][i] = temp[i];
    //     }
    // }

    // for (int i = 0; i < album["pop"].size(); i++)
    // {
    //     cout << album["pop"][i] << endl;
    // }

    // int max_value = -1;
    // for (auto iter = album.begin(); iter != album.end(); iter++)
    // {
    //     for (int i = 0; i < 2; i++)
    //         cout << (iter->second)[i] << " ";
    // }

    // for (int i = 0; i < genres.size(); i++)
    // {
    //     album.insert(pair<string, pair<int, int>>(genres[i], {i, plays[i]}));
    // }

    //unordered_map<string, map<int, int>>::iterator iter;
    // for (auto iter = album.begin(); iter != album.end(); iter++)
    // {
    //     cout << (*iter).first << " " << (*iter).second << endl;
    // }

    return answer;
}