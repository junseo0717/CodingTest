#include<iostream>
#define INF 1000000007
using namespace std;
typedef long long ll;
ll N, K;

ll fact(int a, int b) {
	ll ret = 1; 
	for (int i = a; i <= b; i++) ret = ret * i % INF;
	return ret;
}

ll Divide(int a, int b) {
	if (b == 1) return a; 
	ll half = Divide(a, b / 2);
	if (b % 2) { return half * half % INF * a % INF; }
	else { return half * half % INF; }
}


int main() {
	cin >> N >> K;
	int ans = fact(N - K + 1, N) * Divide(fact(1, K), INF - 2) % INF; 
	cout << ans << "\n";
}