#include <iostream>
#include<string>
#include <algorithm>
#include<cmath>
using namespace std;

int n = 7;
int p[] = {2, -5, 8, 11, -3, 4, 6};
int dp[10];		//dp[i]前i项最大子段和 
int trace[10];	//前i项时最后一个分段的长度 

//递推方程dp[i] = max{p[i], dp[i-1] + p[i]}; 注意不是max{dp[i-1], dp[i-1]+p[i]}!
void MaxSubSum() {
	int begin = 0, end = 0;
	int max = 0;
	if(p[0] > 0) {
		dp[0] = p[0];
		max = p[0];
	} else {
		dp[0] = 0;
	}
	
	for(int i = 1; i < n; ++i) {
		if(dp[i - 1] > 0)
			dp[i] = p[i] + dp[i - 1];
		else {	//前面的和 < 0 舍弃
			dp[i] = p[i];
			begin = i; 
		}
		
		if(dp[i] > max) {
			max = dp[i];
			end = i;
		}
	}
	
	cout << max << endl;
	cout << "max sum range is: [" << p[begin] << ", " << p[end] << "]" << endl;
}

int main()
{
	MaxSubSum();
//	for(int i = 1; i <= n; ++i) {
//		cout << dp[i] << " ";
//	} 
//	cout << "最小为: " << dp[n] << endl;
    return 0;
}

