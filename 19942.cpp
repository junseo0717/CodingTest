#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 987654321;
int N, mp, mf, ms, mv, MP, MF, MS, MV, Price, MAX = INF;
int p[16]; int f[16]; int s[16]; int v[16]; int c[16];
bool flag = false;
int check[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++) cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];

	map<int, vector<vector<int>>> ans_idx; 
	for (int i = 0; i < (1 << N); i++) {
		MP = 0;  MF = 0; MS = 0; MV = 0; Price = 0;
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				MP += p[j]; MF += f[j];
				MS += s[j]; 
				MV += v[j];
				Price += c[j];
				temp.push_back(j + 1);
			}
		}
		if (MP >= mp && MF >= mf && MS >= ms && MV >= mv) {
			if (MAX >= Price) { 
				MAX = Price; 
				check[0] = MP; check[1] = MS;
				check[2] = MV; check[3] = MF;
				ans_idx[MAX].push_back(temp);
			}
		}
	}

	if (MAX == INF) { cout << -1 << "\n"; } 
	else {
		sort(ans_idx[MAX].begin(), ans_idx[MAX].end());
		cout << MAX << "\n";
		for (int a : ans_idx[MAX][0]) cout << a << "\n";
	}
}