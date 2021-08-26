#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    unordered_map<string, bool> phone_map;

    for (int i = 0; i < phone_book.size(); i++)
    {
        phone_map[phone_book[i]] = 1;
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            temp += phone_book[i][j];
            if (phone_map[temp] && (temp.size() < phone_book[i].size()))
            {
                answer = false;
                return answer;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    cout << solution(phone_book);
}