#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N, K;
vector<int> map[54];
bool visited[51];
int answer = 0;

//void Remove(int Node) {
//	if (map[Node].empty()) return;
//
//	for (int i = map[Node].size() - 1; i >= 0; i--) {
//		Remove(map[Node][i]);
//		map[Node].pop_back();
//	}
//	return;
//}

void Answer(int Node) {
	//if (map[Node].empty() || visited[Node]) return; // ����
	bool flag = true;

	for (int i = 0; i < map[Node].size(); i++) {
		if (visited[map[Node][i]] || map[Node][i] == K) continue;
		visited[map[Node][i]] = true;
		flag = false; // �̰�
		Answer(map[Node][i]);
	}

	if (flag) answer++; // ����
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	int root;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Node; cin >> Node;
		if (Node == -1) {
			root = i; continue;
		}
		map[Node].push_back(i);
	}
	cin >> K;
	//Remove(K); ���ʿ� k�� �������� ���ϵ��� ����

	if (K == root){ cout << 0 << "\n";}
	else { Answer(root); cout << answer << "\n"; }
}