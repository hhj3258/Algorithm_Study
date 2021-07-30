#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;

    return a.size() < b.size();
}

int main()
{
    int N; //1<=N<=20,000
    cin >> N;

    string temp = "";
    set<string> word_set;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        word_set.insert(temp);
    }

    vector<string> words;
    for (auto iter = word_set.begin(); iter != word_set.end(); iter++)
        words.push_back(*iter);

    sort(words.begin(), words.end(), cmp);

    for (int i = 0; i < words.size(); i++)
        cout << words[i] << '\n';
}