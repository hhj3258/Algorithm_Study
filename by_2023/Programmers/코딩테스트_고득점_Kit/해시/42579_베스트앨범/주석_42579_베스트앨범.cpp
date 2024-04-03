#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// map의 second 값: vector<Songs>
// Songs(고유번호, 재생횟수)
// pair로 가능하지만 객체로 만들어 접근하는 편이 더 직관적임
class Songs
{
public:
    int num;   // 고유번호
    int plays; // 재생횟수

    Songs(int plays, int num)
    {
        this->num = num;
        this->plays = plays;
    }
};

// vector<Songs> 정렬: 내림차순
// 장르별 재생횟수가 많은 2 곡까지만 뽑아주기 위함
// 재생횟수가 같으면 고유번호가 낮은 순, 그 외에는 재생횟수가 많은 순
bool cmp(Songs &a, Songs &b)
{
    if (a.plays == b.plays)
        return a.num < b.num;
    else
        return a.plays > b.plays;
}

// order_v 정렬: 장르별 재생횟수 합의 내림차순
// 장르별로 재생횟수의 합이 큰 순으로 정렬하기 위함
bool cmp2(pair<int, unordered_map<string, vector<Songs>>::iterator> &a,
          pair<int, unordered_map<string, vector<Songs>>::iterator> &b)
{
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    //map을 굳이 사용할 이유가 없기 때문에 더 빠른 탐색이 가능한 unordered_map 사용
    //album[장르명, [고유번호, 장르별 재생횟수]]
    unordered_map<string, vector<Songs>> album;

    //genres 벡터에서 재생횟수와 고유번호를 찾아 album에 넣어줌
    for (int i = 0; i < genres.size(); i++)
        album[genres[i]].push_back(Songs(plays[i], i));

    //album의 장르 갯수만큼 돌면서 장르별 vector<Songs> 을 내림차순 정렬
    for (auto iter = album.begin(); iter != album.end(); iter++)
        sort((*iter).second.begin(), (*iter).second.end(), cmp);

    //정렬 후 album 원소 테스트 출력
    cout << "<sorted>" << endl;
    for (auto iter = album.begin(); iter != album.end(); iter++)
    {
        cout << "[" << (*iter).first << "]" << endl;
        for (int i = 0; i < (*iter).second.size(); i++)
        {
            cout << "num: " << (*iter).second[i].num << "\t// ";
            cout << "plays: " << (*iter).second[i].plays;
            cout << endl;
        }
        cout << endl;
    }

    // order_v[장르별 재생횟수 합, 장르별 반복자]
    vector<pair<int, unordered_map<string, vector<Songs>>::iterator>> order_v;
    for (auto iter = album.begin(); iter != album.end(); iter++)
    {
        //songs_vec == vector<Songs>
        auto songs_vec = (*iter).second;
        int plays_sum = 0;
        for (int i = 0; i < songs_vec.size(); i++)
            plays_sum += songs_vec[i].plays;

        order_v.push_back(make_pair(plays_sum, iter));
    }

    //order_v의 장르별 재생횟수를 기준으로 내림차순 정렬
    sort(order_v.begin(), order_v.end(), cmp2);

    //정렬 후 order_v 원소 테스트 출력
    cout << "<sorted_order_v>" << endl;
    for (int i = 0; i < order_v.size(); i++)
    {
        cout << "i: " << i << " // " << order_v[i].first << endl;
    }
    cout << endl;

    //order_v[i].second == album의 iterator
    //(*order_v[i].second).second[j] == vector<Songs>
    //answer 벡터에 장르별로 최대 2곡까지만 넣어줌
    for (int i = 0; i < order_v.size(); i++)
    {
        for (int j = 0; j < (*order_v[i].second).second.size(); j++)
        {
            //장르별 곡 갯수는 최대 2개까지만
            if (j == 2)
                break;

            //고유번호를 넣어줌
            answer.push_back((*order_v[i].second).second[j].num);
        }
    }

    return answer;
}

//테스트 케이스 출력
int main()
{
    vector<string> genres1 = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays1 = {500, 600, 150, 800, 2500};

    vector<string> genres2 = {"classic", "pop", "classic", "classic", "pop", "rap", "kpop", "kpop"};
    vector<int> plays2 = {500, 600, 150, 800, 2500, 50, 3000, 10};

    vector<string> genres3 = {"classic", "pop", "pop"};
    vector<int> plays3 = {500, 600, 650};

    vector<int> answer = solution(genres1, plays1);

    cout << "answer: ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ", ";
    }
    cout << endl;
}