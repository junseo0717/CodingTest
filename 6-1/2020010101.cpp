#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct set {
	int x, y, d;
};
int n, m, h, k, idx = 0;
int term = 0;
set runner[10001];
set catcher;
vector<pair<int,int>> tree;
int dx[] = { 0, 1, 0, -1, 0 };
int dy[] = { 0, 0, 1, 0, -1 };
int tx[] = { 0, 1, 0, -1 };
int ty[] = { -1, 0, 1, 0 };
int loop_count = 1, cnt = 1, check = 0;
bool flag = true;
int score = 0;

void input() {
	cin >> n >> m >> h >> k;
	catcher = { (n / 2) + 1, (n / 2) + 1, 0 }; 

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		runner[idx++] = { b, a, c }; 
	}
	for (int i = 0; i < h; i++) {
		int a, b; cin >> a >> b;
		tree.push_back({ b, a });
	}
}

void Move_R(){
	for (int i = 0; i < idx; i++) {
		int x1 = runner[i].x; int y1 = runner[i].y; int d = runner[i].d;
		int x2 = catcher.x; int y2 = catcher.y;
		if (abs(x1 - x2) + abs(y1 - y2) <= 3) {
			pair<int, int> temp = { x1 + dx[d], y1 + dy[d] };
			if (temp.first <= 0 || temp.first > n || temp.second <= 0 || temp.second > n) {
				//방향 바꿔주고
				if (d > 2) { runner[i].d -= 2; d -= 2; }
				else { runner[i].d += 2; d += 2; }

				temp.first = x1 + dx[d]; temp.second = y1 + dy[d];
				// 술래없으면 이동
				if (temp.first == catcher.x && temp.second == catcher.y) { continue; }
				else { runner[i].x = temp.first; runner[i].y = temp.second; }
			}
			else { // 격자내에
				if (temp.first == catcher.x && temp.second == catcher.y) { continue; }
				else { runner[i].x = temp.first; runner[i].y = temp.second; }
			}
		}
	}
}

void Move_C() {
	check++;
	if (check != cnt) return;
	check = 0;	
	if (loop_count == 2 && cnt < n - 1) {
		loop_count = 1; 
		if (flag) { cnt++; catcher.d = (catcher.d + 1) % 4; }
		else { 
			cnt--; 
			if (catcher.d == 0) { catcher.d = 3; } 
			else { catcher.d--; }
		}
	}
	else if (loop_count == 3 && cnt == n - 1) {
		loop_count = 1;
		cnt--; 
		if (catcher.d == 0) { catcher.d = 3; }
		else { catcher.d--; }
	}
	else {
		loop_count++;
		if (flag) { catcher.d = (catcher.d + 1) % 4; }
		else {
			if (catcher.d == 0) { catcher.d = 3; }
			else { catcher.d--; }
		}
	}
}

void Catch() {
	int x1 = catcher.x; int y1 = catcher.y;
	int x2 = x1 + tx[catcher.d]; int y2 = y1 + ty[catcher.d];
	int x3 = x2 + tx[catcher.d]; int y3 = y2 + ty[catcher.d];
	bool check1 = false;
	bool check2 = false;
	bool check3 = false;
	if (x2 <= 0 || x2 > n || y2 <= 0 || y2 > n) check2 = true; // 주의
	if (x3 <= 0 || x3 > n || y3 <= 0 || y3 > n) check3 = true;

	for (int i = 0; i < h; i++) {
		if(!check1) check1 = (tree[i].first == x1) && (tree[i].second == y1);
		if (!check2) check2 = (tree[i].first == x2) && (tree[i].second == y2);
		if (!check3) check3 = (tree[i].first == x3) && (tree[i].second == y3);
	}
	
	int ans = 0;
	for (int i = 0; i < idx; i++) {
		bool check4 = (runner[i].x == x1) && (runner[i].y == y1) && !check1;
		bool check5 = (runner[i].x == x2) && (runner[i].y == y2) && !check2;
		bool check6 = (runner[i].x == x3) && (runner[i].y == y3) && !check3;
		if (check4 || check5 || check6) {
			runner[i] = { -1,-1,-1 };
			ans++;
		}
	}
	score += (term * ans);

	int tempidx = 0;
	set temp[10001];
	for (int i = 0; i < idx; i++) {
		if (runner[i].d != -1) {
			temp[tempidx++] = runner[i];
			runner[i] = { 0,0,0 };
		}
	}
	for (int i = 0; i < tempidx; i++) {
		runner[i] = temp[i];
		idx = tempidx;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	while (k--) {
		term++;
		//도망자 이동
		Move_R();
		//술래이동
		catcher.x += tx[catcher.d]; catcher.y += ty[catcher.d];
		if (catcher.x == 1 && catcher.y == 1 && flag) {
			loop_count = 1;
			flag = false;
			catcher.d += 2;
			check = 0; 
		}
		else if (catcher.x == (n / 2) + 1 && catcher.y == (n / 2) + 1 && !flag) { // 조건 주의
			loop_count = 1;
			flag = true;
			catcher.d -= 2;
			check = 0;
		}
		else { Move_C(); }
		//도망자 잡기
		Catch();
	}
	cout << score << "\n";
}