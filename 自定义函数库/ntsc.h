#include <bits/stdc++.h>
using namespace std;

//“有人认为，爱是性，是婚姻，是凌晨六点的吻，是一大堆孩子。橘小姐，你知道我怎么想吗？爱是想要触碰却又收回的手，如同雨落雨止。”

//判断质数
//返回值,是返回true,不是返回false
bool if_prime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

//输出逆序数字
//cout
void reverse_num(int x) {
	cout << x % 10;
	if (x > 10) {
		reverse_num(x / 10);
	} else
		return;
}

//输出逆序字符串,字符上限99999位
//参数(输入字符串,结束标识)
/*输入实例:
	gets(abc);
	sc(0);
*/
//cout
void reverse_char(char i, char j) {
	char a[99999];
	if (a[i] == j) {
		return;
	} else {
		reverse_char(i + 1, j);
		cout << a[i];
	}
}

//转进制
//参数(十进制数,目标进制)
//cout
void change_base(int a, int b) {
	char to1016[16] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int tmp;
	tmp = a % b;
	a = a / b;
	if (a != 0) {
		change_base(a, b);
	}
	cout << to1016[tmp];
}

//输出
//参数(数组名,分隔符号,数组开始,数组结尾)
void out(int s[], char c, int a, int b) {
	for (int i = a; i < b; i++)
		cout << s[i] << c;
	cout << s[b];
}

//排序库 v2
//请将要排序的数组设置为全局double数组

//冒泡排序。
//输入(排序开始项下标,排序结束项下标,列表名)
void sort_bub(int a, int b, double n[]) {
	for (int i = a; i <= b; i++) {
		for (int j = a; j + 1 <= b - i; j++) {
			if (n[j] > n[j + 1]) {
				swap(n[j], n[j + 1]);
			}
		}
	}
}

//选择排序。
//输入(排序开始项下标,排序结束项下标,列表名)
void sort_sel(int a, int b, double n[]) {
	for (int i = a; i <= b ; i++) {
		int min = i;
		for (int j = i + 1; j <= b; j++)
			if (n[j] < n[min])
				min = j;
		swap(n[i], n[min]);
	}
}

//判断完全数
//返回bool值
bool if_perfectnum(int a) {
	int sum = 0;
	for (int j = 1; j <= a / 2; j++) {
		if (a % j == 0)
			sum += j;
	}
	if (sum == a)
		return true;
	else
		return false;
}

//字符串大小写转换，位移
//输入(字符串string型,目标字母,目的字母)
/*实例
	change_str(s,A,a)  将字符串s中的大写转为小写
    change_str(s,b,a)  将字符串s中的字母按字母表左移1位
*/
//返回字符串string型
string change_str(string s, char a, char b) {
	for (int i = 0; i < s.size(); i++) {
		if (a >= 'a')
			if (s[i] >= a)
				s[i] = s[i] - (a - b);
			else;
		else if (s[i] < b)
			s[i] = s[i] - (a - b);
	}
	return s;
}

//阶乘
//参数(开始,结尾,间隔)
int fac_torial(int a, int b, int n) {
	int sum = 1;
	for (int i = a; i <= b; i += n) {
		sum *= i;
	}
	return sum;
}


//累加
//参数(开始,结尾,间隔)
int fac_plus(int a, int b, int n) {
	int sum = 0;
	for (int i = a; i <= b; i += n) {
		sum += i;
	}
	return sum;
}

//大数加法
//参数(加数,加数,进制(<=10))
void add(string sa, string sb, int B) {
	int la = sa.size();
	int lb = sb.size();
	int lc = max(la, lb);
	int a[99999], b[99999], c[99999];

	for (int i = 0; i < la; i++)
		a[la - i] = sa[i] - '0';
	for (int i = 0; i < lb; i++)
		b[lb - i] = sb[i] - '0';


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


	for (int i = lc; i > 0; i--)
		cout << c[i];
}

//大数减法
void jian(string sa, string sb) {
	int la = sa.size();
	int lb = sb.size();
	int lc = max(la, lb);
	int a[99999], b[99999], c[99999];

	for (int i = 0; i < la; i++)
		a[la - i] = sa[i] - '0';
	for (int i = 0; i < lb; i++)
		b[lb - i] = sb[i] - '0';


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

	for (int i = lc; i > 0; i--)
		cout << c[i];
}
