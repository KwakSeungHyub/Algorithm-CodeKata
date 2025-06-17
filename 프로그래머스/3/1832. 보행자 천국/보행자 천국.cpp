#include <vector>
#include <cstring>
using namespace std;

int MOD = 20170805, r, c;
int dp[501][501][2]; // x, y좌표와 방향
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int DFS(int x, int y, int z, vector<vector<int>>& city_map) {
    if(x == r - 1 && y == c - 1) return 1;
    if(dp[x][y][z] != -1) return dp[x][y][z] % MOD;
    dp[x][y][z] = 0;
    
    for(int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c && city_map[nx][ny] != 1) {
            if(city_map[x][y] == 0 || (city_map[x][y] == 2 && i == z)) {
                dp[x][y][z] += DFS(nx, ny, i, city_map);
            }
        }
    }
   
    return dp[x][y][z] % MOD;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    r = m;
    c = n;
    memset(dp, -1, sizeof(dp));
    
    return DFS(0, 0, 0, city_map);
}