#include<iostream>
using namespace std;
long long X, Y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long answer = -1;

	cin >> X >> Y;
	long long Z = Y * 100 / X;
	long long s = 1; long long e = 1e9;

	// 선형탐색으로 하나하나 찾는 다면 오래 걸릴 것 10의 9승만큼 걸리게됨
	while (s <= e) {
		long long m = (s + e) / 2;
		if ((Y + m) * 100 / (X + m) > Z) {
			answer = m;
			e = m - 1;
		} else s = m + 1;
	}
	//if (X == Y) answer = -1;
	//while (1) {
	//	Y++; X++;
	//	long long temp = Y / X;
	//	z = temp * 100;
	//	if (z > Z) break;
	//	answer++;
	//}
	
	cout << answer << "\n"; 
}