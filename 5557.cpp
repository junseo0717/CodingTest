#include<iostream>
using namespace std;
int N;
typedef long long ll; // ÁÖÀÇ point
ll ans[104][21];
ll num[100];

ll DP(int s, int p) {
	if (s == N - 2) {
		if (p == num[N - 1]) return 1; 
		return 0;
	}

	ll &ret = ans[s][p];
	if (ret) return ret;

	if (p - num[s + 1] <= 20 && p - num[s + 1] >= 0) ret += DP(s + 1, p - num[s + 1]);
	if (p + num[s + 1] <= 20 && p + num[s + 1] >= 0) ret += DP(s + 1, p + num[s + 1]);
	
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cout << DP(0, num[0]) << "\n"; 
}