#include<iostream>
#include<algorithm>
#define MAX 10004
using namespace std;
typedef long long ll;
ll N, M;
ll Time[10001];
//pair<int, int> Time[10001];
//
//bool compare(pair<int, int> a, pair<int, int> b) {
//	if (a.first == b.first) return a.second > b.second;
//	return a.first > b.first;
//}
bool Check(ll m) {
	ll temp = M;
	for (ll i = 0; i < M; i++) temp += m / Time[i]; 
	return temp >= N;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> Time[i];
	if (N <= M) { cout << N << "\n"; return 0; }
	//int MIN = 1e9;
	//for (int i = 0; i < M; i++) {
	//	cin >> Time[i].first;
	//	MIN = min(MIN, Time[i].first);
	//	Time[i].second = i + 1;
	//}
	//// 특정시간이 Mid일때 N명이상을 태울 수 있는 지 확인!!
	//for (int i = 0; i < M; i++) Time[i].first -= MIN;
	//sort(Time, Time + M, compare);

	ll s = 1; ll e = 1e14; ll answer = 0;
	while (s <= e) {
		ll m = (s + e) / 2;
		if (Check(m)) { answer = m; e = m - 1; }
		else { s = m + 1; }
	}

	ll temp = M;
	for (ll i = 0; i < M; i++) temp += ((answer - 1) / Time[i]); // 마지막 사람이 타기 전에 자른 덩어리

	for (ll i = 0; i < M; i++) {
		if (answer % Time[i] == 0) temp++;
		if (temp == N) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
}