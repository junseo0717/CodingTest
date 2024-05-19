#include<iostream>
#include<algorithm>
using namespace std;
int N;
pair<int,int> line[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> line[i].first >> line[i].second;
	sort(line, line + N);

	long long answer = 0;
	int pre = line[0].first; // 이전 시작점
	int MAX = line[0].second; // 이전 끝점
	//이와 같은 상황에 바로 조건 바꿀 수 있어야 함 시작점 기준으로 sort

	for (int i = 1; i < N; i++) {
		int s = line[i].first; // 현재 시작점
		int e = line[i].second; // 현재 끝점
		if (MAX >= s && MAX <= e) { 
			MAX = e; 
		}
		else if(MAX < s) { 
			answer += MAX - pre;
			pre = line[i].first;
			MAX = line[i].second;
		}
	}
	answer += MAX - pre;
	cout << answer << "\n";
}