#include <string>
#include <vector>

using namespace std;
int alpha_to_move[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};

int solution(string name) {
    int answer = 0;
    int n = name.length();
    // case 1 : 한 방향으로 조이스틱을 움직일 때 최소 이동 거리 
    int min_move = n - 1; 
    
    for(int x = 0; x<n; x++){
        answer += alpha_to_move[name[x] - 'A'];
        
        // case 2
        int y = x + 1; 
        while(y < n && name[y] == 'A') y++; 
        
        min_move = min(min_move, x + n - y + min(x, n - y));
    }
    
    answer += min_move;
    return answer;
}