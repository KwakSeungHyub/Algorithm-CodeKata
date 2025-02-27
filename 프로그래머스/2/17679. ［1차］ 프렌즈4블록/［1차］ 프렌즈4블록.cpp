#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int check_board(vector<string> board);
void drop_block(vector<string>& board, set<vector<int>> check);

int check_board(int m, int n, vector<string> board) {
    set<vector<int>> check;
    
    /*for (const auto& b : board) {
        cout << b << endl;
    }
    cout << endl;*/
    
    // 2x2 매트릭스로 찾음
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (board[i][j] != '#' && board[i][j] == board[i + 1][j]) {
                if (board[i][j + 1] == board[i + 1][j + 1]) {
                    if (board[i][j] == board[i + 1][j + 1]) {
                        check.insert({i, j});
                        check.insert({i, j + 1});
                        check.insert({i + 1, j});
                        check.insert({i + 1, j + 1});
                    }
                }
            }
        }
    }
    
    if (check.empty()) {
        return 0;
    }
    else {
        drop_block(board, check);
        return check.size() + check_board(m, n, board);
    }
}

void drop_block(vector<string>& board, set<vector<int>> check) {
    for (const auto& idx : check) {
        board[idx[0]][idx[1]] = '#';
        for (int i = idx[0]; i > 0; i--) {
            swap(board[i][idx[1]], board[i - 1][idx[1]]);
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    answer = check_board(m, n, board);
    
    return answer;
}
