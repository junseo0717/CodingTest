#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, S;
int num[40];

void MITM(int s, int e, vector<long long>& v, long long sum) {
	if (s >= e) {
		v.push_back(sum); 
		return;
	}

	MITM(s + 1, e, v, sum + num[s]);
	MITM(s + 1, e, v, sum);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	vector<long long> v1;
	vector<long long> v2; 
	//// sum을 저장하는 vector, 최대 1,000,000을 계속 더하므로 위험하다는 것 인지
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	MITM(0, N / 2, v1, 0);
	MITM(N / 2, N, v2, 0);
	sort(v2.begin(), v2.end());

	//point
	long long answer = 0; // 최대 2^40개..
	for (int i = 0; i < v1.size(); i++) {
		int find = S - v1[i];
		int dIdx = (int)(lower_bound(v2.begin(), v2.end(), find) - v2.begin());
		if (find == v2[dIdx]) { 
			// 정답? S - v1[x] - v2[x] = 0이므로 lower_bound에서 계산
			int uIdx = upper_bound(v2.begin(), v2.end(), find) - v2.begin();
			answer += uIdx - dIdx; // 정답이 여러개 되는 Idx 계산
		}
	}
	
	if (S == 0) answer--; 
	cout << answer << "\n";
}