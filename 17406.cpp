#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct set {
	int r, c, s;
};

int N, M, K;
int Arr[54][54];
int arr[54][54];
int temp[54][54];
set Cal[10];
vector<int> Idx;
const int INF = 9876543;
int ans = INF;

void Rotate(pair<int,int> s, pair<int,int> e) {
	pair<int, int> S; pair<int, int> E;
	S = s; E = e;

	while (s.first < e.first) {
		for (int i = s.second; i < e.second; i++) temp[s.first][i + 1] = Arr[s.first][i];
		for (int i = s.first; i < e.first; i++) temp[i + 1][e.second] = Arr[i][e.second];
		for (int i = e.second; i > s.second; i--) temp[e.first][i - 1] = Arr[e.first][i];
		for (int i = e.first; i > s.first; i--) temp[i - 1][s.second] = Arr[i][s.second];
		s.first++; s.second++; e.first--; e.second--;
	}
	if (s.first == e.first) temp[s.first][s.second] = Arr[s.first][s.second];

	for (int i = 0; i < N; i++) { // y
		for (int j = 0; j < M; j++) { // x
			if (i >= S.first && i <= E.first && j >= S.second && j <= E.second) continue;
			temp[i][j] = Arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) { // y
		for (int j = 0; j < M; j++) { // x
			Arr[i][j] = temp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Arr[i][j];
			arr[i][j] = Arr[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> Cal[i].r >> Cal[i].c >> Cal[i].s;
		Idx.push_back(i);
	}

	do {
		for (int i : Idx) {
			set val = Cal[i];
			Rotate({ val.r - val.s - 1, val.c - val.s - 1 }, { val.r + val.s - 1, val.c + val.s - 1 });
		}
		int MIN = INF;
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += temp[i][j];
			}
			MIN = min(MIN, sum);
		}
		ans = min(ans, MIN);
		for (int i = 0; i < N; i++) { // y
			for (int j = 0; j < M; j++) { // x
				Arr[i][j] = arr[i][j];
			}
		}

	} while (next_permutation(Idx.begin(), Idx.end()));

	cout << ans << "\n";
}