#include <iostream>
using namespace std;
int N, K;
int dp[1001][1001];

int Cal(int n, int r) {
	if (r == 0 || r == n) return 1;

	int& ret = dp[n][r];
	if (!ret) {
		ret = Cal(n - 1, r - 1) + Cal(n - 1, r);
		ret = dp[n][r] % 10007;
	}

	return ret;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= min(K, i); j++) {
			// 0 ~ i 또는 0 ~ k 까지 중 작은 것을 택함 불필요한 것을 구하지 않기 위해
			if (i == j || j == 0) { dp[i][j] = 1; }
			else {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				dp[i][j] = dp[i][j] % 10007;
			}
		}
	}
	cout << dp[N][K] << "\n";
	//cout << Cal(N, K) << "\n";
}