#include<iostream>
#include<vector>
using namespace std;
int N;
bool Dragon[104][104];
int dx[] = {1, 0, -1, 0};
int dy[] = { 0, -1, 0, 1 };
int tx[] = { 1, 0, -1};
int ty[] = { 0, 1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		pair<int, int> pos;
		vector<int> check;
		int s, k;
		cin >> pos.first >> pos.second >> s >> k;
		check.push_back(s);
		for (int d = 0; d < k; d++) {
			for (int t = check.size() - 1; t >= 0; t--) {
				int temp = 0;
				if (check[t] == 3) temp = 0;
				else { temp = check[t] + 1; }
				check.push_back(temp);
			}
		}
		int x = pos.first; int y = pos.second; // 30분 고민한 실수 주의! "-1"
		Dragon[y][x] = true;
		for (int i = 0; i < check.size(); i++) {
			x += dx[check[i]]; y += dy[check[i]];
			if (x < 0 || x > 100 || y < 0 || y > 100) continue;
			Dragon[y][x] = true;
		}
	}

	int answer = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (!Dragon[i][j]) continue;
			int x = j; int y = i; bool flag = true;
			for (int d = 0; d < 3; d++) {
				x += tx[d]; y += ty[d];
				if (x < 0 || x > 100 || y < 0 || y > 100 || !Dragon[y][x]) {
					flag = false;
					break;
				}
			}
			if (flag) answer++;
		}
	}
	cout << answer << "\n";
}