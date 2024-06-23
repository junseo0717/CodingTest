#include<iostream>
using namespace std;
int N, M;
int dp[101][51];
int sum[101];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a;  cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	for (int j = 1; j <= M; j++) dp[0][j] = -8765432; 
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j == 1) dp[i][j] = max(dp[i][j], sum[i]); 
			for (int k = 2; k <= i; k++) { 
				dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + sum[i] - sum[k - 1]);
			}
		}
	}

	cout << dp[N][M] << "\n";
}