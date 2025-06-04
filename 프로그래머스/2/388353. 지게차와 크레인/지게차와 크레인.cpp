#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool visited[51][51];

int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void Lift(char target, vector<string>& storage, int n, int m)
{
    vector<pair<int, int>> del;
    memset(visited, false, sizeof(visited));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i!=0 && i!=n-1 && j!=0 && j!=m-1) continue; //가장 자리 체크
            if(storage[i][j] == target) del.push_back({i, j}); //삭제 대상
            else if(storage[i][j] == ' ') //근처 경계 탐색
            {
                queue<pair<int, int>>q;
                q.push({i, j});
                visited[i][j]=1;
                
                while(!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    
                    for(int k=0; k<4; k++)
                    {
                        int ny = y+dy[k];
                        int nx = x+dx[k];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
                        if(storage[nx][ny]==target) //삭제 대상
                        {
                            del.push_back({nx, ny});
                            visited[nx][ny]=1;
                        }
                        
                        if(storage[nx][ny]==' ') //이어서 경계 탐색
                        {
                            q.push({nx, ny});
                            visited[nx][ny]=1;
                        }
                        
                    }
                }
            }
            
        }
    }
    
    for(auto i : del) //삭제 처리
    {
        storage[i.first][i.second] = ' ';
    }
}
    
void Crain(char target, vector<string>& storage, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(storage[i][j] == target) storage[i][j] = ' '; //삭제 처리
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int n = storage.size();
    int m = storage[0].size();
    
    for(auto request : requests)
    {
        if(request.size()==1) Lift(request[0], storage, n, m);
        else Crain(request[0], storage, n, m);
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(storage[i][j] != ' ') answer++;
        }
    }
    return answer;
}