#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer(2);

    int total = brown + yellow; //48

    for (int i = 3;; i++)
    {
        int horizon = total / i; //init: 16
        int vertical = i;        //init: 3

        int yellow_num = (horizon - 2) * (vertical - 2); //init: 14*1=14

        if (yellow_num == yellow)
        {
            answer[0] = horizon;
            answer[1] = vertical;
            break;
        }
    }

    return answer;
}

int main()
{
    int brown1 = 10;
    int yellow1 = 2;

    int brown2 = 8;
    int yellow2 = 1;

    int brown3 = 24;
    int yellow3 = 24;

    vector<int> answer = solution(brown2, yellow2);

    cout << "answer: [ ";
    for (int i : answer)
    {
        cout << i << " ";
    }
    cout << "]";
}