#include<iostream>
using namespace std;
int N;
int num[100001];
int cnt[100001]; // 중복되는 요소 체크
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	int s = 0; int e = 0;
	while (e < N) {
		if (!cnt[num[e]]) {
			cnt[num[e]]++;
			e++;
		}
		else {
			ans += (e - s); // num[e]를 포함하는 집합을 미리 더한 것
			cnt[num[s]]--; // num[s]이다
			s++;
		}
	}
	ans += (long long)(e - s) * (e - s + 1) / 2;
	cout << ans << "\n";
}