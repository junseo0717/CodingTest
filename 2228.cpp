#include<iostream>
#include<string.h>
using namespace std;
int N, M;
int answer = -97654321;
int num[101];
int dp[101][51];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> num[i];
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			DP(i, j, 1);
		}
	}
	
	cout << answer << "\n";
}
