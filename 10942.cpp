// 1 : �Ӹ�����̴� 0 : �Ӹ������ �ƴϴ�
//�Ӹ����(Palindrome)�� ȸ���ڶ�� �ϸ� ������ ������ 
// �ڷ� ������ ���� ������ �Ǵ� ���ڳ� ������ ���Ѵ�. 
#include<iostream>
using namespace std;
int N, M;
int num[2000];
bool dp[2000][2000];
//bool Palindrome(int s, int e) {
//	int size = e - s + 1;
//	if (size == 1) return true;
//	for (int i = s; i <= s + size / 2; i++) {
//		if (num[i] != num[e - i]) {
//			return false;
//		}
//	}
//	return true;
//}


int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> M;
	for (int i = 0; i < N; i++) {
		dp[i][i] = 1;
		if (num[i] == num[i + 1]) dp[i][i + 1] = 1; // �ΰ� index�� ���̰� 1
	}

	for (int i = 2; i < N; i++) { // size ��
		for (int j = 0; j < N - i; j++) {
			if (dp[j + 1][j + i - 1] && num[j] == num[j + i]) dp[j][i + j] = 1;
		}
	}

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[s - 1][e - 1] << "\n";
	}
}