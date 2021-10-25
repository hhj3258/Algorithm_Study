#include <iostream>
using namespace std;

void EndWorld(int n)
{
    int devil_num = 666;
    int devil_cnt = 1;

    while (devil_cnt < n)
    {
        devil_num++;
        string temp = to_string(devil_num);
        if (temp.find("666") != -1)
        {
            devil_cnt++;
        }
    }
    cout << devil_num;
}

int main()
{
    int n;
    cin >> n;

    EndWorld(n);
}