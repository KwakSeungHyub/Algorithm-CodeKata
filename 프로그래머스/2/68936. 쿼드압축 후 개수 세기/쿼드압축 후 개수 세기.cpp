#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(int x, int y, int size, vector<int>& answer, vector<vector<int>> &arr) {
    bool Zero = true, One = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] == 0) One = false;
            if (arr[i][j] == 1) Zero = false;
        }
    }

    if (Zero == true) {
        answer[0]++;
        return;
    }

    if (One == true) {
        answer[1]++;
        return;
    }

    DFS(x, y, size / 2, answer, arr);
    DFS(x, y + size / 2, size / 2, answer, arr);
    DFS(x + size / 2, y, size / 2, answer, arr);
    DFS(x + size / 2, y + size / 2, size / 2, answer, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);

    DFS(0, 0, arr.size(), answer, arr);

    return answer;
}