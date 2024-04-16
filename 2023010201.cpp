#include<iostream>
#include<cmath>
#define MAX 10000
using namespace std;
struct set
{
	int x, y;
};

int N, M, K;
int strong[11][11];
set people[11];
set out;
int sum = 0;

void Rotate(int sx, int sy, int MIN) {
	int temp[11][11];
	int bx = sx + MIN - 1;
	int by = sy + MIN - 1;
	int size = sy - sx;
	int out_x = 0; int out_y = 0;
	for (int i = sy; i <= by; i++) {
		for (int j = sx; j <= bx; j++) {
			/* 시계방향 90도 돌리는 것 암기 ㅜㅜ*/
			if (strong[i][j] > 0) temp[j + size][MIN - i + sx + sy - 1] = strong[i][j] - 1;
			else temp[j + size][MIN - i + sx + sy - 1] = 0;
		}
	}
	for (int i = sy; i <= by; i++) {
		for (int j = sx; j <= bx; j++) {
			strong[i][j] = temp[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		if (people[i].x >= sx && people[i].x <= bx && people[i].y >= sy && people[i].y <= by) {
			int people_x = 0; int people_y = 0;
			people_x = MIN + sx + sy - 1 - people[i].y; people_y = people[i].x + size;
			people[i].x = people_x; people[i].y = people_y;
		}
	}
	out_x = MIN + sx + sy - 1 - out.y; out_y = out.x + size;
	out.x = out_x; out.y = out_y;
}

void Rect() {
	int MIN = MAX; int psx = 0; int psy = 0;
	for (int i = 0; i < M; i++) {
		int x = people[i].x; int y = people[i].y;
		if (x == 0) continue;

		int w = max((abs(x - out.x) + 1) , (abs(y - out.y) + 1)); // 정사각형 한변의 길이
		int sx = max(x, out.x); int sy = max(y, out.y);
		// 문제 /**/
		if (sx <= w) { sx = 1; }
		else { sx -= w; sx++; }
		if (sy <= w) { sy = 1; }
		else { sy -= w; sy++; }

		if (MIN > w) {
			MIN = w; psx = sx; psy = sy;
		}
		else if (MIN == w) {
			if (psy > sy) {
				MIN = w; psx = sx; psy = sy;
			}
			else if (psy == sy) {
				if (psx > sx) {
					MIN = w; psx = sx; psy = sy;
				}
			}
		}
	}
	Rotate(psx, psy, MIN);
}

void Move() {
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	for (int i = 0; i < M; i++) {
		int px = people[i].x; int py = people[i].y; 
		if (px == 0) continue;
		int pd = abs(px - out.x) + abs(py - out.y);
		for (int k = 0; k < 4; k++) {
			int x = px + dx[k]; int y = py + dy[k];
			int d = abs(x - out.x) + abs(y - out.y);
			if (x < 1 || y < 1 || y > N || x > N || pd <= d || strong[y][x] != 0) continue;
			if (d == 0) { people[i] = { 0,0 }; sum++; break; } // 탈출
			else { people[i] = { x, y }; sum++; break; } // 이동
		}
	}
}
bool Check() {
	for (int i = 0; i < M; i++) {
		if (people[i].x != 0) return false;
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> strong[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		people[i] = { b, a};
	}
	cin >> out.y >> out.x;

	for (int i = 0; i < K; i++) {
		if (Check()) break;
		Move();
		if (Check()) break;
		Rect();
	}
	
	
	cout << sum << "\n";
	cout << out.y << " " << out.x << "\n";
}