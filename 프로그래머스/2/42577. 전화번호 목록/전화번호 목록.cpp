#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book)
{
    map<string,int> m;
    for(int i=0;i<phone_book.size();i++) m[phone_book[i]]++;//맵에 넣고
    for(int i=0;i<phone_book.size();i++)
        for(int j=1;j<phone_book[i].size();j++)
            if(m[phone_book[i].substr(0,j)]) return false;
	// phone_book의 접두사를 하나씩 넣어보면서 map에 들어있으면 false 리턴
    /*	예시
    	phone_book[0] = "123" 이면
        map에 "1", "12"를 넣어서 체크
    */
    return true;
}