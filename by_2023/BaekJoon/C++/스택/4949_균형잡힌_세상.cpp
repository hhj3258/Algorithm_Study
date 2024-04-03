#include <bits/stdc++.h>
using namespace std;

bool Solve(string &str)
{
    stack<char> myStack;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '[')
            myStack.push(str[i]);
        else if (str[i] == ')')
        {
            if (myStack.empty() || myStack.top() != '(')
                return false;
            else
                myStack.pop();
        }
        else if (str[i] == ']')
        {
            if (myStack.empty() || myStack.top() != '[')
                return false;
            else
                myStack.pop();
        }
    }

    if (myStack.empty())
        return true;
    else
        return false;
}

int main()
{
    string str;
    while (true)
    {
        getline(cin, str);

        if (str == ".")
            break;

        if (Solve(str))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}