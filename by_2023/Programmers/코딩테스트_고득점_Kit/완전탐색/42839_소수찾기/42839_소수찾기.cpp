#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(string numbers)
{
    int answer = 0;
    set<int> my_set;

    sort(numbers.begin(), numbers.end());

    do
    {
        string temp = "";
        for (int i = 0; i < numbers.size(); i++)
        {
            temp += numbers[i];
            my_set.insert(stoi(temp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    int max_num = *my_set.rbegin();
    vector<bool> isPrime(max_num, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= max_num; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= max_num; j += i)
                isPrime[j] = false;
    }

    for (auto iter = my_set.begin(); iter != my_set.end(); iter++)
    {
        if (isPrime[*iter])
            answer++;
    }

    return answer;
}

int main()
{
    string numbers1 = "17";  //1,7,17,71
    string numbers2 = "101"; //0,1,10,11,101,110

    int answer = solution(numbers1);
    cout << "answer: " << answer << endl;
}