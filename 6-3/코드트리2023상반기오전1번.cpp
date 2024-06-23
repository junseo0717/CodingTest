#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, K;
struct set {
	int MAX, T, Add, R;
};
pair<int, int> Attack[11][11]; // 공격력, 언제 공격했는지?
bool visited[11][11]; // 주변 피해자 포탑표시
bool visit[11][11]; // 거리 방문배열
pair<int, int> route[11][11];
pair<int, int> attacter;
pair<int, int> damager;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int del = 0;

void Input() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> Attack[i][j].first;
	}
}
pair<int, int> Choose_A(int Time) {
	set check = { 5001, 0, 0, 0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Attack[i][j].first == 0) continue;
			if (check.MAX > Attack[i][j].first) {
				check = { Attack[i][j].first, Attack[i][j].second, i + j, j };
			}
			else if (check.MAX == Attack[i][j].first) {
				if (check.T < Attack[i][j].second) {
					check = { Attack[i][j].first, Attack[i][j].second, i + j, j };
				}
				else if (check.T == Attack[i][j].second) {
					if (check.Add < i + j) {
						check = { Attack[i][j].first, Attack[i][j].second, i + j, j };
					}
					else if (check.Add == i + j) {
						if (check.R < j) {
							check = { Attack[i][j].first, Attack[i][j].second, i + j, j };
						}
					}
				}
			}
		}
	}
	// 공격자 
	int y = check.Add - check.R; int x = check.R;
	Attack[y][x].first += (N + M);
	Attack[y][x].second = Time;
	return { x, y };
}

pair<int, int> Choose_B() {
	set check = { 0, 1001, 1004, 1001 }; // 초기화

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Attack[i][j].first == 0) continue;
			if (j == attacter.first && i == attacter.second) continue; // 시간초과 주의 : 공격자가 피해자가 되는 경우 피해야 함
			if (check.MAX < Attack[i][j].first) {
				check = { Attack[i][j].first, Attack[i][j].second, i + j, j };
			}
			else if (check.MAX == Attack[i][j].first) {
				if (check.T > Attack[i][j].second) {
					check = { Attack[i][j].first, Attack[i][j].second, i + j, j };
				}
				else if (check.T == Attack[i][j].second) {
					if (check.Add > i + j) {
						check = { Attack[i][j].first, Attack[i][j].second, i + j, j };
					}
					else if (check.Add == i + j) {
						if (check.R > j) {
							check = { Attack[i][j].first, Attack[i][j].second, i + j, j };
						}
					}
				}
			}
		}
	}
	// 피해자
	int y = check.Add - check.R; int x = check.R;
	return { x, y };
}

void Route(int frontx, int fronty) {
	Attack[damager.second][damager.first].first -= del;
	if (Attack[damager.second][damager.first].first < 0) Attack[damager.second][damager.first].first = 0;

	if (route[fronty][frontx] == attacter) return;
	int nx = route[fronty][frontx].first; int ny = route[fronty][frontx].second;
	while (true) {
		visited[ny][nx] = true;
		Attack[ny][nx].first -= (del / 2);
		if (Attack[ny][nx].first < 0) Attack[ny][nx].first = 0;
		pair<int, int> temp = route[ny][nx];
		nx = temp.first; ny = temp.second;
		if (nx == attacter.first && ny == attacter.second) break;
	}
}

bool Lazer(int i, int j) { // (잘못생각... 감떨어짐)DFS + 우선순위 방향 존재 -> 최단거리 = BFS 국룰
	queue<pair<int, int>> que;
	que.push({ i, j });
	visit[j][i] = true;

	while (!que.empty()) {
		int frontx = que.front().first; int fronty = que.front().second;
		que.pop();

		if (frontx == damager.first && fronty == damager.second) { // 원하는 경로인지 확인
			Route(frontx, fronty); // 경로 찾는 함수
			return true;
		}
		for (int k = 0; k < 4; k++) {
			int x = frontx + dx[k]; int y = fronty + dy[k];
			if (x < 1) x = M;
			else if (x > M) x = 1;
			if (y < 1) y = N; // x와 y 모두 범위를 벗어날 수 있으니 else if라고 하면 안됨
			else if (y > N) y = 1;

			if (visit[y][x] || Attack[y][x].first <= 0) continue;
			que.push({ x, y });
			visit[y][x] = true;
			route[y][x] = { frontx, fronty }; // 경로 구하는 알고리즘 적용
		}
	}
	return false; // 공격해야하는 지점에 도달하지 못했다는 것!
}

void Bomb() {
	int tx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int ty[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int x = damager.first; int y = damager.second;

	Attack[y][x].first -= del;
	if (Attack[y][x].first < 0) Attack[y][x].first = 0;
	visited[y][x] = true;

	for (int k = 0; k < 8; k++) {
		x = damager.first + tx[k]; y = damager.second + ty[k];
		if (x < 1) x = M;
		else if (x > M) x = 1;
		if (y < 1) y = N;
		else if (y > N) y = 1;

		if (x == attacter.first && y == attacter.second) continue; // 주의
		if (Attack[y][x].first == 0) continue;
		Attack[y][x].first -= del / 2;
		if (Attack[y][x].first < 0) Attack[y][x].first = 0;
		visited[y][x] = true; // 피해자
	}
}
void Fix() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (attacter.first == j && attacter.second == i) continue;
			if (visited[i][j] || Attack[i][j].first == 0) continue;
			if (damager.first == j && damager.second == i) continue;
			Attack[i][j].first++;
		}
	}
}
int Count() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Attack[i][j].first) cnt++;
		}
	}
	return cnt;
}
void Init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			route[i][j] = { 0,0 };
			visited[i][j] = false;
			visit[i][j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	Input();
	
	for(int t = 1; t <= K; t++) {
		// 초기화
		Init();
		// 포탑 1개만 남아있는 경우 break 조건으로 추가
		// 주의 : 1개밖에 없는 경우 종료시키기 testcase 5번!!
		int cnt = Count();
		if (cnt == 1) break; 
		// 공격자&피해자 선정
		attacter = Choose_A(t); // x, y
		damager = Choose_B();
		// 레이저/포탄 공격
		del = Attack[attacter.second][attacter.first].first;
		if (!Lazer(attacter.first, attacter.second)) {
			Bomb();
		}
		// 포탑 정비
		Fix();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) ans = max(ans, Attack[i][j].first);
	}
	cout << ans << "\n";
}