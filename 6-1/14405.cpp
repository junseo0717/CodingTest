#include<iostream>
using namespace std;
string check[3] = { "pi", "ka", "chu" };

int main() {
	string str;
	cin >> str;
	int pos = 0;
	bool ans = true;

	//while(pos < str.size()) {
	//	int temp = pos; bool flag = true;
	//	for (int j = 0; j < 3; j++) {
	//		flag = true;
	//		for (int k = 0; k < check[j].size(); k++) {
	//			if (check[j][k] == str[temp]) { temp++; }
	//			else { flag = false; temp = pos; break; }
	//		}
	//		if (flag) { // 
	//			pos = temp;
	//			break;
	//		}
	//	}
	//	if (!flag) {
	//		cout << "NO" << "\n";
	//		ans = false;
	//		break;
	//	}
	// 
	// if (ans) cout << "YES" << "\n";
	//}

	for (int i = 0; i < str.size(); i++) {
		if (i < str.size() - 1 && str.substr(i, 2) == "pi" || str.substr(i, 2) == "ka") i += 1; // i가 추가로 1개 더 증가
		else if (i < str.size() - 2 && str.substr(i, 3) == "chu") i += 2;
		else {
			ans = false; break;
		}
	}

	if (ans) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}

// substr 활용 문제