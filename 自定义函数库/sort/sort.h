#include <bits/stdc++.h>
using namespace std;


//����� v2
//�뽫Ҫ�������������Ϊȫ��double����

//ð������
//����(����ʼ���±�,����������±�,�б���)
void sort_bub(int a, int b, double n[]) {
	for (int i = a; i <= b; i++) {
		for (int j = a; j + 1 <= b - i; j++) {
			if (n[j] > n[j + 1]) {
				swap(n[j], n[j + 1]);
			}
		}
	}
}

//ѡ������
//����(����ʼ���±�,����������±�,�б���)
void sort_sel(int a, int b, double n[]) {
	for (int i = a; i <= b ; i++) {
		int min = i;
		for (int j = i + 1; j <= b; j++)
			if (n[j] < n[min])
				min = j;
		swap(n[i], n[min]);
	}
}
