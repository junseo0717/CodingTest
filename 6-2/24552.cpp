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
		if (sum < 0) { // b�� �� ū ��� ������ �������� ��ȣ���� �ǹǷ�
			cout << b << "\n";
			flag = false;
			break;
		}
		if (sum == 0) { // a = b�� �� ū ���
			a = 0;
		}
	}
	if(flag) cout << a << "\n";	
}