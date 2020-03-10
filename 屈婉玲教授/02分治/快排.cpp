#include<iostream>
#include<algorithm>
using namespace std;

void quick(int num[], int n, int l, int r) {
	if(l >= r)
		return;
		
	int key = num[l];
	int i = l, j = r;
	while(i < j) {
		for(; j > i; --j) {
			if(num[j] < key) {
				num[i] = num[j];
				i++;
				break;
			}
		}
		
		for(; i < j; ++i) {
			if(num[i] > key) {
				num[j] = num[i];
				j--;
				break;
			}
		}
	}
	num[i] = key;
	quick(num, n, l, i - 1);
	quick(num, n, i + 1, r);
}

int main() {
	int n = 10;
	int num[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	quick(num, n, 0, n - 1);
	for(int i = 0; i < n; ++i)
		cout << num[i] << " "; 
	return 0;
} 
