#include<iostream>
using namespace std;
int n, cus[1000001], LDR, MBR;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> cus[i];
	cin >> LDR >> MBR;
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = cus[i];
		temp -= LDR;
		ans++;
		if (temp <= 0) continue;
		if (temp % MBR) ans++;
		temp /= MBR;
		ans += temp;
	}
	cout << ans << "\n";
}