//欧几里得法求最大公约数 
//Euclid算法求最大公约数

#include<iostream>
#define MAX(m, n) (m) > (n) ? m : n
#define MIN(m, n) (m) > (n) ? n : m
using namespace std;

int Euclid(int m, int n) {
	int result = 0;
	int big = MAX(m, n);
	int small = MIN(m, n);
	while(small > 0) {
		result = big % small;
		big = small;
		small = result;
	}
	return big;
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << Euclid(m, n);
	
	return 0;
} 


