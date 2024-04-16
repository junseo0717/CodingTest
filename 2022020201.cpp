#include<iostream>
#include<map>
#include<string.h>
#include<queue>
#include<vector>
#define MAX 10000
using namespace std;
struct set
{
	int x, y, w;
};

int dx[] = { 0, -1, 1, 0 }; // 방향 우선순위
int dy[] = { -1, 0, 0, 1 };
vector<int> people[15][15];
bool visit[15][15]; // 다음에 방문하지 못하게 될 부분 체크 true;
bool visit2[15][15]; // 다음에 방문하지 못하게 될 부분 체크 true;
bool check[15][15]; // 움직일때 사용할 함수
bool check2[31];
bool check3[31];
map<int, pair<int, int>> store;
vector<pair<int, int>> baseccamp;
int n, m;

int Move(pair<int, int> b, pair<int, int> s) {
	memset(check, false, sizeof(check));
	queue<set> que;
	que.push({ b.first, b.second, 0 });
	check[b.second][b.first] = true;

	while (!que.empty()) {
		int frontx = que.front().x;
		int fronty = que.front().y;
		int depth = que.front().w;
		if (s.second == frontx && s.first == fronty) return depth; // 4. BFS 구현 시 조심 1 값 확인은 pop에서, 시간초과 문제 발생
		que.pop();

		for (int k = 0; k < 4; k++) {
			int x = frontx + dx[k]; int y = fronty + dy[k];
			if (x < 0 || y < 0 || x >= n || y >= n || visit2[y][x] || check[y][x]) continue;
			if (depth >= 226) return MAX;
			que.push({ x, y, depth + 1 });
			check[y][x] = true; // 방문배열 확인은 무조건 push 아래에
		}
	}
	return MAX;
}
//for문 +인지  -인지 확인 제대로..
/* 2. 정리 벡터에 있는 것 없앨때에는 이렇게 temp 배열 활용해서 옮겨야함 처음부터 집중*/
void remove() {
	vector<int> temp[15][15];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int p = people[i][j].size() - 1; p >= 0; p--) {
				if (people[i][j][p] != 0) temp[i][j].push_back(people[i][j][p]);
				people[i][j].pop_back();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int p = 0; p < temp[i][j].size(); p++) { // 3. p--라고 잘못 씀
				people[i][j].push_back(temp[i][j][p]);
			}
		}
	}
}

// 1 번 수행
void One() {
	memset(check2, false, sizeof(check2));
	int MIN = MAX; int px = 0; int py = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int p = people[i][j].size() - 1; p >= 0; p--) {
				MIN = MAX; px = 0; py = 0;
				int P = people[i][j][p];
				if (check2[P] || P <= 0 || check3[P])  continue;
				for (int k = 0; k < 4; k++) {
					int x = j + dx[k]; int y = i + dy[k];
					if (x < 0 || y < 0 || x >= n || y >= n || visit2[y][x]) continue;
					int M = Move({ x, y }, store[P]);
					if (MIN > M) {
						MIN = M;
						px = x; py = y;
					}
				}
				people[i][j][p] = 0;
				if (MIN == 0) { 
					visit[py][px] = true;
					check3[P] = true;
				}
				else if (MIN != MAX) { // 긴장 놓지 말기 MIN == MAX 일때에는 움직일 수 없는 것이 나와서 시간초과됨!ㅜㅜ
					people[py][px].push_back(P);
					check2[P] = true; /*1. 이미 이동한 사람인 것 확인배열 필요*/
				}
			}
		}
	}
	remove();
}

// 3 번 수행
void Three(int t) {
	int MIN = MAX; int px = 0; int py = 0;
	if (t <= m) {
		for (int i = 0; i < baseccamp.size(); i++) {
			if (visit2[baseccamp[i].second][baseccamp[i].first]) continue;
			int M = Move(baseccamp[i], store[t]);
			if (MIN > M) {
				MIN = M;
				px = baseccamp[i].first; // 6. 행열 조심하기..ㅜ
				py = baseccamp[i].second;
			}
			else if (MIN == M && M != MAX) {
				if (py > baseccamp[i].second) {
					MIN = M;
					px = baseccamp[i].first;
					py = baseccamp[i].second;
				}
				else if (py == baseccamp[i].second) {
					if (px > baseccamp[i].first) {
						MIN = M;
						px = baseccamp[i].first;
						py = baseccamp[i].second;
					}
				}
			}
		}
		people[py][px].push_back(t);
		visit[py][px] = true;
	}
}

// 체크해둔 곳 모두 -1로 변경하기
void Change() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j])  visit2[i][j] = true;
		}
	}
}

bool Check() {
	for (int i = 1; i <= m; i++) {
		if (!check3[i]) return true;
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) baseccamp.push_back({ j, i });
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		store[i] = { a - 1, b - 1 }; // 4. 행열 조심하기, 인덱스 1,1 기준인 것 조심하기.. 이야 미친놈이 실수만 7개
	}

	int T = 1;
	while (true) {
		One();
		Change();  // 5. 문제 제대로 읽기 
		if (!Check()) break;
		Three(T); 
		Change();
		T++;
	}
	cout << T << "\n";
}