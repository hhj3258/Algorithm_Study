#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
bool solution(vector<string> phone_book);

int main()
{
    vector<string> phone_book1 = {"119", "97674223", "1195524421"}; //false

    vector<string> phone_book2 = {"123", "456", "789"}; //true

    bool answer = solution(phone_book1);

    if (answer)
        cout << "answer: "
             << "true";
    else
        cout << "answer: "
             << "false";
}

bool solution(vector<string> phone_book)
{
    bool answer = true;

    unordered_map<string, int> phone_map;
    for (int i = 0; i < phone_book.size(); i++)
    {
        phone_map[phone_book[i]] = 1;
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            phone_number += phone_book[i][j];
            if (phone_map[phone_number] && (phone_number != phone_book[i]))
            {
                answer = false;
            }
        }
    }

    return answer;
}