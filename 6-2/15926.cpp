#include<iostream>
#include<stack>
using namespace std;
bool check[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	int n; cin >> n;
	string str;
	cin >> str;

	stack<int> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			st.push(i);
		}
		else {
			if (!st.empty()) {
				check[st.top()] = true; // point 쌍으로 더하기위해서 index stack에 저장
				check[i] = true;
				st.pop();
			}
		}
		
	}
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if (check[i]) cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);
	cout << ans << "\n";
}