#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    vector<vector<string>> board(11, vector<string>(11,""));
    pair<int,int> pos = {5, 5};//시작 지점
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    string udrl = "URDL";
    for (auto dir : dirs) {
        pair<int, int> next_pos = pos;
        int idx = udrl.find(dir);
        next_pos.first += dx[idx];// 다음 이동 x위치
        next_pos.second += dy[idx];// 다음 이동 y위치
        if (next_pos.first < 0 || next_pos.second < 0 || next_pos.first > 10 || next_pos.second > 10) continue ;
        if ((dir == 'U' && board[pos.first][pos.second].find('D') == -1 && board[next_pos.first][next_pos.second].find('U') == -1) ||
            (dir == 'D' && board[pos.first][pos.second].find('U') == -1 && board[next_pos.first][next_pos.second].find('D') == -1) ||
            (dir == 'R' && board[pos.first][pos.second].find('L') == -1 && board[next_pos.first][next_pos.second].find('R') == -1) ||
            (dir == 'L' && board[pos.first][pos.second].find('R') == -1 && board[next_pos.first][next_pos.second].find('L') == -1)) {
            /* 
            	각 조건들은 다음 경로에 현재 dir이 없고 현재 경로에 현재 dir과 반대의 dir이 없는지 에 대한 판별이다.
                간단한 예시로 (5,5) 에서 현재 경로가 U이면 현재 (5, 5)에 D가 있는지와 (4,5)에 U가 있는지를 확인하는
                작업이다.
            */
            board[next_pos.first][next_pos.second] += dir;
            answer++;
        }
        pos = next_pos;
    }
    return answer;
}