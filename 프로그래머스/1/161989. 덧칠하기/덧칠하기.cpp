#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1; 
    int tmp = section[0];
    
    for(int i = 0; i < section.size(); ++i) {
        if(section[i] < tmp + m) continue;
        else {
            tmp = section[i];
            answer++;
        }
    }
    return answer;
}