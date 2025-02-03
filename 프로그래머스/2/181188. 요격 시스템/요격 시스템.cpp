#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets)
{
    int answer = 0, idx = 0;
    sort(targets.begin(), targets.end());//오름차순 정렬
    while (idx < targets.size())
    {//요격을 다할때까지
        int end = targets[idx++][1];// 타겟의 e 설정
        answer++;
        while (idx < targets.size() && targets[idx][0] < end)
        {// end 보다 해당 타겟의 s가 작다면 밀어준다.
            // 해당 타깃이 end를 설정해 놓은 타겟보다 end가 작을 때 갱신
            if (targets[idx][1] < end) end = targets[idx][1];
            idx++;
        }
    }
    return answer;
}