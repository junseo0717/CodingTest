#include<iostream>
using namespace std;
int N;
int temp[4000001];
int p_num[4000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 2; i <= N; i++) temp[i] = i;
	for (int i = 2; i <= N; i++) {
		if (!temp[i]) continue;
		for (int j = i + i; j <= N; j += i) temp[j] = 0;
	}

	int m = 0; 
	for (int i = 0; i <= N; i++) {
		if (!temp[i]) { m++; }
		else { p_num[i - m] = temp[i]; }
	}

	int s = 0; int e = 0; int ans = 0; int ans_check = 0;
	while (1) {
		if (ans_check >= N) ans_check -= p_num[s++]; // ǥ�� ���
		else if (e == N - m + 1) break; // ���ߴ� ����..
		else if(ans_check < N) ans_check += p_num[e++]; 
		
		// �̶� ������ �� �����ְ� �Ѿ! else if�� �ϸ� �ð��ʰ��� ����
		// why? ���⼭ ��� �Ѿ�� �ʰ� ��.. s�� e�� �������־�� ��..!
		if (ans_check == N) {
			ans++;
		}
	}
	cout << ans << "\n";
}