#include<iostream>
using namespace std;

int n;
int nums[100];
int temp[100];

void merge(int first, int mid, int last) {
	int i = first, n = mid;
	int j = mid + 1, m = last;
	int k = 0;
	
	while(i <= n && j <= m) {
		if(nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	
	while(i <= n)
		temp[k++] = nums[i++];
	while(j <= m)
		temp[k++] = nums[j++];
		
	for(int ii = 0; ii < k; ++ii)
		nums[first + ii] = temp[ii];
}

void MergeSort(int first, int last) {
	if(first < last) {
		int mid = (first + last) / 2;
		MergeSort(first, mid);
		MergeSort(mid + 1, last);
		merge(first, mid, last);
	}
} 

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> nums[i];
	
	MergeSort(0, n - 1);	
	
	for(int i = 0; i < n; ++i)
		cout << nums[i] << " ";
	return 0;
} 
