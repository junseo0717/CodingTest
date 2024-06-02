#include<iostream>
#include<vector>
using namespace std;
int X;
vector<int> lenght;
int answer = 1;

int main() {
	cin >> X;
	/*lenght.push_back(64);

	while (true) {
		int temp = 0;
		for (int i = 0; i < lenght.size(); i++) temp += lenght[i];
		if (temp == X) {
			cout << lenght.size() << "\n";
			break;
		}
		int back = lenght.back();
		lenght.pop_back();
		lenght.push_back(back / 2);
		lenght.push_back(back / 2);
		temp = 0;
		for (int i = 0; i < lenght.size() - 1; i++) temp += lenght[i];
		if(temp >= X) lenght.pop_back();
	}*/

	while (X != 1) {
		if (X & 1) answer++;
		X /= 2;
	}
	cout << answer << "\n";
}