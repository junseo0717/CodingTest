#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#define INF 1e9 + 4
using namespace std;
typedef long long ll;
ll N;
ll lis[1000004];
pair<int,int> ans[1000004];
int num, len;
stack<int> stk;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	fill(lis, lis + 1000004, INF);
	for (int i = 0; i < N; i++) {
		cin >> num;
		auto lower = lower_bound(lis, lis + len, num); 
		if (*lower == INF) len++;					   
		*lower = num;
		int pos = (int)(lower_bound(lis, lis + len, num) - lis);
		ans[i].first = pos; ans[i].second = num; 
	}
	cout << len << "\n";
	for (int i = N - 1; i >= 0; i--) {
		if (ans[i].first == len - 1) {
			stk.push(ans[i].second); 
			len--;
		}
	}
	while (stk.size()) {
		cout << stk.top() << " "; stk.pop();
	}
}