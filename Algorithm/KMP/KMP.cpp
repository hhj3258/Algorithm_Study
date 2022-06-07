#include <bits/stdc++.h>
using namespace std;

vector<int> MakeTable(string target)
{
    vector<int> table(target.size());
    int j = 0; // j 는 항상 i 보다 작음
    for (int i = 1; i < target.size(); i++)
    {
        // target[i] 와 target[j] 의 문자가 다르면
        // j를 table[j-1] 에 저장된 인덱스로 이동시킨다.
        while (j > 0 && target[i] != target[j])
        {
            j = table[j - 1];
        }

        // i번째, j번째 문자가 같으면
        if (target[i] == target[j])
        {
            // table[i] 에 j+1 을 기록하고
            // j 를 1 증가시긴다.
            // table[i] 는 i번째 문자의 접두사 접미사의 길이가 된다.
            table[i] = ++j;
        }
    }

    return table;
}

void KMP(string str, string target)
{
    vector<int> table = MakeTable(target);

    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        while (j > 0 && str[i] != target[j])
        {
            j = table[j - 1];
        }

        if (str[i] == target[j])
        {
            // j가 target의 마지막 문자의 인덱스를 가리키고 있다면
            if (j == target.size() - 1)
            {
                // target 과 일치하는 문자열을 찾은 것임.
                cout << "Target's Start Index : " << (i - target.size() + 1) << endl;
                // table[j] 의 값은 현재 접미사의 크기와 동일한 접두사의 '마지막 인덱스 + 1' 을 저장하고 있음
                // j를 접두사의 마지막을 가리키는 인덱스로 점프시켜서 그 인덱스부터 조사하도록 함.
                j = table[j];
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    string str = "ababacabacaabacaaba";
    string target = "abacaaba";

    cout << "str size : " << str.size() << endl;
    cout << "target size : " << target.size() << endl;
    cout << "----------------------------------\n";

    // vector<int> table = MakeTable(target);
    // for (auto &item : table)
    //     cout << item << ' ';

    KMP(str, target);
}