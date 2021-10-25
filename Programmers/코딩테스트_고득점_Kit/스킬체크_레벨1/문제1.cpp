#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> solution(long long n);

int main()
{
    long long n = 12345;

    vector<int> answer = solution(n);
}

vector<int> solution(long long n)
{
    vector<int> answer;

    string temp = to_string(n);

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        answer.push_back(temp[i] - '0');
    }

    // for (int i = 0; i < answer.size(); i++)
    // {
    //     cout << answer[i] << " ";
    // }

    return answer;
}