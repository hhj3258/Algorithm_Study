#include <iostream>
#include <string>
#include <vector>

using namespace std;
string solution(string phone_number);

int main()
{
    string phone_number1 = "01033334444";

    solution(phone_number1);
}

string solution(string phone_number)
{
    string answer = "";

    for (int i = 0; i < phone_number.size() - 4; i++)
    {
        phone_number[i] = '*';
    }

    answer = phone_number;

    return answer;
}