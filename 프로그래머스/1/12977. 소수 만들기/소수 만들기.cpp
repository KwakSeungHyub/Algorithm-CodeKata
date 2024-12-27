#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    for(int i=0;i<nums.size();i++)
        for(int j=i+1;j<nums.size();j++)
            for(int k=j+1;k<nums.size();k++)
            {
                bool able = true;
                int sum = nums[i]+nums[j]+nums[k];
                
                for(int z=2;z<sum;z++)
                { 
                    if(sum%z==0){
                        able=false;
                        break;
                    }
                }
                
                if(able)
                    answer++;
                
            }
    

    return answer;
}