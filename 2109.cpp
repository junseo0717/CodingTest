#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
int ans = 0;
pair<int, int> L[10001];
bool day[10001];
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순!!

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> L[i].second >> L[i].first;
	/*sort(L, L + n, greater<>());

	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = L[i].second; j > 0; j--) {
			if (!day[j]) {
				flag = true;
				day[j] = true;
				break;
			}
		}
		if(flag) ans += L[i].first;
	}
	cout << ans << "\n";*/

	sort(L, L + n);

	for (int i = 0; i < n; i++) {
		pq.push(L[i].second);
		if (pq.size() > L[i].first) pq.pop();
	}
	while (pq.size()) {
		ans += pq.top(); pq.pop();
	}
	cout << ans << "\n";
}