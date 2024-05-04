#include<iostream>
#include<string>
#include<algorithm>
//#define MAX 999999999999999999
//#define MIN -999999999999999999
using namespace std;
int T;
int num[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }; // ���ɰ��� ��� ����
// <�ִ밪>
//long long dp[51][101]; ����1. 50�ڸ� ���� ���ڷ� ���� �� �ִ� �迭�� �����Ƿ� string�� ����ؾ���!
// string�� �ڸ��� -> string�� ũ��(�ƽ�Ű�ڵ�) �� ������ ã�ƾ� �ϴµ� 
// �ִ��� ���� ���ɰ��� �Ἥ �ڸ����� �ø��� ���ؼ� ���� ���� ����ϴ� ���� 7�� 1�� �����غ���
// ������ �ڸ����� Ŀ���ϱ� ������ 1�� ���� ����ϵ��� �ϴµ� Ȧ���� ���´ٸ�? 7�� ����ؼ� 71111 �ڸ����� �ø����� �غ���
// 711�� ����ұ� 117�� ����ұ�? �翬�� 711�� ����Ѵ�

//<�ּҰ�>
// ����� ������ ũ�ٰ� �������� �ƴ� ������ ���� -> �׸���� ��� ����� ���� �������� �Ѵ�, ����� ���� �ʹ� �����Ƿ� DPȰ��
string dp[104];  // top-down
string dp2[104]; // bottom-up
int N;

//long long s_MIN(int d, int use) {
//	if (use == 0) return 0;
//	if (use < 0 || use == 1) return MAX;
//	long long& ret = dp[d][use];
//	if (ret) return ret;
//
//	ret = MAX;
//
//	for (int i = 0; i < 10; i++) {
//		if (d == 0 && i == 0) continue;
//		long long temp = pow(10, d) * i;
//		ret = min(ret, s_MIN(d + 1, use - num[i]) + temp);
//	}
//	return ret;
//}
//long long s_MAX(int d, int use) {
//	if (use == 0) return 0;
//	if (use < 0 || use == 1) return MIN;
//	
//	long long& ret = dp[d][use];
//	if (ret) return ret;
//
//	ret = MIN;
//
//	for (int i = 0; i < 10; i++) {
//		if (d == 0 && i == 0) continue;
//		
//		long long temp = pow(10, d) * i;
//		ret = max(ret, s_MAX(d + 1, use - num[i]) + temp);
//	
//	}
//	return ret;
//}

string findMAX(int n) {
	string ret = "";

	if (n & 1) { ret += '7'; n -= 3; } // Ȧ��
	//¦��
	while (n) {
		ret += "1";
		n-= 2;
	}

	return ret;
}

string get_MIN(string a, string b) {
	if (a.size() == b.size()) return (a < b) ? a : b;
	if (a.size() < b.size()) return a;
	return b;
}

string findMIN(int n) {
	if (n == 0) return ""; 
	string& ret = dp[n];
	if (ret != "111111111111111111111111111111111111111111111111119") return ret;

	for (int i = 0; i < 10; i++) {
		if (i == 0 && n == N) continue; 
		if (n - num[i] < 0) continue;

		ret = get_MIN(ret,  to_string(i) + findMIN(n - num[i])); 
	}
	return ret; // �����!
}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> T;
	while (T > 0) {
		T--;
		cin >> N;
		/*memset(dp, 0, sizeof(dp));
		cout << s_MIN(0, n) << " ";
		memset(dp, 0, sizeof(dp));
		cout << s_MAX(0, n) << "\n";*/
		fill(dp, dp + 104, "111111111111111111111111111111111111111111111111119"); // ���� ū ��! "1" * 49 + "9"
		fill(dp2, dp2 + 104, "111111111111111111111111111111111111111111111111119"); // ���� ū ��! "1" * 49 + "9"
		dp2[0] = "";
		for (int i = 2; i < 104; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i - num[j] < 0) continue;
				if (j == 0 && dp2[i - num[j]] == "")continue;
				dp2[i] = get_MIN(dp2[i], dp2[i - num[j]] + to_string(j));
			}

		}
		cout << dp2[N] << " " << findMAX(N) << "\n";
	}
}