#include <iostream>
#include <vector>
using namespace std;

double total = 0;

vector<double> dir(4);

bool board[30][30];

void dfs(int x,int y,int N,double possible) {

	if (x < 0 || y < 0 || x >30 || y > 30 || board[x][y])
		return;


	if (N == 0) {
		total += possible;
		return;
	}
	board[x][y] = true;
	
	if (dir[0]){ // 동
		if(!board[x][y+1])
			dfs(x, y+1, N - 1, possible * dir[0]);
	}
	if (dir[1]) { // 서 
		if (!board[x][y - 1])
			dfs(x, y-1, N - 1, possible * dir[1]);
	}
	if (dir[2]) { // 남
		if (!board[x+1][y]) 
			dfs(x+1, y, N - 1, possible * dir[2]);
	}
	if (dir[3]) { // 북
		if (!board[x - 1][y])
			dfs(x-1, y, N - 1, possible * dir[3]);
	}
	board[x][y] = false;
}

int main(void) {
	
	int N;
	cin >> N;

	for (int i = 0; i < 4; i++) {
		cin >> dir[i];
		dir[i] /= 100;
	}

	dfs(15, 15, N , 1);
	cout.precision(16);
	cout << total;
}