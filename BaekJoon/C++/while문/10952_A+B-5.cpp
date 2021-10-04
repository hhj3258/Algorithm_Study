#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num1, num2;
    vector<int> answers;
    while (true)
    {
        cin >> num1 >> num2;
        if (num1 + num2 == 0)
            break;
        answers.push_back(num1 + num2);
    }

    for (int i : answers)
        cout << i << endl;
}