#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int sum = 1;
    int multi = 0;
    for(int i = 0; i < num_list.size(); i++) 
    {
        
        sum  *= num_list[i];
        multi += num_list[i];
        
    }
    int multi_squ = multi * multi;
    if(sum < multi_squ) answer = 1;
    else answer = 0;
    return answer;
}