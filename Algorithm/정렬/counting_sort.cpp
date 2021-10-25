#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#define DATA_SIZE 20 //정렬해야될 수의 갯수
#define MAX_NUM 10   //숫자의 최대값

int data_arr[DATA_SIZE];  //들어오는 수의 갯수만큼 할당
int count[MAX_NUM];       //숫자의 최대값만큼 할당
vector<int> sorted_datas; //정렬된 값을 넣을 벡터

void CountingSort(int datas[])
{
    //count 배열이 중복되는 숫자의 개수를 카운팅함
    for (int i = 0; i < DATA_SIZE; i++)
        count[datas[i]]++;

    cout << "[count]  ";
    for (int i = 0; i < DATA_SIZE; i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;

    //count[i]=0일 경우는 존재하지 않는 숫자이므로 추가할 필요가 없음
    //count[i]가 0이 아니면 sorted_datas 배열에 count[i]의 값만큼 반복해서 추가
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (count[i] != 0)
            for (int j = 0; j < count[i]; j++)
                sorted_datas.push_back(i);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int n;

    cout << "[input]  ";
    for (int i = 0; i < DATA_SIZE; i++)
    {
        n = rand() % 10;
        data_arr[i] = n;

        cout << n << " ";
    }
    cout << endl;

    CountingSort(data_arr);

    cout << "[output] ";
    for (int i = 0; i < DATA_SIZE; i++)
    {
        cout << sorted_datas[i] << " ";
    }
}