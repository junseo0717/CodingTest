// CCTV는 벽을 통과할 수 없다
// 사각지대 : CCTV가 감시할 수 없는 영역
// 회전 가능 : 90도 방향
#include<iostream>
#include<vector>
using namespace std;

int N, M, ans = 987654321;
int room[10][10]; // 감시된 부분을 0 ~ 6이 아닌 수를 넣고 빼주는 방향으로 구현해보자
vector<pair<int, int>> CCTV; // x, y
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<pair<int,int>> Change(pair<int, int> pos, int k) {
	vector<pair<int, int>> ret;
	int x = pos.first; int y = pos.second;
	if (room[y][x] == 1) {
		while (1) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || room[ny][nx] == 6) break;
			// 조심2
			if (room[ny][nx] == 0) {
				room[ny][nx] = 8;
				ret.push_back({ nx, ny });
			}
			x = nx; y = ny; // 조심 ㅠㅠ
		}
	}
	else if (room[y][x] == 2) {
		for (int i = 0; i <= 2; i += 2) {
			int tx = x; int ty = y; //조심3 ㅠㅠ
			while (1) {
				int dir = (k + i) % 4;
				int nx = tx + dx[dir]; int ny = ty + dy[dir]; 
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || room[ny][nx] == 6) break;
				if (room[ny][nx] == 0) { // 조심2 ㅠㅠ
					room[ny][nx] = 8;
					ret.push_back({ nx, ny });
				}
				tx = nx; ty = ny; // 조심 ㅠㅠ
			}
		}
	}
	else if (room[y][x] == 3) {
		for (int i = 0; i < 2; i ++) {
			int tx = x; int ty = y;
			while (1) {
				int dir = (k + i) % 4;
				int nx = tx + dx[dir]; int ny = ty + dy[dir];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || room[ny][nx] == 6) break;
				if (room[ny][nx] == 0) {
					room[ny][nx] = 8;
					ret.push_back({ nx, ny });
				}
				tx = nx; ty = ny; // 조심 ㅠㅠ
			}
		}
	}
	else if (room[y][x] == 4) {
		for (int i = 0; i < 3; i++) {
			int tx = x; int ty = y;
			while (1) {
				int dir = (k + i) % 4;
				int nx = tx + dx[dir]; int ny = ty + dy[dir];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || room[ny][nx] == 6) break;
				if (room[ny][nx] == 0) {
					room[ny][nx] = 8;
					ret.push_back({ nx, ny });
				}
				tx = nx; ty = ny; // 조심 ㅠㅠ
			}
		}
	}
	else if (room[y][x] == 5) {
		for (int i = 0; i < 4; i++) {
			int tx = x; int ty = y;
			while (1) {
				int dir = (k + i) % 4;
				int nx = tx + dx[dir]; int ny = ty + dy[dir];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || room[ny][nx] == 6) break;
				if (room[ny][nx] == 0) { // 조심2 ㅜㅜ
					room[ny][nx] = 8;
					ret.push_back({ nx, ny });
				}
				tx = nx; ty = ny; // 조심 ㅠㅠ
			}
		}
	}
	return ret;
}

void DFS(int depth) { 
	if (depth == CCTV.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (room[i][j] == 0) cnt++;
			}
		}
		ans = min(cnt, ans);
		return;
	}

	for (int k = 0; k < 4; k++) {
		vector<pair<int, int>> turn_back = Change(CCTV[depth], k);
		DFS(depth + 1);
		for (auto i : turn_back) room[i.second][i.first] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
			if (room[i][j] != 6 && room[i][j] != 0) CCTV.push_back({j, i});
			//if (room[i][j] >= 1 && room[i][j] <= 5) CCTV.push_back({ j, i });
		}
	}
	DFS(0);
	cout << ans << "\n";
}