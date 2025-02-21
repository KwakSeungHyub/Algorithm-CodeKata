#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();
    map<int,int> m;
    for(int i=0;i<n;i++) m[nums[i]]++;
    return min((int)m.size(), n/2);//폰켓몬 가지수 와 골라야하는 수 중 작은 값
}