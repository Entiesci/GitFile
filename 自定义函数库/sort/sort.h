#include <bits/stdc++.h>
using namespace std;


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
