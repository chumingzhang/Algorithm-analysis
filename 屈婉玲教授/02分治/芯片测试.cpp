#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Chip {
	int index;	
	int state;	//0-��  1-�� 
};

// оƬ����(j �� i ���в���)
int test(int i, int j) {
	if(j == 1)
		return i;
	else
		return rand() % 2; 
} 

// �����㷨
//�������ԣ������Ϊ�õģ����û򶼻��������ζ�һ����
//����������һ�����ģ�ȫ����
//�������Ա�֤ÿ�����ٶ�һ�����Ҳ�ͬʱ���������õģ�
//��֤ʣ�µ���Ȼ�õ�ռ��������
int find(vector<Chip> chips) {
	int n = chips.size();
	if(n < 3)
		return (chips.begin())->index; 
		
	vector<Chip>::iterator it1;
	vector<Chip>::iterator it2;
	if(n == 3) {
		it1 = chips.begin();
		it2 = chips.begin();
		it2++;
		if(test(it1->state, it2->state) && test(it2->state, it1->state))
			return it1->index;
		else
			return chips.end()->index;
	}
	
	//��nΪ����ʱ�������ж��ֿյ����һ��,�ο��ؼ�����1
    //�Ǻõģ���������ǻ��ģ���ȥ��
	if(n % 2 != 0) {
		it1 = chips.begin();
		// it2 = chips.end() 	����ָ��ĩβ�գ����������һ��Ԫ�� 
		it2 = chips.begin();
		for(int i = 0; i < n - 1; ++i)
			it2++;
			
		int count = 0;
		// �����һƬоƬ���в��� 
		for(int i = 0; i < n; ++i) {
			if(it1 != it2)
				count += test(it2->state, it1->state);
			it1++;
		}
		if(count >= n / 2)	//Ϊ�� 
			return it2->index;
		else {
			chips.pop_back();
			n--;
		}	
	}
//	for(int i = 0; i < chips.size(); ++i) {
//		cout << chips.at(i).index << "  11111  " << chips.at(i).state << endl;
//	}
	
	// ����һ�����
	it1 = chips.begin();	//����it1 
	for(int i = 0; i < n / 2; ++i) {
		it2 = it1;
		it2++;
		
		int r1 = test(it1->state, it2->state);
		int r2 = test(it2->state, it1->state);
//		cout << r1 << "  " << r2 << endl;
		if(r1 && r2) {
			chips.erase(it2);	//ɾ����ָ���Զ�ǰ�� 
			it1++;	
		} else {
			it2++;
			chips.erase(it1, it2); //erase���÷�ΧΪ [first,last)  ɾ����ָ���Զ�ǰ��
		}
		
//		for(int j = 0; j < chips.size(); ++j) {
//			cout << chips.at(j).index << " " << chips.at(j).state << endl;
//		}
	}
//	cout << "  ---------------------  " << endl;
	return find(chips);	//�ݹ�ʣ�µ� 
}


int main() {
	int n;
	cin >> n;
	vector<Chip> chips(n);
	vector<Chip>::iterator it;
	for(int i = 0; i < n; ++i) {
		chips.at(i).index = i + 1;
		cin >> chips.at(i).state;
	}
	
//	for(int i = 0; i < n; ++i) {
//		cout << chips.at(i).index << " " << chips.at(i).state << endl;
//	}
	cout << find(chips) << endl; 
}
 

//�����㷨
//int rough(vector<int> chips, int n) {
//	int large_bound, low_bound;
//	if(n % 2 != 0) {
//		large_bound = (n - 1) / 2;
//		low_bound = (n + 1) / 2;
//	} else {
//		large_bound = n / 2;
//		low_bound = n / 2 + 1;
//	}
//	
//	for(int i = 0; i < n; ++i) {
//		int good = 0, bad = 0;
//		for(int j = 0; j < n; ++j) {
//			if(i != j) {
//				if(test(chips.at(i), chips.at(j)) == 1)
//					good++;
//				else
//					bad++;
//				// �ҵ���оƬ 
//				if(good >= large_bound)
//					return i;			
//			}
//		}
//	}
//} 
//
//int main() {
//	int n = 7;
//	// 0-�� 1-�� 
//	vector<int> chips;
//	int temp;
//	for(int i = 0; i < n; ++i) {
//		cin >> temp;
//		chips.push_back(temp);
//	}
//	int index = rough(chips, n);
//	cout << index;
//	return 0;
//} 
