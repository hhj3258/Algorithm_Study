#include <iostream>
#include <algorithm>
using namespace std;

void SortInside(string N)
{
    sort(N.begin(), N.end(), greater<char>());

    cout << N;
}

int main()
{
    string N; //N<=1,000,000,000
    cin >> N;

    SortInside(N);
}