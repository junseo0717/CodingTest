#include<iostream>
using namespace std;
int T, A, S, B;
int arr[201];
int dp[201][4001];

int main() {
	cin >> T >> A >> S >> B;
	for (int i = 0; i < A; i++) {
		int a; cin >> a;
		arr[a]++;
	}
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= arr[i]; j++) dp[i][j] += 1;

		for (int j = 1; j <= A; j++) {
			dp[i][j] += dp[i - 1][j];
			for (int k = 1; k <= arr[i]; k++) {
				if (j - k > 0) {
					dp[i][j] += dp[i - 1][j - k];
					dp[i][j] %= 1000000;
					// ¡÷¿«
				}
			}
		}
	}
	int ans = 0;
	for (int i = S; i <= B; i++) {
		ans += dp[T][i];
		ans %= 1000000;
	}
	cout << ans << "\n";
}