#include<iostream>
using namespace std;
int N, K;
int Walk[101][2];
int Circle[101][2]; // 0: 시간, 1: 돈
int dp[101][100001];

int DP(int d, int sum_t) {
	if (d >= N) return 0; 
	// 메모이제이션
	int& ret = dp[d][sum_t];
	if (ret) return ret;
	// 로직
	ret = -987654321; 
	if(sum_t - Walk[d][0] >= 0)  
		ret = max(ret, DP(d + 1, sum_t - Walk[d][0]) + Walk[d][1]);
	if (sum_t - Circle[d][0] >= 0) ret = max(ret, DP(d + 1, sum_t - Circle[d][0]) + Circle[d][1]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> Walk[i][0] >> Walk[i][1] >> Circle[i][0] >> Circle[i][1];
	}
	
	cout << DP(0, K) << "\n";
}