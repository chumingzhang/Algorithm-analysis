//p37 动态规划算法设计 
#include <iostream>
#include <algorithm>
using namespace std;

int m[100][100];	//得到第i个到第j个矩阵最少的相乘次数 
int s[100][100];	//记录断点 

int MatrixChain(int p[], int n) {
	//m[i][j]表示从i到j的矩阵连乘最小次数，和普通二维数组计算次序不同
    //m[i][j]是一个右上三角矩阵，先知道对角线的值，然后往右上方递推
    //如已知m[0][0],m[1][1],m[2][2]=0, 可求m[0][1], m[1][2]，再求m[0][2]
	for (int r = 1; r < n; ++r) { //矩阵跨度 
		for(int i = 0; i < n - r; ++i) { //对每个m[i][i+r]，计算i到i+r之间每个k的划分结果
			int j = i + r; //j取最右矩阵的下标
			m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];	//初始化先取k=i的情况
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

