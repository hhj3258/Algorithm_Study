#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
bool solution(vector<string> phone_book);

int main()
{
    vector<string> phone_book1 = { "119", "97674223", "1195524421" };   //false

    vector<string> phone_book2 = { "123","456","789" };     //true

    solution(phone_book1);
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    set<string> book_set;
    for (auto i = book_set.begin(); i != book_set.end(); i++) {

    }

    return answer;
}