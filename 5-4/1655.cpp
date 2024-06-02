#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<>> minheap;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int n; cin >> n;
		if (i % 2) {
			maxheap.push(n);
		}
		else {
			minheap.push(n);
		}
		if (minheap.empty()) {
			cout << maxheap.top() << "\n";
			continue;
		}
		if (minheap.top() < maxheap.top()) { // maxheap의 가장 큰값이 minheap의 가장 작은값보다 크면
			minheap.push(maxheap.top());
			maxheap.push(minheap.top());
			minheap.pop();
			maxheap.pop();
		}
		cout << maxheap.top() << "\n";
	}
}