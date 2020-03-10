#include<iostream>
#include<algorithm>
using namespace std;

//两两比大小，较小者再和当前最小值比，较大者再和当前最大值比 
//若n为奇数，轮空一个，剩下每2个元素比3次，一共比3n / 2 - 3次
//若n为偶数，开始只比1次，剩下每2个元素比3次，一共3n / 2 - 2次
//所以总的来说至多3n / 2 - 2次
void findMaxMin(int num[], int n, int &max_num, int &min_num) {
	if(n <= 0) {
		return;
	} else if(n == 1) {
		max_num = num[0];
		min_num = num[0];
		return;
	} else if(n % 2 != 0) {	//n为奇数时， 初值设为最后一个元素 
		max_num = num[n - 1];
		min_num = num[n - 1];
	} else {
		max_num = max(num[n - 1], num[n - 2]);
		min_num = min(num[n - 1], num[n - 2]);
		n -= 2;
	}
	
	for(int i = 0; i < n; i += 2) {
		if(num[i] > num[i + 1]) {
			max_num = max(max_num, num[i]);
			min_num = min(min_num, num[i + 1]);
		} else {
			max_num = max(max_num, num[i + 1]);
			min_num = min(min_num, num[i]);
		}
	}
}

int main() {
	int n = 10;
	int num[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}; 
	int max_num, min_num;
	findMaxMin(num, n, max_num, min_num);
	cout << "max " << max_num << endl;
	cout << "min " << min_num << endl;
	return 0;
} 
