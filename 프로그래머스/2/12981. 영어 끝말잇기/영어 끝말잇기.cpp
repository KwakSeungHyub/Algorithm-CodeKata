#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<string> words)
{
	vector<string> v;

	for (int i = 0; i < words.size(); ++i)
	{
		if (i > 0 && words[i - 1].back() != words[i].front())
			return { i % n + 1, i / n + 1 };

		if (find(v.begin(), v.end(), words[i]) != v.end())
			return { i % n + 1, i / n + 1 };

		v.push_back(words[i]);
	}

	return { 0, 0 };
}