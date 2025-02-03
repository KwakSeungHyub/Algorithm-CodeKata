#include <string>
#include <vector>
#define NUM 1000000000000000

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> stars;
    long long minX = NUM, maxX = -NUM, minY = NUM, maxY = -NUM;
    for (int i = 0; i < line.size(); i++) {
        for (int k = i + 1; k < line.size(); k++) {
            long long mod = (long long)line[i][0] * line[k][1] - (long long)line[i][1] * line[k][0];
            if (mod == 0) continue;
            long long bfed = (long long)line[i][1] * line[k][2] - (long long)line[i][2] * line[k][1] ;
            long long ecaf = (long long)line[i][2] * line[k][0] - (long long)line[i][0] * line[k][2];
            if (bfed % mod || ecaf % mod) {
                continue;
            }
            long long x = bfed / mod, y = ecaf / mod;
            stars.push_back({ x,y });
            minX = min(minX, x); minY = min(minY, y);
            maxX = max(maxX, x); maxY = max(maxY, y);
        }
    }
    string row = string(maxX - minX + 1, '.');
    vector<string> answer(maxY - minY + 1, row);
    for (int i = 0; i < stars.size();i++) {
        long long x = stars[i].first, y = stars[i].second;
        answer[abs(y - maxY)][abs(x - minX)] = '*';
    }
    return answer;
}