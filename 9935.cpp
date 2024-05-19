#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
string str1, str2;
stack<int> stk;

int main() {
	cin >> str1 >> str2;

	for (char a : str1) {
		stk.push(a);
		if (stk.size() >= str2.size() && stk.top() == str2[str2.size() - 1]) {
			string temp = "";
			for (char b : str2) {
				temp += stk.top();
				stk.pop();
			}
			reverse(temp.begin(), temp.end()); 
			if (temp != str2) {
				for (int b : temp) stk.push(b);
			}
		}
	}
	
	if (stk.size() == 0) cout << "FRULA" << "\n";
	else {
		string ret = "";
		while (stk.size()) { ret += stk.top(); stk.pop(); }
		reverse(ret.begin(), ret.end());
		cout << ret << "\n";
	}
}