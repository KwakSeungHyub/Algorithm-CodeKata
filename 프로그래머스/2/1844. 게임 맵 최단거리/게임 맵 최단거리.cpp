#include<vector>
#include<queue>
using namespace std;

struct Pos {
    int x;
    int y;
    Pos(int _y, int _x) { y = _y; x = _x; }
};

int solution(vector<vector<int> > maps)
{
    const int n = maps.size(); // n 행
    const int m = maps[0].size(); // m 열
    // 방향 (시계방향으로 설정했다. 상우하좌. 방향 순서에 따라 노드의 방문 순서가 달라질 수 있다. 일반 큐라 큐에 들어간 순서대로 나오기 때문)
    int deltaY[4] = { -1, 0, 1, 0 }; 
    int deltaX[4] = { 0, 1, 0, -1 };

    vector<vector<bool>> checked(n, vector<bool>(m)); // 예약 된 적이 있는지. 큐에 삽입된적이 있는 위치일 때 true, 즉 이미 출발지로부터의 최단 거리가 업뎃 되어있는 
    vector<vector<int>> dist(n, vector<int>(m)); // 출발지로부터 해당 위치까지의 최단 거리
    queue<Pos> q; // 큐

    /* 출발지는 예약 작업을 할 수 없고 바로 방문해야 하니 미리 작업 */
    q.push(Pos(0, 0));  // 큐에 넣기
    checked[0][0] = true; // 예약
    dist[0][0] = 1; // 출발지의 거리는 1

    while (!q.empty()) {
        /* 방문 */
        Pos pos = q.front();
        q.pop();
        int nowY = pos.y;
        int nowX = pos.x;

        /* 예약 */
        for (int i = 0; i < 4; ++i) {  // 방문한 곳을 기준으로 상우하좌 4가지 방향에 있는 곳들 예약 처리
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            /* 다음에 방문할 수 잇는지, 즉 예약할 수 있는지 체크 */
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) // 1. 맵을 벗어난다면 예약할 수 없는 방향
                continue;
            if (maps[nextY][nextX] == 0) // 2. 벽이라면 예약할 수 없는 방향
                continue;
            if (checked[nextY][nextX]) // 3. 이미 예약된적이 있다면 예약할 수 없는 방향
                continue;
            
            /* 다음에 방문할 수 있는 곳이니 큐에 넣어 예약하기! -> ⭐그와 동시에 최단거리 업데이트⭐ */
            q.push(Pos(nextY, nextX));
            checked[nextY][nextX] = true;
            dist[nextY][nextX] = dist[nowY][nowX] + 1; // 최단 거리 업데이트 (방문 노드에서 +1 하면 최단거리!)
        }
    }
        
    if (!checked[n - 1][m - 1]) // 도착지가 한번도 큐에 들어갔던적이 없다면 애초에 갈 수 없었던 곳이니 -1 리턴
        return -1;
    else
        return dist[n - 1][m - 1]; // 도착지의 최단경로 리턴
}