#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int bfs(vector<string> maps, queue<pair<int,int>> q, int n, int m, char target)
{
    int vis[n][m]; memset(vis, -1, sizeof(vis));// 방문배열 -1로 초기화
    vis[q.front().first][q.front().second] = 0;// 시작지점 0
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int dir=0;dir<4;dir++)// 북동남서 탐색
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;// 범위밖이면
            if(maps[nx][ny] == 'X' || vis[nx][ny] != -1) continue;// 길이 아니거나 이미 방문했다면
            if(maps[nx][ny] == target) return (vis[cur.first][cur.second] + 1);// 목표지점이면
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    return -1;// 방문 불가능하면
}

int solution(vector<string> maps)
{
    int answer = 0, n = maps.size(), m = maps[0].size(), exit[2];
    queue<pair<int,int>> s_l, l_e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maps[i][j] == 'S') s_l.push({i,j});//시작지점
            else if(maps[i][j] == 'L') l_e.push({i,j});//레버
            else if(maps[i][j] == 'E')//출구
            {
                exit[0] = i;
                exit[1] = j;
            }
        }
    }
    int tmp;
    answer = bfs(maps, s_l, n, m, 'L');
    if(answer == -1) return -1;
    else
        tmp = bfs(maps, l_e, n, m, 'E');
    if(tmp == -1) return -1;
    else
        answer += tmp;    
    return answer;
}