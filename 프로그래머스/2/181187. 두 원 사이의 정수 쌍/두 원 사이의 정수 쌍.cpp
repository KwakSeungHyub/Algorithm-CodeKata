#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int x=1;x<=r2;x++){
        long long max_y=floor(sqrt(r2*1ll*r2-x*1ll*x));
        long long min_y=x<r1?ceil(sqrt(r1*1ll*r1-x*1ll*x)):0;
        answer+=(max_y-min_y+1);
    }
    return answer*4;
}