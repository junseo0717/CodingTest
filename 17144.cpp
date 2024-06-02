#include<iostream>
using namespace std;
int R, C, T;
int room[60][60];
int temp[60][60];
int air = 0; // c
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] < 0) air = i; // æ∆∑ßƒ≠ ¿˙¿Â
		}
	}

	while (T--) {
		// »ÆªÍ
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!room[i][j]) continue;
				if (room[i][j] < 0) {
					temp[i][j] = -1;
					continue;
				}
				int cnt = 0;
				int val = room[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int x = j + dx[k]; int y = i + dy[k];
					if (room[y][x] == - 1 || x < 0 || x >= C || y < 0 || y >= R) continue;
					cnt++;
					temp[y][x] += val;
				}
				temp[i][j] += room[i][j] - (val * cnt);
			}
		}
		
		air--; // ¿≠ƒ≠ 3
		for (int i = air - 2; i >= 0; i--) temp[i + 1][0] = temp[i][0];
		for (int i = 1; i < C; i++) temp[0][i - 1] = temp[0][i];
		for (int i = 1; i <= air; i++) temp[i - 1][C - 1] = temp[i][C - 1];
		for (int i = C - 2; i > 0; i--) temp[air][i + 1] = temp[air][i];
		temp[air][1] = 0;

		air++; // 4
		for (int i = air + 2; i < R; i++) temp[i - 1][0] = temp[i][0];
		for (int i = 1; i < C; i++) temp[R - 1][i - 1] = temp[R - 1][i];
		for (int i = R - 2; i >= air; i--) temp[i + 1][C - 1] = temp[i][C - 1];
		for (int i = C - 2; i > 0; i--) temp[air][i + 1] = temp[air][i];
		temp[air][1] = 0;

		// √ ±‚»≠
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				room[i][j] = temp[i][j];
				temp[i][j] = 0;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] < 0) continue;
			answer += room[i][j];
		}
	}
	cout << answer << "\n";
}
