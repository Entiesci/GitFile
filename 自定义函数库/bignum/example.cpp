#include <bits/stdc++.h>

using namespace std;


string sa, sb;
int la, x;
int lb ;
int lc ;
int a[99999], b[99999], c[99999];

//乘法
void chen(int x) {

	for (int i = 0; i <= lc; i++) //先加
		c[i] = a[i] * x;

	for (int i = 0; i <= lc; i++) { //进位
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}

	if (c[lc + 1] != 0)
		lc++;
	while (c[lc] == 0 && lc > 1)
		lc--;//去前导0

}


int main() {
	cin >> sa >> x;
	la = sa.size();
	lb = sb.size();
	lc = max(la, lb);
	for (int i = 0; i < la; i++)
		a[la - i] = sa[i] - '0';
	for (int i = 0; i < lb; i++)
		b[lb - i] = sb[i] - '0';
	chen(x);
	for (int i = lc; i > 0; i--)
		cout << c[i];
	return 0;
}

//div_small
void div_small(int x) {
	lc = la;
	for (int i = 0; i < lc; i++) {
		c[i] = a[i] / x;
		a[i + 1] += (a[i] % x) * 10;
	}
	c[lc] = a[lc] / x;
	yu = a[lc] % x;
	lb = 0;
	for (int i = 0; i < lc; i++) {
		if (c[i] == 0 && lc > 1)
			lb++;
		else
			break;
	}
}

int main() {
	cin >> sa >> x;
	la = sa.size();
	for (int i = 0; i < la; i++)
		a[i] = sa[i] - '0';
	div_small(x);
	for (int i = lb; i < lc; i++)
		cout << c[i];
	cout << endl << yu;
	return 0;
}
//chen
#include <bits/stdc++.h>
using namespace std;
int res[100000];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			res[i + j] += (s1[i] - '0') * (s2[j] - '0');
		}
	}
	//js
	if (res[0] >= 10)
		cout << res[0] / 10;
	for (int i = len1 + len2 - 1; i > 0; i--) {
		if (res[i] >= 10) {
			res[i - 1] += res[i] / 10;
			res[i] %= 10;
		}
	}
	//输出
	for (int i = 0; i < len1 + len2 - 1; i++) {
		cout << res[i];
	}
	return 0;
}