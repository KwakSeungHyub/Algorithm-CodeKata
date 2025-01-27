#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<bool>> queen, int& answer, int row)
{
    if (row == queen.size()) {
        answer++;            
        return;
    }

    for (int col = 0; col < queen[row].size(); ++col) { // 1️⃣ 첫번째 행당 하나만 들어갈 수 잇음
        bool isOk = true;
        for (int i = row - 1, j = 1; i >= 0; --i, ++j) { // 2️⃣3️⃣4️⃣ 를 검사하자. (이전 행들에서 검사)
            bool con1 = queen[i][col]; // 2️⃣같은 열에 놓여진 퀸이 있는지
            bool con2 = col - j >= 0 && queen[i][col - j]; // 3️⃣ 왼쪽 대각선에 놓여진 퀸이 있는지
            bool con3 = col + j <= queen.size() - 1 && queen[i][col + j]; // 4️⃣ 오른쪽 대각선에 놓여진 퀸이 있는지
            if (con1 || con2 || con3) { // 셋 중 하나라도 해당 된다면 이 queen[row][col] 자리에 퀸을 놓을 수 없다.
                isOk = false;
                break;
            }
        }
        if (isOk) { // 0 ~ row-1 행들을 모두 검사했어도 위 검사를 통과했다면 queen[row][col]은 놓여질 수 있다! 
            queen[row][col] = true; // 퀸 놓기
            DFS(queen, answer, row + 1); // 다음 행 검사하러 
            queen[row][col] = false; // 퀸 지우기. 
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<vector<bool>> queen(n, vector<bool>(n, false));
    DFS(queen, answer, 0);
    return answer;
}