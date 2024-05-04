#include<iostream>
#include<algorithm>
using namespace std;
int N, M, C;
int J[24];
int dp[24][1 << 14][24]; 

int DP(int d, int j, int c) {
	if (d >= M) return 0; 

	int& ret = dp[d][j][c];
	if (ret) return ret;

	// ·ÎÁ÷ 
	ret = max(ret, DP(d + 1, j, C)); 
	for (int i = 0; i < N; i++) {
		bool isj = (1 << i) & j; 
		bool isc = (c - J[i]) >= 0;
		if (!isj && isc) ret = max(ret, DP(d, j | (1 << i), c - J[i]) + 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) {
		cin >> J[i];
	}

	cout << DP(0, 0, C) << "\n";
}