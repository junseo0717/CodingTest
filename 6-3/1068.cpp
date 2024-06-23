#include<iostream>
#include<vector>
using namespace std;
int N, del;
vector<int> node[50];
bool check[50];
int answer = 0;

void DFS(int d) {
	bool flag = true;//

	for (int i = 0; i < node[d].size(); i++) {
		if (node[d][i] == del || check[node[d][i]]) continue;
		check[node[d][i]] = true;
		flag = false; 
		DFS(node[d][i]);
	}

	if (flag) answer++;
	return;
}

int main() {
	cin >> N;
	int root = 0;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		if (n < 0) {
			root = i; continue;
		}
		node[n].push_back(i); 
	}
	cin >> del;
	DFS(root);

}