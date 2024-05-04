#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int N, C;
int num[30];
vector<int> v1;
vector<int> v2;

int solve(vector<int> &v, int k)
{
	int s = 0;
	int e = v.size();
	int m;
	while (e - s > 0) // e == s 이면 반복 종료
	{
		m = (e + s) / 2; // 중간위치 계산
		if (v[m] <= k) s = m + 1; // 찾고자하는 값보다 작은 경우
		else e = m; // 찾고자 하는 값보다 큰 경우
	}
	return e;
}
//int s, int e : MITM 알고리즘 구분
// upper bound 활용 -> sort..! -> vector<int> &v, 넣어주기
void DP(int s, int e, vector<int> &v, int sum) {
	if (sum > C) return;
	if (s > e) {
		v.push_back(sum); // 이거임 왜?, 끝까지 돈 상태의 sum의 값을 모두 구해보는 것
		return;
	}

	//if (sum <= C) v.push_back(sum); -> 알고리즘 잘못이해함 왜?
	
	//경우의수 용량에 더하거나 아니거나
	DP(s + 1, e, v, sum + num[s]); // 더하거나 
	DP(s + 1, e, v, sum); // 더하지 않거나
	return; // 주의 !! 없으면 컴파일 오류
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	int answer = 0;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	DP(0, N / 2 - 1, v1, 0);
	DP(N / 2, N - 1, v2, 0);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (auto x : v1) {
		// 알고리즘 잘못 이해함 2
		if(C - x >= 0) answer += solve(v2, C - x);
		// 왜 v1부터 시작? v2부터 보면 안돼?
		/*if (C - x >= 0) 
			answer += (int)(upper_bound(v2.begin(), v2.end(), C - x) - v2.begin());*/
		
	}
	cout << answer << "\n";
}

// Upper bound: upper bound는 찾고자 하는 값보다 큰 값이 처음으로 나타나는 위치입니다.
// Lower bound: 찾고자 하는 값 이상이 처음 나타나는 위치, 원소가 여러개 있더라도 상관없음
// default
// => 이분탐색 원리 활용