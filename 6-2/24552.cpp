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
		if (sum < 0) { // b가 더 큰 경우 무조건 옳지않은 괄호열이 되므로
			cout << b << "\n";
			flag = false;
			break;
		}
		if (sum == 0) { // a = b인 더 큰 경우
			a = 0;
		}
	}
	if(flag) cout << a << "\n";	
}