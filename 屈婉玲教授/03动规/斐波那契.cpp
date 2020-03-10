#include <iostream>
#include <algorithm>
using namespace std;

// µÝ¹é
int Fib(int n) {
	if(n <= 1)
		return n;
		
	return Fib(n - 1) + Fib(n - 2);
} 

// ¶¯¹æ 
//int Fib(int n) {
//	int dp[100];
//	dp[0] = 0;
//	dp[1] = 1;
//	
//	for(int i = 2; i <= n; ++i)
//		dp[i] = dp[i - 1] + dp[i - 2];
//		
//	return dp[n];
//}

int main()
{
	int n;
	cin >> n;
	cout << Fib(n) << endl; 
    return 0;
}

