#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";

    for (int i=0; i < queries.size(); i++){
        int a = queries[i][0];
        int b = queries[i][1];
        reverse(my_string.begin() + a, my_string.begin() + b + 1);
    }
    return my_string;
}