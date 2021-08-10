#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> box;
int d[100] = {
    0,
};

void Solve()
{
    d[0] = box[0];
    d[1] = max(box[0], box[1]);
    for (int i = 2; i < N; i++)
    {
        d[i] = max(d[i - 1], d[i - 2] + box[i]);
    }
    cout << d[N - 1];
}

int main()
{

    //cin >> N;
    N = 4;
    for (int i = 0; i < N; i++)
    {
        //cin >> box[i];
    }
    box.push_back(1);
    box.push_back(3);
    box.push_back(1);
    box.push_back(5);

    Solve();
}