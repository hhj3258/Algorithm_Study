#include <iostream>
#include <vector>

using namespace std;

struct CubeInfo
{
    int length = 0;
    int cnt = 0;
};

vector<CubeInfo> cubes;

// 채우는데 사용한 큐브의 갯수
int answer = 0;
// 박스를 모두 채웠는지 체크할 bool 변수
bool isFail = false;

// Solve(박스의 가로, 박스의 세로, 박스의 높이, 큐브 배열 시작 인덱스)
void Solve(int length, int width, int height, int idx)
{
    // 종료 조건
    // 박스의 가로, 세로, 높이 중 하나라도 0 이라면 반환
    // 셋 중 하나라도 0이면 부피 = 0 이므로 큐브를 넣을 수 없다
    if (length == 0 || width == 0 || height == 0)
        return;

    // 가장 큰 큐브부터 가장 작은 큐브까지 반복
    for (int i = idx; i >= 0; i--)
    {
        // 현재 큐브의 갯수가 0 이라면 continue
        if (cubes[i].cnt <= 0)
            continue;

        // 박스의 가로, 세로, 높이 중 하나라도 현재 큐브의 길이보다 작다면 continue
        // 셋 중 하나라도 큐브의 길이보다 작다면 큐브를 넣을 수 없다.
        if (length < cubes[i].length || width < cubes[i].length || height < cubes[i].length)
            continue;

        // 여기부터 아래는 큐브를 넣었을 때의 경우

        // 현재 큐브 갯수를 -1
        cubes[i].cnt--;
        // 사용한 큐브 갯수를 +1
        answer++;

        // 박스를 작은 박스들 3개의 공간으로 나누어 '분할' 한다.
        // Solve(큐브 길이, 박스 세로 - 큐브 길이, 큐브 길이, 현재 큐브 idx)
        Solve(cubes[i].length, width - cubes[i].length, cubes[i].length, i);
        // Solve(박스 가로 - 큐브 길이, 박스 세로, 큐브 길이, 현재 큐브 idx)
        Solve(length - cubes[i].length, width, cubes[i].length, i);
        // Solve(박스 가로, 박스 세로, 박스 높이 - 큐브 길이, 현재 큐브 idx)
        Solve(length, width, height - cubes[i].length, i);

        // 박스를 분할하고 작업을 마쳤으므로 반환
        // 반환하지 않으면 작은 큐브들을 현재 박스에 박스가 비어있다고 보고
        // 처음부터 넣는 작업을 반복하게 될 것임.
        return;
    }

    // 만약 현재 재귀에서 박스에 맞는 큐브를 하나도 발견하지 못했다면
    // 박스를 모두 채우지 못했다고 체크
    isFail = true;
}

int main()
{
    int length, width, height;
    // 채우고자 하는 박스의
    // 가로>>세로>>높이
    cin >> length >> width >> height;

    int N;
    // 큐브의 종류의 갯수
    cin >> N;

    // 큐브의 종류, 현재 큐브의 갯수
    int cube_idx, cube_cnt;
    for (int i = 0; i < N; i++)
    {
        cin >> cube_idx >> cube_cnt;

        // CubeInfo { length(큐브의 길이), cnt(큐브의 갯수) }
        CubeInfo cubeInfo;
        // 큐브의 한 변의 길이 = 2^cube_idx
        cubeInfo.length = (1 << cube_idx);
        cubeInfo.cnt = cube_cnt;

        cubes.push_back(cubeInfo);
    }

    // Solve(박스의 가로, 박스의 세로, 박스의 높이, 큐브 배열 시작 인덱스)
    Solve(length, width, height, N - 1);

    if (isFail)
        cout << "-1";
    else
        cout << answer;
}