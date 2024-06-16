#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
int R, C, N;
char Cave[101][101];
bool visited[101][101];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
vector<pair<int, int>> Cluster;

void Throw(int s, int idx) {
	if (idx % 2) {
		for (int i = 1; i <= C; i++) {
			if (Cave[s][i] == 'x') {
				Cave[s][i] = '.';
				break;
			}
		}
	}
	else {
		for (int i = C; i >= 1; i--) {
			if (Cave[s][i] == 'x') {
				Cave[s][i] = '.';
				break;
			}
		}
	}
}

void BFS(int i, int j) {
	queue<pair<int, int>> que;
	que.push({ i,j });
	visited[j][i] = true;

	while (!que.empty()) {
		int frontx = que.front().first; int fronty = que.front().second;
		que.pop();

		for (int k = 0; k < 4; k++) {
			int x = frontx + dx[k]; int y = fronty + dy[k];
			if (x <= 0 || x > C || y <= 0 || y > R || visited[y][x] || Cave[y][x] != 'x') continue;
			que.push({ x, y });
			visited[y][x] = true;
		}
	}
	
}

bool FindCluster() {
	bool flag = true;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= C; i++) {
		if(Cave[1][i] == 'x' && !visited[1][i]) BFS(i, 1);
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (Cave[i][j] == 'x' && !visited[i][j]) {
				flag = false;
				Cluster.push_back({ j, i });
			}
		}
	}
	return flag;
}

int Finddel() {
	int MIN = 104;
	for (pair<int, int> a : Cluster) {
		int x = a.first; int y = a.second;
		int cnt = 0;
		while (true) {
			y--;
			if (y < 1 || Cave[y][x] == 'x' && visited[y][x]) break;
			// Ŭ�����Ϳ� ����ִ� �� ���� -> �湮��� Ȱ�� ����
			cnt++;
		}
		MIN = min(MIN, cnt);
	}
	return MIN;
}

void Fall(int size) {
	for (pair<int, int> a : Cluster) {
		int x = a.first; int y = a.second;
		Cave[y][x] = '.';
		Cave[y - size][x] = 'x';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> R >> C;
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) cin >> Cave[i][j];
	}
	cin >> N;
	int idx = 1;
	while(N--){
		int s; cin >> s;
		//�ʱ�ȭ
		Cluster.clear();
		//���� ������
		Throw(s, idx);
		//���� Ŭ������ ã��
		if (!FindCluster()) {
			int size = Finddel(); // ����Ʈ�� ũ�� ã��
			Fall(size); // ����Ʈ����
		}
		idx++;
	}
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) cout << Cave[i][j];
		cout << "\n";
	}
	
}