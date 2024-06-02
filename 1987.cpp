#include<iostream>
using namespace std;
struct set {
	int x, y, depth;
};
int R, C;
char in[21][21];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; int answer = 0; 

void DFS(int s, int e, int check, int depth) {
	answer = max(depth, answer); // 여기서 update하는걸 왜 잊니ㅜㅜ

	for (int k = 0; k < 4; k++) {
		int x = s + dx[k]; int y = e + dy[k];
		if (x < 0 || x >= C || y < 0 || y >= R) continue;
		int next = (1 << (int)(in[y][x] - 'A'));
		if((check & next) == 0) DFS(x, y, check | next ,depth + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) cin >> in[i][j];
	}
	DFS(0, 0, 1 << (int)(in[0][0] - 'A'), 1);

	cout << answer << "\n";
}