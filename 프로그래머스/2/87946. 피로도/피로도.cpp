#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0, n = dungeons.size();

    sort(dungeons.begin(), dungeons.end());
    do {
        int k_c = k, cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(k_c >= dungeons[i][0]) {
                k_c -= dungeons[i][1];
                cnt++;
            }
        }
        answer = max(answer, cnt);
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}