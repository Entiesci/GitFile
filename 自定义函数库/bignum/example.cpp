#include <bits/stdc++.h>

using namespace std;


string sa, sb;
int la, x;
int lb ;
int lc ;
int a[99999], b[99999], c[99999];

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
	//输出结果
	for (int i = lc; i > 0; i--)
		cout << c[i];
	return 0;
}