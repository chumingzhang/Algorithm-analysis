#include<iostream>
#include<algorithm>
#include<list> 
using namespace std;

// myΩı±Í»¸À„∑® 
//void findSecondMax(int num[], int n) {
//	list<int> lists[100];
//	int temp[100];
//	for(int i = 0; i < n; ++i)
//		temp[i] = num[i];
//	
//	while(n > 1) {
//		int index = 0;
//		for(int i = 0; i < n - 1; i += 2) {
//			if(temp[i] < temp[i + 1]) {
//				lists[temp[i + 1]].push_back(temp[i]);
//				temp[index] = temp[i + 1];
//				index++;
//			} else {
//				lists[temp[i]].push_back(temp[i + 1]);
//				temp[index] = temp[i];
//				index++;
//			}
//		}
//		
//		if(n % 2 == 0)
//			n /= 2;
//		else {
//			temp[index] = temp[n - 1];
//			n = (n / 2) + 1;
//		}
//			
//	}
//	
//	int sec = -1;
//	list<int>::iterator iter;
//	for(iter = lists[temp[0]].begin(); iter != lists[temp[0]].end(); ++iter) {
//		sec = max(sec, *iter);
//	}
//	cout << "The second largest num is " << sec << endl;
//}

void findSecondMax(int num[], int n) {
	if(n < 2)
		return;
	
	list<int> smallList[100];
	int maxNum = num[0];
	int maxIndex = 0;
	for(int i = 1; i < n; ++i) {
		if(num[i] > maxNum) {
			smallList[i].push_back(maxNum);
			maxNum = num[i];
			maxIndex = i;
		} else {
			smallList[maxIndex].push_back(num[i]);
		}
	}
	
	int sec = -1;
	list<int>::iterator it;
	for(it = smallList[maxIndex].begin(); it != smallList[maxIndex].end(); ++it)
		sec = max(sec, *it);
	cout << "The second largest num is " << sec << endl;
}

int main() {
	int n = 7;
	int num[] = {16, 8, 24, 9, 23, 73, 55};
	findSecondMax(num, n);

	return 0;
} 
