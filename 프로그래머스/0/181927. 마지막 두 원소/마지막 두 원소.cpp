#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) 
{
    vector<int> answer = num_list;
    
    int lastIndex = num_list.size() - 1; // 마지막 인덱스
    int addNum; // 추가할 숫자
    
    if(num_list[lastIndex] > num_list[lastIndex - 1])
    {
        // 마지막 원소 > 마지막 직전 원소
        addNum = num_list[lastIndex] - num_list[lastIndex - 1];
    }
    else
    {
        // 마지막 원소 <= 마지막 직전 원소
        addNum = 2 * num_list[lastIndex];
    }
    
    answer.push_back(addNum);
    
    return answer;
}