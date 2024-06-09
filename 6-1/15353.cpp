#include<iostream>
using namespace std;
string A, B;
string answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> A >> B;
	int aidx = A.size() - 1; 
	int bidx = B.size() - 1;

	int temp = 0;
	while(aidx >= 0 || bidx >= 0 || temp) {
		if(aidx >= 0) temp += A[aidx] - '0';
		if(bidx >= 0) temp += B[bidx] - '0';
		
		answer += (temp % 10) + '0'; 
		temp /= 10;
		aidx--; bidx--; 
	}

	string ans;
	for (int i = answer.size(); i >= 0; i--) ans += answer[i];
 	cout << ans << "\n";
}