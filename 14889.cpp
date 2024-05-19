#include <iostream>
#include<vector>
#include<cmath>
#define INF 987654321;
using namespace std;
int N;
int S[20][20];

int go(vector<int>& s, vector<int>& e) {
	pair<int, int> temp;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			if (i == j) continue;
			temp.first += S[s[i]][s[j]]; 
			temp.second += S[e[i]][e[j]];
		}
	}
	return abs(temp.first - temp.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> S[i][j];
	}

	int cnt = 0; int ans = INF;
	for (int i = 0; i < (1 << N); i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			if ((i >> j) & 0x1 == 1) cnt++;
		}
		if (cnt != N / 2) continue;
		vector<int> S, L;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) S.push_back(j);
			else L.push_back(j);
		}
		ans = min(ans, go(S, L));
	}
	cout << ans << "\n";
}

