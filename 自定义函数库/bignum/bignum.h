#include <bits/stdc++.h>
using namespace std;

//请将函数复制在你的程序里,不用直接从本文件调用!)

//前置（定义变量）（将此代码复制在主函数外）
string sa, sb;
int la, lb, lc;
int a[99999], b[99999], c[99999];
//前置（输入并处理）（放在运算函数的前面）
cin >> sa >> sb;
la = sa.size();
lb = sb.size();
lc = max(la, lb);
for (int i = 0; i < la; i++)
	a[la - i] = sa[i] - '0';
for (int i = 0; i < lb; i++)
	b[lb - i] = sb[i] - '0';
//输出结果的代码
for (int i = lc; i > 0; i--)
	cout << c[i];


//大数加法
//参数(加数,加数,进制(<=10))
void add(int B) {

	for (int i = 0; i <= lc; i++) //先加
		c[i] = a[i] + b[i];

	for (int i = 0; i <= lc; i++) { //进位
		c[i + 1] += c[i] / B;
		c[i] %= B;
	}

	if (c[lc + 1] != 0)
		lc++;
	while (c[lc] == 0 && lc > 1)
		lc--;//去前导0

}

//大数减法
void sub() {

	for (int i = 0; i <= lc; i++)
		c[i] = a[i] - b[i];

	for (int i = 0; i <= lc; i++) {
		if (c[i] < 0) {
			c[i] += 10;
			c[i + 1]--;
		}
	}

	while (c[lc] == 0 && lc > 1)
		lc--;
}

//大数乘法
//因数：sa，x（int）
void mul_small(int x) {

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

//双大数乘法
void mul_big() {

}

//大数除法(大数/单精度)
void div_small(int x) {

}

//大数除法(大数/大数)
void div_big() {

}
