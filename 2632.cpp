#include<iostream>
#include<algorithm>
using namespace std;
int K, A, B, answer = 0;
int sum_a[2004];
int sum_b[2004];
int a[1004];
int b[1004];
int Suma[2000001];
int Sumb[2000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);

	// 구간합 하기위한 build up!!
	cin >> K >> A >> B;
	for (int i = 1; i <= A; i++) {
		cin >> a[i];
		sum_a[i] = sum_a[i - 1] + a[i];
	}
	for (int i = A + 1; i <= 2 * A; i++) sum_a[i] = sum_a[i - 1] + a[i - A];
	for (int i = 1; i <= B; i++) {
		cin >> b[i];
		sum_b[i] = sum_b[i - 1] + b[i];
	}
	for (int i = B + 1; i <= 2 * B; i++) sum_b[i] = sum_b[i - 1] + b[i - B];
	
	// 횟수 check
	for (int i = 1; i <= A; i++) { // start
		for (int j = i; j <= A + i - 1; j++) { 
			int sum = sum_a[j] - sum_a[j - i]; // 합 A - 1의 interval을 가지도록 설정
			Suma[sum]++;
			if (i == A) break; // 주의1. A이면 stop!
		}
	}
	for (int i = 1; i <= B; i++) { // start
		for (int j = i; j <= B + i - 1; j++) { //  A + i - 1, j = interval
			int sum = sum_b[j] - sum_b[j - i];
			Sumb[sum]++;
			if (i == B) break; //
		}
	}
	answer += Suma[K] + Sumb[K];
	for (int i = 0; i < K; i++) answer += (Suma[i] * Sumb[K - i]);
	cout << answer << "\n";
}