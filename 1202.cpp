#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N, K;
pair<int, int> bag[300001]; int C[300001];
priority_queue<long long> que;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> bag[i].first >> bag[i].second;
	for (int i = 0; i < K; i++) cin >> C[i];
	sort(bag, bag + N);
	sort(C, C + K);

	long long answer = 0;
	int Idx = 0;
	for (int i = 0; i < K; i++) {
		while (bag[Idx].first <= C[i] && Idx < N) que.push(bag[Idx++].second); // bag[Idx].first <= C[i] && !check[Idx] && Idx < N
		if (que.size()) { // 
			answer += que.top();
			que.pop();
		}
	}
	cout << answer << "\n";
}