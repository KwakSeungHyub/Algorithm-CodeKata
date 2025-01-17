#include <string>
#include <vector>

using namespace std;

void    recur(int cur, int *answer)
{
    if (cur == 0) return ;
    if (cur % 10 > 5 || (cur % 10 == 5 && (cur % 100) / 10 >= 5))
    {
        *answer += 10 - cur % 10;//올린만큼 ++
        cur += 10;//다음 자릿수 +1
    }
    else *answer += cur % 10;//내린만큼 ++
    if (cur / 10 > 0) recur(cur/10, answer);

}

int solution(int storey)
{
    int answer = 0;
    recur(storey, &answer);
    return answer;
}