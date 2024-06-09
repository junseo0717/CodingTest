#include<iostream>
#define MOD 1000000000
using namespace std;
int N;
int dp[101][11][1024];
//bool check[11];
typedef long long ll;

int DP(int depth, int past, int visit) { // 원래 check 배열 활용했었음?
	if (depth == N) {
		/*for (int i = 0; i <= 9; i++) { 
			if (!check[i]) {
				return 0;
			}
		}*/
		if (visit == ((1 << 10) - 1)) {
			return 1;
		}
		else return 0;
	}
	//check[past] = true;

	int& ret = dp[depth][past][visit];
	if (ret) return ret;

	if (past > 0) {
		ret += DP(depth + 1, past - 1, visit | (1 << (past - 1)));
	}
	if (past < 9) {
		ret += DP(depth + 1, past + 1, visit | (1 << (past + 1)));
	}
	
	//check[past] = false;
	ret = ret % MOD;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	int ans = 0;

	for (int i = 1; i <= 9; i++) {
		ans += DP(1, i, 1 << i);
		ans = ans % MOD;
	}
	cout << ans << "\n";
}
