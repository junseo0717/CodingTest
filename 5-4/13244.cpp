#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
vector<int> list[1004];
int T, N, M;
bool visited[1004];

void DFS(int Node) {
	//if (visited[Node]) return;
	visited[Node] = true;

	for(int n : list[Node]) {
		if (!visited[n]) DFS(n);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> T;

	while (T--) {
		for (int i = 0; i < 1004; i++) list[i].clear(); //list clear..
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int s, e; cin >> s >> e;
			list[s].push_back(e);
			list[e].push_back(s);
		}
		if (M != N - 1) {
			cout << "graph" << "\n"; continue;
		}

		memset(visited, false, sizeof(visited));
		DFS(1);

		bool flag = true; //
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				cout << "graph" << "\n"; 
				flag = false; // ���� & �ݷʻ��� 
				// �ƴ� ���⼭ continue�ص� while�� �ɸ��� ���� �ƴϴϱ� flag ������ �־����..
				// �ݷʴ� ��� �����ؾ��ϳ�? : �ᱹ �� �ڵ带 �����߰ڴٰ� �����ؾ���
				break;
			}
		}
		if(flag) cout << "tree" << "\n";
	}
}