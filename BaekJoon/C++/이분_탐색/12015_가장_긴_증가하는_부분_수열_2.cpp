#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

void Solve(vector<int> A)
{
    int temp = 0;
    int cnt = 0;
    vector<int> vec(1, 0);

    for (int i = 0; i < N; i++)
    {
        temp = A[i];

        //넣고자하는 값이 vec의 마지막 값보다 크다면 넣어주고
        //길이 + 1
        if (temp > vec.back())
        {
            vec.push_back(temp);
            cnt++;
        }
        //넣고자하는 값이 vec의 마지막 값보다 작거나 같다면
        //temp를 기존 vec안에서 찾아본다.
        //temp가 있다면 그 iter를 돌려줄 것이고, 없다면 temp보다 큰 원소중 가장 처음 오는 iter를 반환해준다.
        //해당 iter에 해당되는 vec 값을 변경해준다.
        else
        {
            auto low = lower_bound(vec.begin(), vec.end(), temp);
            *low = temp;
        }
    }

    cout << cnt << endl;
}

int main()
{
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}