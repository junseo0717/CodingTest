#include<iostream>
using namespace std;
int n;
int num[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n;
    int sum = 0; int ret = -1004;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        ret = max(ret, sum); // ��� �� ����
        if (sum < 0) sum = 0; // ������ ���͹����� �� ���� ������ �������� ��������
    }
    cout << ret << "\n";
}