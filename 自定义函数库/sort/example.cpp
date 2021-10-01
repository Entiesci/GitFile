#include <bits/stdc++.h>
#include <D:\文档\GitHub\File\自定义函数库\sort\sort.h>
using namespace std;
double a[9999], x;


int main() {
	cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
	}
	sort_bub(1, x, a);
	for (int i = 1; i <= x; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}