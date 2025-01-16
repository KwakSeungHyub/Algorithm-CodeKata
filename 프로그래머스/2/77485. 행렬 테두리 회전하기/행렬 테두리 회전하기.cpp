#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int board[104][104];
vector<int> solution(int r, int c, vector<vector<int>> q) {
    
    vector<int> answer;
    int cnt = 1;
    for(int i=1; i<= r; i++){
        for(int j=1; j<=c; j++){
            board[i][j] = cnt;
            cnt++;
        }
    }
    for(int i=0; i<q.size(); i++){
        vector<int> tmp;
        vector<pair<int,int>> xy;
        int mn = 1e9;
        int sty = q[i][0];
        int stx = q[i][1];
        int eny = q[i][2];
        int enx = q[i][3];
        // 오른쪽
        for(int i=stx; i<=enx; i++){
            tmp.push_back(board[sty][i]);
            mn = min(mn, board[sty][i]);
            xy.push_back({sty,i});
        }
        // 아래
        for(int i=sty+1; i<=eny; i++){
            tmp.push_back(board[i][enx]);
            mn = min(mn, board[i][enx]);
            xy.push_back({i, enx});
        }
        
        // 왼쪽
        for(int i=enx-1; i>= stx; i--){
            tmp.push_back(board[eny][i]);
            mn = min(mn, board[eny][i]);
            xy.push_back({eny, i});
        }
        
        // 위
        for(int i=eny-1; i>= sty+1; i--){
            tmp.push_back(board[i][stx]);
            mn = min(mn, board[i][stx]);
            xy.push_back({i, stx});
        }
        
        rotate(tmp.rbegin(), tmp.rbegin()+1, tmp.rend());
        
        for(int i=0; i<xy.size(); i++){
            board[xy[i].first][xy[i].second] = tmp[i];
        }
        
        answer.push_back(mn);
    }
    return answer;
}