#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
pair<int, int> line[501];
int lis[501];
int len;

// ���� ����..�̤� �� LIS�� ���� ���ߴ� �� ���� ���鼭 �ٽ� ����!
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	// �ð����⵵ 500*500
	int MAX = 0;
	for (int i = 0; i < N; i++) { // 1���� �����ϸ� �翬�� ��������! �ڿ� 0���� Ȯ���ϴµ��ФФ�
		cin >> line[i].first >> line[i].second;
	}
	sort(line, line + N);
	// sort + ���� ���� !!
	int answer = 0;
	for (int i = 0; i < N; i++) {
		auto lower = lower_bound(lis, lis + len, line[i].second);
		if (*lower == 0) len++;
		*lower = line[i].second;
	}
	
	cout << N - len << "\n";
}