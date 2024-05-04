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
	while (e - s > 0) // e == s �̸� �ݺ� ����
	{
		m = (e + s) / 2; // �߰���ġ ���
		if (v[m] <= k) s = m + 1; // ã�����ϴ� ������ ���� ���
		else e = m; // ã���� �ϴ� ������ ū ���
	}
	return e;
}
//int s, int e : MITM �˰��� ����
// upper bound Ȱ�� -> sort..! -> vector<int> &v, �־��ֱ�
void DP(int s, int e, vector<int> &v, int sum) {
	if (sum > C) return;
	if (s > e) {
		v.push_back(sum); // �̰��� ��?, ������ �� ������ sum�� ���� ��� ���غ��� ��
		return;
	}

	//if (sum <= C) v.push_back(sum); -> �˰��� �߸������� ��?
	
	//����Ǽ� �뷮�� ���ϰų� �ƴϰų�
	DP(s + 1, e, v, sum + num[s]); // ���ϰų� 
	DP(s + 1, e, v, sum); // ������ �ʰų�
	return; // ���� !! ������ ������ ����
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
		// �˰��� �߸� ������ 2
		if(C - x >= 0) answer += solve(v2, C - x);
		// �� v1���� ����? v2���� ���� �ȵ�?
		/*if (C - x >= 0) 
			answer += (int)(upper_bound(v2.begin(), v2.end(), C - x) - v2.begin());*/
		
	}
	cout << answer << "\n";
}

// Upper bound: upper bound�� ã���� �ϴ� ������ ū ���� ó������ ��Ÿ���� ��ġ�Դϴ�.
// Lower bound: ã���� �ϴ� �� �̻��� ó�� ��Ÿ���� ��ġ, ���Ұ� ������ �ִ��� �������
// default
// => �̺�Ž�� ���� Ȱ��