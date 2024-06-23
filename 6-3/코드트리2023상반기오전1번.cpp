#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, K;
struct set {
	int MAX, T, Add, R;
};
pair<int, int> Attack[11][11]; // ���ݷ�, ���� �����ߴ���?
bool visited[11][11]; // �ֺ� ������ ��žǥ��
bool visit[11][11]; // �Ÿ� �湮�迭
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
	// ������ 
	int y = check.Add - check.R; int x = check.R;
	Attack[y][x].first += (N + M);
	Attack[y][x].second = Time;
	return { x, y };
}

pair<int, int> Choose_B() {
	set check = { 0, 1001, 1004, 1001 }; // �ʱ�ȭ

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Attack[i][j].first == 0) continue;
			if (j == attacter.first && i == attacter.second) continue; // �ð��ʰ� ���� : �����ڰ� �����ڰ� �Ǵ� ��� ���ؾ� ��
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
	// ������
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

bool Lazer(int i, int j) { // (�߸�����... ��������)DFS + �켱���� ���� ���� -> �ִܰŸ� = BFS ����
	queue<pair<int, int>> que;
	que.push({ i, j });
	visit[j][i] = true;

	while (!que.empty()) {
		int frontx = que.front().first; int fronty = que.front().second;
		que.pop();

		if (frontx == damager.first && fronty == damager.second) { // ���ϴ� ������� Ȯ��
			Route(frontx, fronty); // ��� ã�� �Լ�
			return true;
		}
		for (int k = 0; k < 4; k++) {
			int x = frontx + dx[k]; int y = fronty + dy[k];
			if (x < 1) x = M;
			else if (x > M) x = 1;
			if (y < 1) y = N; // x�� y ��� ������ ��� �� ������ else if��� �ϸ� �ȵ�
			else if (y > N) y = 1;

			if (visit[y][x] || Attack[y][x].first <= 0) continue;
			que.push({ x, y });
			visit[y][x] = true;
			route[y][x] = { frontx, fronty }; // ��� ���ϴ� �˰��� ����
		}
	}
	return false; // �����ؾ��ϴ� ������ �������� ���ߴٴ� ��!
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

		if (x == attacter.first && y == attacter.second) continue; // ����
		if (Attack[y][x].first == 0) continue;
		Attack[y][x].first -= del / 2;
		if (Attack[y][x].first < 0) Attack[y][x].first = 0;
		visited[y][x] = true; // ������
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
		// �ʱ�ȭ
		Init();
		// ��ž 1���� �����ִ� ��� break �������� �߰�
		// ���� : 1���ۿ� ���� ��� �����Ű�� testcase 5��!!
		int cnt = Count();
		if (cnt == 1) break; 
		// ������&������ ����
		attacter = Choose_A(t); // x, y
		damager = Choose_B();
		// ������/��ź ����
		del = Attack[attacter.second][attacter.first].first;
		if (!Lazer(attacter.first, attacter.second)) {
			Bomb();
		}
		// ��ž ����
		Fix();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) ans = max(ans, Attack[i][j].first);
	}
	cout << ans << "\n";
}