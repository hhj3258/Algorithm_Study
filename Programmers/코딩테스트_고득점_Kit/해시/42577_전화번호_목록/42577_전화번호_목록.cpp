#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
bool solution(vector<string> phone_book);

int main()
{
    vector<string> phone_book1 = {"119", "97674223", "1195524421"}; //false

    vector<string> phone_book2 = {"123", "456", "789"}; //true
    bool answer = solution(phone_book2);

    if (answer)
        cout << "answer: "
             << "no";
    else
        cout << "answer: "
             << "yes";
}

bool solution(vector<string> phone_book)
{
    bool answer = true;

    set<string> book_set;
    string xx = "xx";
    xx.size();
    for (string phone_num : phone_book)
    {
        book_set.insert(phone_num);
    }

    // auto iter = book_set.find("119");
    // cout << (*iter)[0];

    auto temp_num = book_set.begin();

    for (auto i = book_set.begin(); i != book_set.end(); i++)
    {
        for (int j = 0; j < (*temp_num).size(); j++)
        {
            if (j == (*i).size())
            {
                break;
            }

            if ((*temp_num)[j] != (*i)[j])
            {
                answer = true;
                break;
            }
            else
            {
                answer = false;
            }
        }

        temp_num++;
    }

    return answer;
}