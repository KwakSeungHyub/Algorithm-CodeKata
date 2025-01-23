#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards)
{
    int n = cards.size();
    vector<bool> vis(n+1, false);
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int cur = cards[i], cnt = 0;
        while (!vis[cur])
        {//아직 고른 카드가 아니라면
            vis[cur] = true;//골랐음 체크
            cur = cards[cur-1];//현재카드 갱신
            cnt++; //개수++;
        }
        if (cnt) res.push_back(cnt);//묶음이면 추가
    }
    sort(res.begin(), res.end(), greater<int>());//내림차순 정렬
    if (res.size() > 1) return res[0]*res[1];//묶음이 2개이상이면
    return 0;
}