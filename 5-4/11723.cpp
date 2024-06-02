#include<iostream>
#include<string.h>
using namespace std;
int M, N;
//bool visited[21]; // 이거 대신에 비트마스킹을 쓰자고 생각해볼 수 있어야 함!

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> M;
	for (int i = 0; i < M; i++) {
		string s; int m;
		cin >> s;
		if (s == "all") {
			//memset(visited, false, sizeof(visited)); 
			N = (1 << 21) - 1;
			continue;
		}
		if (s == "empty") {
			//memset(visited, true, sizeof(visited)); 
			N = 0;  continue;
		}
		cin >> m;
		/*if (s == "add" && !visited[m]) visited[m] = true;
		else if (s == "remove" && visited[m]) visited[m] = false;
		else if (s == "check" && visited[m]) cout << 1 << "\n";
		else if (s == "check" && !visited[m]) cout << 0 << "\n";
		else if (s == "toggle" && visited[m]) visited[m] = false;
		else if (s == "toggle" && !visited[m]) visited[m] = true;*/
		if (s[0] == 'a') N |= (1 << m);
		else if (s[0] == 'r') N &= ~(1 << m);
		else if (s[0] == 'c' && N & (1 << m)) cout << 1 << "\n";
		else if (s[0] == 'c' && !(N & (1 << m))) cout << 0 << "\n";
		else if (s[0] == 't') N ^= (1 << m);
	}
}