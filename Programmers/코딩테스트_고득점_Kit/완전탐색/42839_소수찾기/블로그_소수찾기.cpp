#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(string numbers)
{
    int answer = 0;
    set<int> my_set; //중복값을 제거하기 위해 set 사용

    //모든 순열 조합을 구하기 위해 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    cout << "조합의 경우의 수" << endl;
    do
    {
        string temp = "";
        for (int i = 0; i < numbers.size(); i++)
        {
            temp += numbers[i];
            my_set.insert(stoi(temp));
            cout << temp << ", ";
        }
        cout << endl;

    } while (next_permutation(numbers.begin(), numbers.end()));
    cout << endl;

    cout << "만들어진 조합 중 중복값 제거" << endl;
    for (auto iter = my_set.begin(); iter != my_set.end(); iter++)
    {
        cout << *iter << ", ";
    }
    cout << endl
         << endl;

    //*my_set.rbegin() ==> my_set의 가장 마지막 값(가장 큰 값)
    int max_num = *my_set.rbegin();
    //소수 판별 벡터를 가장 큰 값의 크기만큼 초기화
    vector<bool> isPrime(max_num, true);
    //숫자 0,1은 소수가 아니므로 false
    isPrime[0] = false;
    isPrime[1] = false;

    cout << "에라토스테네스의 체" << endl;
    for (int i = 2; i * i <= max_num; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= max_num; j += i)
                isPrime[j] = false;
    }

    for (int i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i])
            cout << i << ", ";
    }
    cout << endl
         << endl;

    //iter가 my_set을 순회하면서 isPrime[*iter]가 소수라면 answer++
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

    int answer = solution(numbers2);
    cout << "answer: " << answer << endl;
}