#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    for(int i=brown/2-1; i>=3; i--)
    {// brown/2 는 행+열-2의 길이이다.
        int col = i, row = brown/2 - i;
        if ((col - 2)*row == yellow) return {col, row+2};
        // (행-2)*열이 곧 내부에 들어가는 yellow의 개수이다.
    }
    return {};
}