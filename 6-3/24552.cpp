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
		if (sum < 0) { // b�� �� ū ��� b�� �� ������ �ùٸ� ��ȣ�� ��
			cout << b << "\n";
			flag = false;
			break;
		}
		if (sum == 0) { // a = b�� �� ū ��� �ǹٸ� ��ȣ�̹Ƿ� a = 0�� �������
			a = 0;
		}
		// a�� �� ū ��� X
	}
	if(flag) cout << a << "\n";	// a�� ���� ��� �ùٸ� ��ȣ�� ������� �ִ� ���� ������ ��ȣ�� ��..
}