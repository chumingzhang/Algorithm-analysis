#include<iostream>
using namespace std;

int BinarySearch(int num[], int l, int r, int to_find) {
	int find_times = 0;
	while(l <= r) {
		find_times++;
		int mid = (l + r) / 2;
		if(num[mid] == to_find)
			return find_times;
		else if(num[mid] > to_find)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	int num[100];
	for(int i = 0; i < n; ++i)
		num[i] = i + 1;
	
	for(int i = 0; i < n; ++i) {
		int find_times = BinarySearch(num, 0, n - 1, i + 1);
		if(find_times) {
			cout << "find " << i + 1 << " in " << find_times << " search" << endl;
		}
			
	}		
	
		
	return 0;
} 
