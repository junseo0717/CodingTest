#include<iostream>
#include<string.h>
using namespace std;
int N, M;
int map[4][4];
bool visited[4][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		int Idx = M - 1;
		while (num > 0) {
			map[i][Idx] = num % 10;
			Idx--;
			num /= 10;
		}
	}
	int answer = 0;
	for (int s = 0; s < (1 << (N * M)); s++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int temp = 0;
			for (int j = 0; j < M; j++) {
				int idx = i * M + j; 
				if ((s & (1 << idx)) == 0) {
					temp = temp * 10 + map[i][j];
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}

		for (int j = 0; j < M; j++) {
			int temp = 0;
			for (int i = 0; i < N; i++) {
				int idx = i * M + j; 
				int idx = i * M + j; 
				if ((s & (1 << idx)) != 0) { 
					temp = temp * 10 + map[i][j]; 
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;// ÁÖÀÇ
		}
		answer = max(answer, sum);
	}
	cout << answer << "\n";
}