#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());

    int start = 0;
    int end = people.size() - 1;

    while (start < end)
    {
        //2명의 무게
        int kg = people[start] + people[end];

        //2명의 무게가 limit보다 크면 무거운 사람 혼자 태움
        if (kg > limit)
        {
            end--;
        }
        //2명의 무게가 limit보다 작거나 같으면 두 명 다 태움
        else if (kg <= limit)
        {
            start++;
            end--;
        }
        //배의 갯수 + 1
        answer++;
    }

    //사람이 남아있으면 배의 갯수 + 1
    if (start == end)
    {
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> people = {70, 50, 80, 50};
    int limit = 100;
    cout << solution(people, limit);
}