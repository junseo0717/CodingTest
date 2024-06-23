#include<iostream>
using namespace std;


int main() {
	string str;
	cin >> str;

	int a = 0, b = 0, sum = 0;
	bool flag = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' (') {
			a++;
			sum++;
		}
		else {
			b++;
			sum--;
		}
		if (sum < 0) { // b가 더 큰 경우 b를 뺄 때마다 올바른 괄호가 됨
			cout << b << "\n";
			flag = false;
			break;
		}
		if (sum == 0) { // a = b인 더 큰 경우 옳바른 괄호이므로 a = 0을 만들어줌
			a = 0;
		}
		// a가 더 큰 경우 X
	}
	if(flag) cout << a << "\n";	// a가 많은 경우 올바른 괄호가 만들어져 있는 것을 제외한 괄호가 답..
}