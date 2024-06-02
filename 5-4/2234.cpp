#include<iostream>
#include<string.h>
using namespace std;
int N, M;
int map[51][51];
int visited[51][51]; // 방 함께 check
int roomsize[251];
int ans1, ans2, ans3;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int DFS(int j, int i) {
	if (visited[i][j]) return 0;
	visited[i][j] = ans1;
	int ret = 1;  // 정리

	for (int k = 0; k < 4; k++) {
		int x = j + dx[k]; int y = i + dy[k];
		if (x <= 0 || x > N || y <= 0 || y > M || visited[y][x] || map[i][j] & (1 << k)) continue;
		ret += DFS(x, y); // 정리
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) cin >> map[i][j];
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				ans1++;
				// 두개의 방을 더해서 ans3를 구하는 방식
				roomsize[ans1] = DFS(j, i);
				ans2 = max(ans2, roomsize[ans1]);
			}
		}
	}

	/*for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 4; k++) {
				int x = j + dx[k]; int y = i + dy[k];
				if (!(map[i][j] & (1 << k)) || x <= 0 || x > N || y <= 0 || y > M) continue;
				map[i][j] &= ~(1 << k);
				memset(visited, false, sizeof(visited));
				ans3 = max(ans3, DFS(j, i));
				map[i][j] |= (1 << k);

			}
		}
	}*/

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (i + 1 <= M) { // 더블 체크 주의
				int x = visited[i + 1][j];
				int y = visited[i][j];
				if (x != y) {
					ans3 = max(ans3, roomsize[x] + roomsize[y]);
				}
			}
			if (j + 1 <= N) {
				int x = visited[i][j + 1];
				int y = visited[i][j];
				if (x != y) {
					ans3 = max(ans3, roomsize[x] + roomsize[y]);
				}
			}
		}
	}
	cout << ans1 << "\n" << ans2 << "\n" << ans3 << "\n";
}