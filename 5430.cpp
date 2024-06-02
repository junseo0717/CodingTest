#include<iostream>
#include<queue>
using namespace std;
int T;
deque<int> num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		num.clear();
		bool flag = false;
		string p; cin >> p;
		int n; cin >> n;
		string arr; cin >> arr;
		
		int temp = 0;
		for (int i = 1; i < arr.size(); i++) {
			if (arr[i] == ']' || arr[i] == ',') {
				if (temp == 0) continue; // 빈칸일 경우 넘기기
				num.push_back(temp);
				temp = 0;
			}
			else {
				temp *= 10;
				temp += (int)(arr[i] - '0'); // 문제가 됨.. 당연히 더해야지
			}
		}

		int cnt = 0;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				cnt++;
			}
			else if(p[i] == 'D') {
				if (num.empty()) {
					cout << "error" << "\n";
					flag = true;
					break;
				}
				if (cnt % 2) { num.pop_back(); }
				else if(!((cnt % 2))) { num.pop_front(); }
			}
		}
		if (flag) continue;

		if (cnt % 2) {
			// 거꾸로 출력
			cout << "[";
			for (int i = num.size() - 1; i >= 0; i--) {
				cout << num[i];
				if (i == 0) break;
				cout << ",";
			}
			cout << "]" << "\n";
		}
		else {
			cout << "[";
			for (int i = 0; i < num.size(); i++) {
				cout << num[i];
				if (i == num.size() - 1) break;
				cout << ",";
			}
			cout << "]" << "\n";
		}
	}
}