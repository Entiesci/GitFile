#include <bits/stdc++.h>
using namespace std;

//�뽫������������ĳ�����,����ֱ�Ӵӱ��ļ�����!)

//ǰ�ã���������������˴��븴�����������⣩
string sa, sb;
int la, lb, lc;
int a[99999], b[99999], c[99999];
//ǰ�ã����벢�������������㺯����ǰ�棩
cin >> sa >> sb;
la = sa.size();
lb = sb.size();
lc = max(la, lb);
for (int i = 0; i < la; i++)
	a[la - i] = sa[i] - '0';
for (int i = 0; i < lb; i++)
	b[lb - i] = sb[i] - '0';
//�������Ĵ���
for (int i = lc; i > 0; i--)
	cout << c[i];


//�����ӷ�
//����(����,����,����(<=10))
void add(int B) {

	for (int i = 0; i <= lc; i++) //�ȼ�
		c[i] = a[i] + b[i];

	for (int i = 0; i <= lc; i++) { //��λ
		c[i + 1] += c[i] / B;
		c[i] %= B;
	}

	if (c[lc + 1] != 0)
		lc++;
	while (c[lc] == 0 && lc > 1)
		lc--;//ȥǰ��0

}

//��������
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

//�����˷�
//������sa��x��int��
void mul_small(int x) {

	for (int i = 0; i <= lc; i++) //�ȼ�
		c[i] = a[i] * x;

	for (int i = 0; i <= lc; i++) { //��λ
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}

	if (c[lc + 1] != 0)
		lc++;
	while (c[lc] == 0 && lc > 1)
		lc--;//ȥǰ��0

}

//˫�����˷�
void mul_big() {

}

//��������(����/������)
void div_small(int x) {

}

//��������(����/����)
void div_big() {

}
