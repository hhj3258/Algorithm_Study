#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Join
{
    int age;
    string name;
    int order;
};

bool cmp(Join a, Join b)
{
    if (a.age == b.age)
        return a.order < b.order;
    return a.age < b.age;
}

int main()
{
    int N; //1<=N<=100,000;
    cin >> N;

    Join R;
    vector<Join> humans(N);
    for (int i = 0; i < humans.size(); i++)
    {
        cin >> R.age >> R.name;
        R.order = i;
        humans[i] = R;
    }

    sort(humans.begin(), humans.end(), cmp);

    for (int i = 0; i < humans.size(); i++)
    {
        cout << humans[i].age << " "
             << humans[i].name << '\n';
    }
}