#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int f=0,d=0;
    string first_s="";
    
    for(int i = 0 ; i < s.size(); i++)
    {
        if(first_s == "")
        {
            first_s = to_string(s[i]);
            f++;
            continue;
        }
        
        if (first_s == to_string(s[i]))
            f++;
        else
            d++;

        if( f == d)
        {
            answer++;
            f=0;d=0;
            first_s = "";
        }
        
    }
    
    if ( f != 0)
        answer += 1;
    
    return answer;
}