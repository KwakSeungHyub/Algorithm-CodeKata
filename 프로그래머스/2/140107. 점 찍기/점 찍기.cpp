#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d)
{
    long long answer = d/k + 1;//x축 위의 해당점들
    for(long long i=0;i<d;i+=k)
        answer += (long long)sqrt(1LL*d*d - i*i)/k;// 해당 조건 점들
    return answer;
}