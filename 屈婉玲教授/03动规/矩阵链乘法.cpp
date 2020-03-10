//p37 ��̬�滮�㷨��� 
#include <iostream>
#include <algorithm>
using namespace std;

int m[100][100];	//�õ���i������j���������ٵ���˴��� 
int s[100][100];	//��¼�ϵ� 

int MatrixChain(int p[], int n) {
	//m[i][j]��ʾ��i��j�ľ���������С����������ͨ��ά����������ͬ
    //m[i][j]��һ���������Ǿ�����֪���Խ��ߵ�ֵ��Ȼ�������Ϸ�����
    //����֪m[0][0],m[1][1],m[2][2]=0, ����m[0][1], m[1][2]������m[0][2]
	for (int r = 1; r < n; ++r) { //������ 
		for(int i = 0; i < n - r; ++i) { //��ÿ��m[i][i+r]������i��i+r֮��ÿ��k�Ļ��ֽ��
			int j = i + r; //jȡ���Ҿ�����±�
			m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];	//��ʼ����ȡk=i�����
			s[i][j] = i;
			for(int k = i + 1; k < j; ++k) {
				int temp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if(temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			} 
		}
	}
	
	return m[0][n - 1];
}

void TraceSolution(int l, int r) {
	if(r - l < 2)
		return;
	cout << s[l][r] << " ";
	TraceSolution(l, s[l][r]);
	TraceSolution(s[l][r] + 1, r);
}
 

int main()
{
	int n = 5;
	int p[] = {30, 35, 15, 5, 10, 20};
	int ans = MatrixChain(p, n);
	cout << "Min multiply times: " << ans << endl;
    cout << "Solution is: " << endl;
    TraceSolution(0, n - 1);
	  
    return 0;
}

