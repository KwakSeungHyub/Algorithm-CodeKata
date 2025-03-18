#include <string>
#include <vector>

using namespace std;
int W_max, W_min, B_max, B_min;
void compare(int num1, int num2, int num3, int num4){
        if(num1 > num2){
            W_max = num1;
            W_min = num2;
        }else{
            W_max = num2;
            W_min = num1;
        }
    
        if(num3 > num4){
            B_max = num3;
            B_min = num4;
        }
        else{
            B_max = num4;
            B_min = num3;
            
        }}
int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    compare(wallet[0], wallet[1], bill[0], bill[1]);
    
    while(B_min > W_min || B_max > W_max){
        if(bill[0] > bill[1]){
            bill[0] = bill[0]/2;
        }else{
            bill[1] = bill[1]/2;
        }
    compare(wallet[0], wallet[1], bill[0], bill[1]);
        answer++;
    }
    
    return answer;
}