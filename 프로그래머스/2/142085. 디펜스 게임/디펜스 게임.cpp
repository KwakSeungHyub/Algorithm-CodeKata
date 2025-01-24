#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;//작으면 top으로 오게됨
    for (int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);
        if (pq.size() > k)// 무적권보다 개수보다 크게 쌓이게되면
        {
            sum += pq.top();// 가장 작은값 ++
            pq.pop();// 빼준다.
        }
        if (sum > n) return i;// 종료조건
    }
    return enemy.size();// 모든라운드 통과
}