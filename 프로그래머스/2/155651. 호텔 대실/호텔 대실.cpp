#include <string>
#include <vector>

using namespace std;

int my_stoi(string s)//시간을 정수형으로 변환 12:30 => 1230
{
    int ans = 0;
    for(int i=0;i<5;i++)
        if(isdigit(s[i])) ans = ans * 10 + s[i] - '0';
    return ans;
}

int solution(vector<vector<string>> book_time)
{
    int answer = 0, room[2410]={0,};// 0000 ~ 2409 까지인 이유는 마지막 대실 종료 시간(2359) + 청소시간 때문이다. 
    int n = book_time.size();
    for(int i=0;i<n;i++)
    {
        int s = my_stoi(book_time[i][0]), e = my_stoi(book_time[i][1]) + 10;
        if(e % 100 >= 60) e += 40;// 60분부터 시간을 늘려주어야 하기때문에
        for(int j=s;j<e;j++) room[j]++;
    }
    for(int i=0;i<2400;i++) answer = max(answer, room[i]);//가장 큰값이 곂치는 시간대의 필요 방 개수이다.
    return answer;
}