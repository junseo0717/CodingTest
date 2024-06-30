#include<iostream>
#include<string.h>
using namespace std;
struct set { int r, c, h, w, k; };
int L, N, Q;
int chess[42][42];
int S[42][42]; // 기사 번호, 체력
set M[32];
int bk[32];
bool flag = true;
pair<int,int> visited[32];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void Input() {
	cin >> L >> N >> Q;
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) cin >> chess[i][j];
	}

	int idx = 0;
	for (int i = 1; i <= N; i++) {
		int r, c, h, w, k;
		cin >> r >> c >> h >> w >> k;
		bk[i] = k;
		M[i] = { r, c, h, w, k };
		for (int y = r; y < r + h; y++) {
			for (int x = c; x < c + w; x++) S[y][x] = i;
		}
	}
}

void Move(int a, int d) {			
	if (visited[a].first != 0 || M[a].k <= 0) return;
	visited[a].first = M[a].r; visited[a].second = M[a].c;

	int r = M[a].r + dy[d]; int c = M[a].c + dx[d];
	int h = M[a].h; int w = M[a].w;
	for (int y = r; y < r + h; y++) {
		for (int x = c; x < c + w; x++) {
			if (!flag) return; // 이전에 벽 만남
			if (y < 1 || y > L || x < 1 || x > L || chess[y][x] == 2) {
				flag = false; return;
			} // 벽만남
			if (S[y][x] != 0 && S[y][x] != a) Move(S[y][x], d);
		}
	}
	if (!flag) return;
	M[a].r += dy[d]; M[a].c += dx[d];
}

void Back() { //
	for (int i = 1; i <= N; i++) {
		//if (M[i].k <= 0) continue;
		if (visited[i].first != 0) {
			M[i].r = visited[i].first; 
			M[i].c = visited[i].second;
		}
	}
}

void Change(int a) { // 배열 바꾸고 체력 변경
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) S[i][j] = 0;
	}

	for (int i = 1; i <= N; i++) {
		int r = M[i].r; int c = M[i].c;
		int h = M[i].h; int w = M[i].w;
		if (M[i].k <= 0) continue;

		int del = 0;
		for (int y = r; y < r + h; y++) {
			for (int x = c; x < c + w; x++) {
				if (visited[i].first == 0 || a == i || M[i].k <= 0) continue;
				if (chess[y][x] == 1) { del++; }
			}
		}
		if(a != i) M[i].k -= del;

		 // 죽은 기사 처리
		for (int y = r; y < r + h; y++) {
			for (int x = c; x < c + w; x++) {
				S[y][x] = i;
				if (M[i].k <= 0) S[y][x] = 0;
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	Input();

	for (int q = 0; q < Q; q++) { // 100 * 30 * 30 * 30
		int i, d;
		cin >> i >> d;
		if (M[i].k <= 0) continue;
		flag = true;
		for (int i = 1; i <= N; i++) visited[i] = {0, 0};
		Move(i, d);

		if (flag) { Change(i); }
		else { Back(); }
		// 처음 기사가 밀렸다 하더라도 
		// 다음 기사가 밀리지 않았을 경우 
		// 처음 기사도 밀리지 않도록 설정하는 부분
			/*4 4 3
			1 1 1 1
			0 1 1 1
			0 1 1 0
			1 1 2 0
			3 1 2 2 4
			2 2 1 2 13
			1 4 2 1 15
			3 3 1 2 9
			4 0
			1 2
			1 0*/
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		if (M[i].k > 0) {
			ans += bk[i] - M[i].k;
		}
	}

	cout << ans;
}