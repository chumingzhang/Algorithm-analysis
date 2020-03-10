#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

string X = "ABCBDAB";
string Y = "BDCABA";
int dp[10][10];		//dp[i][j]第一个序列前i个和第二个序列前j个的最长公共子序列 
char trace[10][10];	//T表示斜向上，L表示←，U表示↑ 

void LCS(string x, string y) {
	for(int i = 1; i <= x.length(); ++i) {
		for(int j = 1; j <= y.length(); ++j) {
			if(x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1; 
				trace[i][j] = 'T'; 
			} else if(dp[i - 1][j] >= dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j]; 
				trace[i][j] = 'U'; 
			} else {
				dp[i][j] = dp[i][j - 1]; 
				trace[i][j] = 'L'; 
			}
		}
	} 
}

void traceBack(int r, int c, string cur_ans) {
	if(r <= 0 || c <= 0) {
		cout << cur_ans;
		return;
	}
	
	if(trace[r][c] == 'T') {
		traceBack(r - 1, c - 1, X[r - 1] + cur_ans);
	} else if(trace[r][c] == 'L') {
		traceBack(r, c - 1, cur_ans);
	} else {
		traceBack(r - 1, c, cur_ans);
	}
}

int main()
{
	LCS(X, Y);
	for(int i = 1; i <= X.length(); ++i) {
		for(int j = 1; j <= Y.length(); ++j) {
			cout << trace[i][j] << " ";
		}
		cout << endl;
	} 
	cout << "最长为: " << dp[X.length()][Y.length()] << endl;
	traceBack(X.length(), Y.length(), "");
    return 0;
}

