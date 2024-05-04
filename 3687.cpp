#include<iostream>
#include<string>
#include<algorithm>
//#define MAX 999999999999999999
//#define MIN -999999999999999999
using namespace std;
int T;
int num[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }; // 성냥개비 사용 개수
// <최대값>
//long long dp[51][101]; 주의1. 50자리 수를 숫자로 담을 수 있는 배열이 없으므로 string을 사용해야함!
// string의 자리수 -> string의 크기(아스키코드) 비교 순으로 찾아야 하는데 
// 최대한 적은 성냥개비를 써서 자리수를 늘리기 위해서 가장 적게 사용하는 수인 7과 1에 집중해보자
// 무조건 자리수가 커야하기 때문에 1을 많이 사용하도록 하는데 홀수가 나온다면? 7을 사용해서 71111 자리수를 늘리도록 해보자
// 711을 써야할까 117을 써야할까? 당연히 711을 써야한다

//<최소값>
// 사이즈가 무조건 크다고 좋은것이 아님 명제가 없음 -> 그리디로 모든 경우의 수를 따져봐야 한다, 경우의 수가 너무 많으므로 DP활용
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

	if (n & 1) { ret += '7'; n -= 3; } // 홀수
	//짝수
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
	return ret; // 써야지!
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
		fill(dp, dp + 104, "111111111111111111111111111111111111111111111111119"); // 가장 큰 수! "1" * 49 + "9"
		fill(dp2, dp2 + 104, "111111111111111111111111111111111111111111111111119"); // 가장 큰 수! "1" * 49 + "9"
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