#include <string>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> outN(1000001); //out
vector<vector<int>> inN(1000001); //int
set<int> nodeSet;

int calc(int stN)
{
    int nowN=stN;
    while(true)
    {
        if (outN[nowN].size()>=2){
            return 3;
        }
        else if (outN[nowN].size()==0)
        {
            return 2;
        }
        nowN=outN[nowN][0];        
        if (nowN==stN)
        {
            return 1;
        }
    }
}


vector<int> solution(vector<vector<int>> edges) {
    int maxNum=0;
    vector<int> answer(4,0);
    for (int i=0; i<edges.size(); i++)
    {
        outN[edges[i][0]].push_back(edges[i][1]);
        inN[edges[i][1]].push_back(edges[i][0]);
        nodeSet.insert(edges[i][1]);
        nodeSet.insert(edges[i][0]);
    }
    int stN;
    for (set<int>::iterator i=nodeSet.begin(); i!=nodeSet.end(); i++)
    {
        if (inN[*i].size()==0 && outN[*i].size()>=2)
        {
            stN=*i;
            break;
        }
    }
    answer[0]=stN;
    for (int i=0; i<outN[stN].size(); i++)
    {
        answer[calc(outN[stN][i])]+=1;
    }  
    return answer;
}