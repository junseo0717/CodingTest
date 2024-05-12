#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
pair<int, int> line[501];
int lis[501];
int len;

// 완전 정리..ㅜㅜ 왜 LIS를 생각 못했는 지 강의 보면서 다시 정리!
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	// 시간복잡도 500*500
	int MAX = 0;
	for (int i = 0; i < N; i++) { // 1부터 시작하면 당연히 오류나지! 뒤에 0부터 확인하는데ㅠㅠㅜ
		cin >> line[i].first >> line[i].second;
	}
	sort(line, line + N);
	// sort + 최장 수열 !!
	int answer = 0;
	for (int i = 0; i < N; i++) {
		auto lower = lower_bound(lis, lis + len, line[i].second);
		if (*lower == 0) len++;
		*lower = line[i].second;
	}
	
	cout << N - len << "\n";
}