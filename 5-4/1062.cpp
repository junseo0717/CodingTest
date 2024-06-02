#include<iostream>
using namespace std;
int N, K;
string s;
int word[51];
int ans = 0;

int Answer(int mask) {
	int cnt = 0;
	for (int words : word) {
		if (words && (words & mask) == words) cnt++;
	}
	return cnt;
}
int go(int depth, int k, int mask) {
	if (k < 0) return 0;
	if (depth == 26) return Answer(mask);

	int ret = go(depth + 1, k - 1, mask | (1 << depth));
	int a = (int)('a' - 'a'); int n = (int)('n' - 'a');
	int t = (int)('t' - 'a');
	int i = (int)('i' - 'a');
	int c = (int)('c' - 'a');
	if (depth != a && depth != n && depth != t && depth != i && depth != c) {
		ret = max(ret, go(depth + 1, k, mask));
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) word[i] |= (int)(1 << (s[j] - 'a'));
	}
	cout << go(0, K, 0) << "\n";
}