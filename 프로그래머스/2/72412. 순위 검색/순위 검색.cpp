#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<int>> um;

// void dfs(int cnt, vector<string> words, string res, int score)
// {// 재귀로 구현할 수 도 있긴 하지만 addCases함수보다는 조금 느리다.
//     if (cnt == 4)
//     {
//         um[res].push_back(score);
//         return ;
//     }
//     dfs(cnt+1, words, res + words[cnt], score);
//     dfs(cnt+1, words, res + "-", score);
// }

void addCases(vector<string> words, int score)
{
	/*
   		16가지의 방식으로 um에 넣어주는 함수이다.
    	예를 들어 지원자의 조건이 abcd라 가정하면
        -bcd, a-cd, ab-d, abc-, ....., ---- 와 같이 총 16가지의 형태가 나오게 된다.
        # 총 네 자리에서 각각 두가지의 선택방법이 있으므로 2^4가지수
    */
    for(int i=0; i<16; i++)
    {
        string res = "";
        int num = i;
        for(int j=0; j<4; j++)
        {
            if (num <= 0 || num%2 == 0) res += "-";
            else res += words[j];
            num /= 2;
        }
        um[res].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    vector<string> words(5);
    for (auto str : info)
    {
        istringstream iss(str);// 지원자의 정보를 스트림으로 변형시켜 공백 기준으로 나눌때 간단히 나눠준다.
        iss >> words[0] >> words[1] >> words[2] >> words[3] >> words[4];
        addCases(words, stoi(words[4]));
    }
    unordered_map<string, vector<int>>::iterator iter = um.begin();
    for (iter; iter != um.end(); iter++) sort(iter->second.begin(), iter->second.end());
    /*
    	미리 맵에 들어간 점수배열들을 정렬하여야 한다.
        query는 크기가 최대 100,000 이므로 query에서 확인할때 마다 해당 점수배열을 정렬하면 이부분에서
        정렬하는 것보다 쓸데없이 많이 정렬하기 때문이다.
        처음에는 내가 확인하는 점수배열들만 정렬하기 떄문에 아래 포문에 넣어야 더 빠를줄 착각하였다.
        애초에 um의 크기는 최대4*3*3*3이기 때문에 여기서 정렬하는게 훨씬 빠르다.
    */
    for (auto q : query)
    {
        int idx = 0;
        istringstream iss(q);
        iss >> words[0] >> words[4] >> words[1] >> words[4] >> words[2] >> words[4] >> words[3] >> words[4];
        vector<int> scores = um[words[0]+words[1]+words[2]+words[3]];
        if (scores.empty())
        {
            answer.push_back(0);
            continue ;
        }
        //sort(scores.begin(),scores.end()); 여기서 정렬을 하면 100,000번 하게 될 수도 있다.....
        idx = lower_bound(scores.begin(), scores.end(), stoi(words[4])) - scores.begin();
        answer.push_back(scores.size() - idx);//총인원수에서 조건보다 낮은 점수 인원 빼주기
    }
    return answer;
}