#include<iostream>
#include<algorithm>
using namespace std;
int N;
pair<int,int> line[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> line[i].first >> line[i].second;
	sort(line, line + N);

	long long answer = 0;
	int pre = line[0].first; // ���� ������
	int MAX = line[0].second; // ���� ����
	//�̿� ���� ��Ȳ�� �ٷ� ���� �ٲ� �� �־�� �� ������ �������� sort

	for (int i = 1; i < N; i++) {
		int s = line[i].first; // ���� ������
		int e = line[i].second; // ���� ����
		if (MAX >= s && MAX <= e) { 
			MAX = e; 
		}
		else if(MAX < s) { 
			answer += MAX - pre;
			pre = line[i].first;
			MAX = line[i].second;
		}
	}
	answer += MAX - pre;
	cout << answer << "\n";
}