#include <iostream>

using namespace std;

int main()
{
    int num1, num2;

    //조건문에 cin 넣어주면 마지막에 eof를 만나고 bool 값 false 리턴
    while (cin >> num1 >> num2)
        cout << (num1 + num2) << endl;
}