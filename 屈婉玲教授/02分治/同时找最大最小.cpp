#include<iostream>
#include<algorithm>
using namespace std;

//�����ȴ�С����С���ٺ͵�ǰ��Сֵ�ȣ��ϴ����ٺ͵�ǰ���ֵ�� 
//��nΪ�������ֿ�һ����ʣ��ÿ2��Ԫ�ر�3�Σ�һ����3n / 2 - 3��
//��nΪż������ʼֻ��1�Σ�ʣ��ÿ2��Ԫ�ر�3�Σ�һ��3n / 2 - 2��
//�����ܵ���˵����3n / 2 - 2��
void findMaxMin(int num[], int n, int &max_num, int &min_num) {
	if(n <= 0) {
		return;
	} else if(n == 1) {
		max_num = num[0];
		min_num = num[0];
		return;
	} else if(n % 2 != 0) {	//nΪ����ʱ�� ��ֵ��Ϊ���һ��Ԫ�� 
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
