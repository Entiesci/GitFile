#include <bits/stdc++.h>
using namespace std;
long long n, lc;
int a[222];

void chen() {
	for (int i = 0; i <= lc; i++) //先加
		a[i] = a[i] * 2;

	for (int i = 0; i <= lc; i++) { //进位
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	if (a[lc + 1] != 0)
		lc++;
	while (a[lc] == 0 && lc > 1)
		lc--;//去前导0

}

void pre(int n) {
	a[0] = 1;
	lc = 1;
	//计算2^(n+1)-2
	for (int i = 1; i <= n + 1 ; i++) {
		chen();
	}
	a[0] - 2;
	//借位
	for (int i = 0; i <= lc; i++) {
		if (a[i] < 0) {
			a[i + 1] -= 1;
			a[i] += 10;
		} else
			break;
	}
}

int main() {
	//freopen("hanoi.in", "r", stdin);
	//freopen("hanoi.out", "w", stdout);

	cin >> n;
	pre(n);

	for (int i = 0; i < lc; i++) {
		cout << a[i];
	}
	return 0;
}