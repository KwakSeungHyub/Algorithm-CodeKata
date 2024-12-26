#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;
    if(angle < 90) {
       answer = 1;
       return answer;    
    } 
    if(angle == 90)  answer = 2;
    else if(90 < angle < 180) answer = 3;
    if(angle == 180 ) answer = 4;
    return answer;
}