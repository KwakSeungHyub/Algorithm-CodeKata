#include <string>
#include <vector>

using namespace std;

void    go_to(int *nx, int *ny, char c, int num)
{// map 자료구조형을 사용하여도 편하게 구현할 수 있을 것 같다.
    if (c == 'E') *ny += num;
    else if (c == 'W') *ny -= num;
    else if (c == 'N') *nx -= num;
    else *nx += num;
}

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer(2);
    int n=park.size(), m=park[0].size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if (park[i][j] == 'S') answer = {i,j};//시작점 등록
    for(auto c : routes)
    {
        bool flag = true;
        int nx=answer[0], ny=answer[1];//타겟지점
        go_to(&nx, &ny, c[0], c[2]-'0');//이동
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;//공원 넘어가면
        for(int i=answer[0];i<=nx;i++) if(park[i][answer[1]] == 'X') flag = false;
        for(int i=nx;i<=answer[0];i++) if(park[i][answer[1]] == 'X') flag = false;
        // x좌표가 변했을때 사이에 장애물이 있는지 판단 
        for(int i=answer[1];i<=ny;i++) if(park[answer[0]][i] == 'X') flag = false;
        for(int i=ny;i<=answer[1];i++) if(park[answer[0]][i] == 'X') flag = false;
        // y좌표가 변했을때 사이에 장애물이 있는지 판단 
        if (flag) answer = {nx, ny};//이상없다면
    }
    return answer;
}