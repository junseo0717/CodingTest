// �� �� �� ��� �� ���� ���� �Ҽ��� ������ Ȯ��
// ���� 5��
// �Է� : ��Ⱑ ����Ǵ� ���� �� ���ݿ��� A���� ������ Ȯ���� B���� ������ Ȯ��
// �� ���ݿ��� �� ���� ���� ���ƾ� �� ���� ��������
//if (0) { cout << "True" << "\n"; }
//else { cout << "False" << "\n"; }
#include <iostream>
#include<algorithm>
#include<string.h>
using namespace std;
bool P[20];
double A, B, dp[20][20][20]; // !!3�������� �ϴ� �� ����!! 

double DP(int d, int x, int y) {
	if (d == 18) return P[x] || P[y] ? 1.0 : 0.0; // ��� �� ���� ���� �Ҽ���? 1.0 else 0.0 => ���� ����
	double &ret = dp[d][x][y];
	if (ret != -1) return ret;
	ret = 0.0;
	ret += DP(d + 1, x + 1, y + 1) * A * B;
	ret += DP(d + 1, x + 1, y) * A * (1 - B);
	ret += DP(d + 1, x, y + 1) * (1 - A) * B;
	ret += DP(d + 1, x, y) * (1 - A) * (1 - B);
	return ret;
}

void prime() {
	fill(P + 2, P + 20, 1);
	for (int i = 2; i < 20; i++) {
		for (int j = i + i; j < 20; j += i) {
			P[j] = 0;
		}
	}
}

int main() {
	cin >> A >> B;
	A /= 100;
	B /= 100;
	prime();
	memset(dp, -1, sizeof(dp));
	cout << DP(0, 0, 0) << "\n";
}