#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct set { int x, y, state; };
int w, h;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int visited[20][20][(1 << 10)]; // 경우의수 비트마스킹으로 처리
int Space[20][20];
int cnt = 0; // 더러운 곳 총 개수

void BFS(int i, int j) { // 완탐
	queue<set> que;
	que.push({ i, j, 0 });

	while (!que.empty()) {
		int frontx = que.front().x; int fronty = que.front().y;
		int state = que.front().state;
		que.pop();

		for (int d = 0; d < 4; d++) {
			int x = frontx + dx[d]; int y = fronty + dy[d];
			if (x < 0 || x >= w || y < 0 || y >= h || Space[y][x] == -1) continue;

			if (Space[y][x] > 0) { // 더러운곳 
				int ns = state | (1 << (Space[y][x] - 1));
				if (visited[x][y][ns]) continue;
				visited[x][y][ns] = visited[frontx][fronty][state] + 1; // depth를 값으로 가짐
				que.push({ x, y, ns });

				if (ns == ((1 << cnt) - 1)) { // 더러운 곳 모두 체크됨
					cout << visited[x][y][ns] << "\n";
					return;
				}
			}
			else {
				if (visited[x][y][state]) continue;
				visited[x][y][state] = visited[frontx][fronty][state] + 1; 
				que.push({ x, y, state });
			}
		}
	}
	cout << -1 << "\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		cnt = 0;
		memset(visited, 0, sizeof(visited));
		pair<int, int> robot;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char a; cin >> a;
				if (a == 'o') { robot = { j, i }; Space[i][j] = 0; }
				else if (a == '*') { Space[i][j] = ++cnt; }
				else if (a == '.') { Space[i][j] = 0; }
				else if (a == 'x') { Space[i][j] = -1; }
			}
		}
		BFS(robot.first, robot.second);
	}
}