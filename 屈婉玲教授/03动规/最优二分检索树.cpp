//�������ݵ�ƽ��ʱ����С 
#include <iostream>
#include <algorithm>
using namespace std;

int n = 5;
char S[] = {'A', 'B', 'C', 'D', 'E'};
float P[] = {0.04, 0.1, 0.02, 0.3, 0.02, 0.1, 0.05, 0.2, 0.06, 0.1, 0.01};
float dp[15][15]; 	//dp[i][j]�� i ~ j ��ɵ���С 
float w[15][15];	//w[i][j]�� i ~ j ��ɵĸ����ܺ� 
int trace[15][15]; 	//��¼��ǰ�������ڵ� 

void init() {
	for(int i = 1; i <= n; ++i) {
		w[i][i] = P[2 * i - 2] + P[2 * i - 1] + P[2 * i];
		dp[i][i] = w[i][i];
		trace[i][i] = i;
		for(int j = i + 1; j <= n; ++j) {
			w[i][j] = w[i][j - 1] + P[2 * j - 1] + P[2 * j];
		}
	}
}

void calc() {
	//��ʼ��
	init(); 

//��һ 
	for(int len = 1; len < n; ++len) {
		for(int i = 1; i <= n - len; ++i) {
			int j = i + len;
			dp[i][j] = dp[i + 1][j];
			trace[i][j] = i;
			for(int k = i + 1; k <= j; ++k) {
				float temp = dp[i][k-1];
                if (k!=j){ //k=jʱ��m[j+1][j]=1
                    temp += dp[k+1][j];
                }
               if (temp < dp[i][j]){
                   dp[i][j] = temp;
                   trace[i][j] = k;
               }
            }
            dp[i][j] += w[i][j];
		}
	}

//���� (���󣬼���˳�����Ӧ�ð��Խ���˳�������Ϸ�������)
//	for(int i = 1; i <= n; ++i) {
//		for(int j = i + 1; j <= n; ++j) {
//			dp[i][j] = dp[i][i - 1] + dp[i + 1][j] + w[i][j];
////			cout << i << " " << j << " " << dp[i][j] << " ???" << endl;
//			for(int k = i + 1; k <= j; ++k) {
//				float temp = dp[i][k - 1] + dp[k + 1][j] + w[i][j];
////				cout << i << " " << k << " " << j << " " << temp << " 111" << endl;
//				if(temp < dp[i][j]) {
////					cout << "asd" << endl;
//					dp[i][j] = temp;
//				}
//			}
//		}
//	}
}

// ���������������� 
void traceBack(int l, int r) {
	if(l > r)
		return;
	int rootIndex = trace[l][r];
	cout << S[trace[l][r] - 1] << " ";
	traceBack(l, rootIndex - 1); 
	traceBack(rootIndex + 1, r); 
}

int main()
{
	calc();
	cout << "The ans is: " << dp[1][n] << endl;
//	for(int i = 1; i <= n; ++i) {
//		for(int j = 1; j <= n; ++j) {
//			cout << trace[i][j] << " ";
//		}
//		cout << endl;
//	}
	traceBack(1, n);
    return 0;
}
