#include <iostream>
#include<string>
#include <algorithm>
#include<cmath>
using namespace std;

int n = 6;
int p[] = {10, 12, 15, 255, 1, 2};
int dp[10];		//dp[i]ǰi�����ص���С�洢 
int b[10];		//ÿ����ռλ�� 
int trace[10];	//ǰi��ʱ���һ���ֶεĳ��� 

int Length(int num) {
	for(int i = 0; i <= 8; ++i) {
		if(pow(2, i) >= (num + 1))
			return i; 
	}
}

void Compress() {
	for(int i = 1; i <= n; ++i) {
		b[i] = Length(p[i - 1]);
		dp[i] = dp[i - 1] + b[i];
		trace[i] = 1; 
		for(int j = 0; j < i - 1; ++j) {
			int maxBit = b[j + 1];
			for(int k = j + 2; k <= i; ++k) {
				if(b[k] > maxBit)
					maxBit = b[k];
			} 
			int temp = dp[j] + (i - j) * maxBit;
			if(dp[i] > temp) {
				dp[i] = temp;
				trace[i] = i - j;
			}
		}
		dp[i] += 11;
	}
}

void traceBack(int left) {
	if(left <= 0)
		return;
	cout << trace[left] << endl;
	traceBack(left - trace[left]);
}

int main()
{
	Compress();
//	for(int i = 1; i <= n; ++i) {
//		cout << trace[i] << " ";
//	} 
	cout << "��СΪ: " << dp[n] << endl;
	traceBack(n);
    return 0;
}

