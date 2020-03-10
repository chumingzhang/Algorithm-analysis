#include <iostream>
#include <algorithm>
using namespace std;

int n = 4, b = 10;
int v[] = {1, 3, 5, 9};
int w[] = {2, 3, 4, 7};
int dp[15][15];			//dp[i][j]��ǰi����Ʒ����������j������ֵ 
int trace[15][15];		//trace[i][j]װǰi����Ʒ����������jʱװ����Ʒ������� 

// ��ȫ�������� (��һ-�Ϻ�)
//void calc() {
//	//��ʼ��
//	for(int j = w[0]; j <= b; ++j) {
//		dp[1][j] = (j / w[0]) * v[0]; 
//		trace[1][j] = 1;
//	}
//
//	for(int i = 2; i <= n; ++i) {
//		for(int j = 1; j <= b; ++j) {
//			dp[i][j] = dp[i - 1][j];
//			trace[i][j] = trace[i - 1][j];
//			if(j - w[i - 1] >= 0) {
//				int temp = dp[i][j - w[i - 1]] + v[i - 1];
//				if(temp >= dp[i - 1][j]) {
//					dp[i][j] = temp;
//					trace[i][j] = i;
//				}
//			}	
//		}
//	} 
//}

// ��ȫ�������� (����-�ϲ�)
//void calc() {
//	//��ʼ��
//	for(int j = w[0]; j <= b; ++j) {
//		dp[1][j] = (j / w[0]) * v[0]; 
//		trace[1][j] = 1;
//	}
//
//	for(int i = 2; i <= n; ++i) {
//		for(int j = 1; j <= b; ++j) {
//			dp[i][j] = dp[i - 1][j];
//			trace[i][j] = trace[i - 1][j];
//			for(int k = 0; k * w[i - 1] <= j; ++k)  {
//				int temp = dp[i][j - k * w[i - 1]] + (k * v[i - 1]);
//				if(temp >= dp[i][j]) {
//					dp[i][j] = temp;
//					trace[i][j] = i;
//				}
//			}	
//		}
//	} 
//}

//0-1�������� 
void calc() {
	//��ʼ��
	for(int j = w[0]; j <= b; ++j) {
		dp[1][j] = (j / w[0]) * v[0]; 
		trace[1][j] = 1;
	}

	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= b; ++j) {
			dp[i][j] = dp[i - 1][j];
			trace[i][j] = trace[i - 1][j];
			if(j - w[i - 1] >= 0) {
				int temp = dp[i - 1][j - w[i - 1]] + v[i - 1];
				if(temp >= dp[i - 1][j]) {
					dp[i][j] = temp;
					trace[i][j] = i;
				}
			}	
		}
	} 
}

void traceBack(int cur, int left) {
	if(left <= 0)
		return;
	cout << "װ����Ʒ" << trace[cur][left] << endl;
	traceBack(trace[cur][left], left - w[trace[cur][left] - 1]);
}

int main()
{
	calc();
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= b; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	} 
	cout << "����ֵ: " <<dp[n][b] << endl;
	traceBack(n, b);
    return 0;
}

