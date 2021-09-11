#include <bits/stdc++.h>
using namespace std;


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
		reverse_char(i + 1);
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