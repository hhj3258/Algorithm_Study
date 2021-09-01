#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

void Solve(vector<int> A)
{
    vector<int> vec(1, 0);

    for (int i = 0; i < N; i++)
    {
        //넣고자하는 값이 vec의 마지막 값보다 크다면 넣어준다.
        if (A[i] > vec.back())
            vec.push_back(A[i]);
        //넣고자하는 값이 vec의 마지막 값보다 작거나 같다면
        else
        {
            //temp를 기존 vec안에서 찾아본다.
            //temp가 있다면 그 iter를 돌려줄 것이고, 없다면 temp보다 큰 원소중 가장 처음 오는 iter를 반환해준다.
            auto low = lower_bound(vec.begin(), vec.end(), A[i]);
            //해당 iter에 해당되는 vec 값을 변경해준다.
            *low = A[i];
        }
    }

    //초기값으로 넣어준 0을 제외한 vec의 길이가 가장 긴 증가하는 부분 수열의 길이가 된다.
    cout << vec.size() - 1 << endl;
}

int main()
{
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}