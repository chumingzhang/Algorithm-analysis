#include<iostream>
using namespace std;

void InsertSort(int nums[], int n) {
	for(int i = 0; i < n - 1; ++i) {
		for(int j = i + 1; j >= 0; --j) {
			if(nums[j] < nums[j - 1]) {
				int temp = nums[j - 1];
				nums[j - 1] = nums[j];
				nums[j] = temp;
			} else {
				break;
			}
		}
	}
	
	for(int i = 0; i < n; ++i)
		cout << nums[i] << " ";
}

int main() {
	int n;
	cin >> n;
	int nums[100];
	for(int i = 0; i < n; ++i)
		cin >> nums[i];
	
	InsertSort(nums, n);	
	
	return 0;
} 
