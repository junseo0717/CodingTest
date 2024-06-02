#include<iostream>
#include<vector>
#include<algorithm>
#define INF 10000000
using namespace std;
int N, K, answer;
int cnt[104];
int num[104];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < K; i++) cin >> num[i];

	for (int i = 0; i < K; i++) {
		if (!cnt[num[i]]) { 
			if (ans.size() == N) {
				int Idx = 0, pos;
				for (int _a : ans) {
					int temp = INF; 
					for (int j = i + 1; j < K; j++) {
						if (_a == num[j]) {
							temp = j; break;
						}
					}
					if (Idx < temp) {
						Idx = temp;
						pos = _a;
					}
				}
				cnt[pos] = 0; 
				answer++;
				// 특정값을 가진 것 제거
				ans.erase(find(ans.begin(), ans.end(), pos));
			}
			ans.push_back(num[i]); 
			cnt[num[i]] = 1;
		}
	}
	cout << answer << "\n";
}