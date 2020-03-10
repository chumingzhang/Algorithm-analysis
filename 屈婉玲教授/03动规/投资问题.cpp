#include <iostream>
#include <algorithm>
using namespace std;

int dp[10][10];	//dp[i][j]��ʾ��ǰ(i+1)����ĿͶ��j��Ԫʱ������������� 
int trace[10][10];	//׷�ٽ� 

void calc(int m, int n ,int value[4][6]) {
	for(int j = 0; j <= m; ++j) {
		dp[0][j] = value[0][j];
		trace[0][j] = j;
	}
		
	
	for(int i = 1; i < n; ++i) {	//i-��Ŀ�� 
		for(int j = 1; j <= m; ++j) {	//j-��Ǯ�� 
			for(int k = 0; k <= j; ++k)	{	//k-ǰ(i - 1)����Ŀ���õ�Ǯ�� 
				int temp = dp[i - 1][k] + value[i][j - k];
				if(temp > dp[i][j]) {
					dp[i][j] = temp;
					trace[i][j] = j - k;
				} 
			}
		}
	}
}

void traceBack(int left, int cur, int value[4][6]) {
	if(left <= 0)
		return;
	cout << "��Ŀ" << cur + 1 << " Ͷ���ˣ� " << trace[cur][left] << " ��Ԫ, ���� " << value[cur][trace[cur][left]] << " ��Ԫ" << endl;
	traceBack(left - trace[cur][left], cur - 1, value);
}

int main()
{
	//5��Ԫ�ָ�4����Ŀ 
	int m = 5, n = 4;
	//value[i][j]��ʾͶ�ʵ�i����Ŀj��Ԫʱ������ 
	int value[4][6] = {
			{0, 11, 12, 13, 14, 15},
			{0, 0, 5, 10, 15, 20},
			{0, 2, 10, 30, 32, 40},
			{0, 20, 21, 22, 23, 24}
		};
	calc(m, n, value);
//	for(int i = 0; i < 4; ++i) {
//		for(int j = 0; j <= 5; ++j) {
//			cout << trace[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	cout << "The maximun reward: " << dp[n - 1][m] << endl;
	traceBack(m, n - 1, value);
    return 0;
}

