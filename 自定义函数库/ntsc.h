#include <bits/stdc++.h>
using namespace std;

//��������Ϊ�������ԣ��ǻ��������賿������ǣ���һ��Ѻ��ӡ���С�㣬��֪������ô���𣿰�����Ҫ����ȴ���ջص��֣���ͬ������ֹ����

//�ж�����
//����ֵ,�Ƿ���true,���Ƿ���false
bool if_prime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

//�����������
//cout
void reverse_num(int x) {
	cout << x % 10;
	if (x > 10) {
		reverse_num(x / 10);
	} else
		return;
}

//��������ַ���,�ַ�����99999λ
//����(�����ַ���,������ʶ)
/*����ʵ��:
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

//ת����
//����(ʮ������,Ŀ�����)
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

//���
//����(������,�ָ�����,���鿪ʼ,�����β)
void out(int s[], char c, int a, int b) {
	for (int i = a; i < b; i++)
		cout << s[i] << c;
	cout << s[b];
}

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

//�ж���ȫ��
//����boolֵ
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

//�ַ�����Сдת����λ��
//����(�ַ���string��,Ŀ����ĸ,Ŀ����ĸ)
/*ʵ��
	change_str(s,A,a)  ���ַ���s�еĴ�дתΪСд
    change_str(s,b,a)  ���ַ���s�е���ĸ����ĸ������1λ
*/
//�����ַ���string��
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

//�׳�
//����(��ʼ,��β,���)
int fac_torial(int a, int b, int n) {
	int sum = 1;
	for (int i = a; i <= b; i += n) {
		sum *= i;
	}
	return sum;
}


//�ۼ�
//����(��ʼ,��β,���)
int fac_plus(int a, int b, int n) {
	int sum = 0;
	for (int i = a; i <= b; i += n) {
		sum += i;
	}
	return sum;
}

//�����ӷ�
//����(����,����,����(<=10))
void add(string sa, string sb, int B) {
	int la = sa.size();
	int lb = sb.size();
	int lc = max(la, lb);
	int a[99999], b[99999], c[99999];

	for (int i = 0; i < la; i++)
		a[la - i] = sa[i] - '0';
	for (int i = 0; i < lb; i++)
		b[lb - i] = sb[i] - '0';


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


	for (int i = lc; i > 0; i--)
		cout << c[i];
}

//��������
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
