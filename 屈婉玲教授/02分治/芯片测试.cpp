#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Chip {
	int index;	
	int state;	//0-坏  1-好 
};

// 芯片测试(j 对 i 进行测试)
int test(int i, int j) {
	if(j == 1)
		return i;
	else
		return rand() % 2; 
} 

// 分治算法
//两两测试，如果均为好的（都好或都坏），则任丢一个；
//否则（至少有一个坏的）全丢掉
//这样可以保证每次至少丢一个，且不同时丢掉两个好的；
//保证剩下的仍然好的占半数以上
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
	
	//当n为奇数时，单独判断轮空的最后一个,参考关键结论1
    //是好的，则结束；是坏的，则去掉
	if(n % 2 != 0) {
		it1 = chips.begin();
		// it2 = chips.end() 	错误，指向末尾空，而不是最后一个元素 
		it2 = chips.begin();
		for(int i = 0; i < n - 1; ++i)
			it2++;
			
		int count = 0;
		// 对最后一片芯片进行测试 
		for(int i = 0; i < n; ++i) {
			if(it1 != it2)
				count += test(it2->state, it1->state);
			it1++;
		}
		if(count >= n / 2)	//为真 
			return it2->index;
		else {
			chips.pop_back();
			n--;
		}	
	}
//	for(int i = 0; i < chips.size(); ++i) {
//		cout << chips.at(i).index << "  11111  " << chips.at(i).state << endl;
//	}
	
	// 两两一组测试
	it1 = chips.begin();	//重置it1 
	for(int i = 0; i < n / 2; ++i) {
		it2 = it1;
		it2++;
		
		int r1 = test(it1->state, it2->state);
		int r2 = test(it2->state, it1->state);
//		cout << r1 << "  " << r2 << endl;
		if(r1 && r2) {
			chips.erase(it2);	//删除后指针自动前移 
			it1++;	
		} else {
			it2++;
			chips.erase(it1, it2); //erase作用范围为 [first,last)  删除后指针自动前移
		}
		
//		for(int j = 0; j < chips.size(); ++j) {
//			cout << chips.at(j).index << " " << chips.at(j).state << endl;
//		}
	}
//	cout << "  ---------------------  " << endl;
	return find(chips);	//递归剩下的 
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
 

//蛮力算法
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
//				// 找到好芯片 
//				if(good >= large_bound)
//					return i;			
//			}
//		}
//	}
//} 
//
//int main() {
//	int n = 7;
//	// 0-坏 1-好 
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
