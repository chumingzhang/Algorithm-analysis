#include<iostream>
#include<algorithm>
using namespace std;

// 排序后输出num[k] 

// 类似快排 
int Partition(int num[], int l, int r) {
	int i = l;
	int j = r;
	int x = num[l];
	while(i < j) {
		while(i < j && num[j] >= x)
			j--;
		if(i < j)
			num[i++] = num[j];
			
		while(i < j && num[i] <= x)
			i++;
		if(i < j)
			num[j--] = num[i];
	} 
	num[i] = x;
	return i;
}

void findK(int num[], int l, int r, int k) {
	int pivot = Partition(num, l, r);
	if(pivot == k)
		cout << num[k];
	else if(pivot > k)
		return findK(num, l, pivot - 1, k);
	else 
		return findK(num, pivot + 1, r, k);
}

int main() {
	int n = 7;
	int num[] = {16, 8, 24, 9, 23, 73, 55};
	int k;
	cin >> k; 
	findK(num, 0, n - 1, k);
	
	return 0;
} 
