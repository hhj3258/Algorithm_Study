#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
int solution(vector<vector<string>> clothes);

int main()
{
    vector<vector<string>> clothes1 =
        {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};

    vector<vector<string>> clothes2 =
        {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};

    int answer = solution(clothes1);
    cout << "answer: " << answer << endl;
}

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    unordered_map<string, int> cloth_map;

    for (int i = 0; i < clothes.size(); i++)
    {
        cloth_map[clothes[i][1]] += 1;
    }

    for (auto iter = cloth_map.begin(); iter != cloth_map.end(); iter++)
    {
        answer = answer * (iter->second + 1);
    }

    return answer - 1;
}