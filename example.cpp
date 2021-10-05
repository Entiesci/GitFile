#include <bits/stdc++.h>
using namespace std;
int n, a[10001], mx, nmx, nmxid, ans = 1, flag, flag2;

void pre() {
	mx = a[1];
	a[1] = 0;
	while (1) {
		flag = 0;
		for (int j = 1; j <= n;) {
			nmxid = -1;
			nmx = 0;
			for (int i = j; i <= n; i++) {
				if (a[i] < mx && nmx < a[i]) {
					nmx = a[i];
					nmxid = i;
				}
			}
			if (nmxid > 0) {
				a[nmxid] = 0;

			} else {
				cout << "new ";
				ans++;
				for (int i = 1; i <= n; i++) {
					if (a[i]) {
						nmxid = i;
						flag = 1;
						break;
					}
				}
			}
			if (flag = 1)
				break;
			j = nmxid;
			mx = a[nmxid];
		}
		flag2 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] != 0)
				flag2 = 1;
		}
		if (flag2 = 0)
			return;
	}
}

int main() {
	int i = 1;
	while (cin >> a[i])
		i++;

	pre();
	cout << ans;
	return 0;
}