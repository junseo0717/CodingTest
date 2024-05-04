//#include<iostream>
//#include<vector>
//
//using namespace std;
//int N;
//int A[1001], cnt[1001]; // cnt[idx] : idx에서 count한 최장수열 값 
//
//int answer = 0; int ans_Idx = 0;
//vector<int> ans[1001];
//
//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> A[i];
//	}
//
//	// 팬윅트리 알고리즘
//	for (int i = 0; i < N; i++) {
//		int MAX = 0; int Idx = -1;
//		for (int j = 0; j < i; j++) {
//			if (A[j] < A[i] && MAX < cnt[j]) {
//				MAX = cnt[j];
//				Idx = j;
//			}
//		}
//		for (int j = 0; j < ans[Idx].size(); j++) {
//			ans[i].push_back(ans[Idx][j]);
//		}
//		ans[i].push_back(A[i]);
//		cnt[i] = MAX + 1; // 자기자신 더해줌
//		if (answer < cnt[i]) {
//			answer = cnt[i];
//			ans_Idx = i;
//		}
//	}
//	cout << answer << "\n";
//	for (int i = 0; i < ans[ans_Idx].size(); i++) {
//		cout << ans[ans_Idx][i] << " ";
//	}
//}

#include<iostream>
#include<algorithm>
using namespace std;
int N, len, num;
long long lis[1001]; // index를 나타내는 것
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		auto lower = lower_bound(lis, lis + len, num);
		if (*lower == 0) len++;
		*lower = num;
	}
	cout << len << "\n";
	for (int i = 0; i < len; i++) cout << lis[i] << " ";
}