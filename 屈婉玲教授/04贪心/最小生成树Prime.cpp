#include <iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std; 

int n = 8;
int V[] = {1, 2, 3, 4, 5, 6, 7, 8}; //¶¥µã
int E[][8] = {
		{INT_MAX, 2, 3, INT_MAX, INT_MAX, INT_MAX,INT_MAX,INT_MAX},
        {2, INT_MAX, 4, 18, INT_MAX, INT_MAX, 7, INT_MAX},
        {3, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 8},
        {INT_MAX, 18, INT_MAX, INT_MAX, 5, 3, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, 4, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 3, 4, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1},
        {INT_MAX, INT_MAX, 8, INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX}
	};
	
bool notInV(int v, vector<int> add_v) {
	for(int i = 0; i < add_v.size(); ++i) {
		if(v == add_v[i])
			return false;
	}
	return true;
}
	
void Prime() {
	vector<int> add_v;
	add_v.push_back(V[0]);
	cout << "add vertex: " << V[0] << endl;
	vector<int> add_e;
	int total = 0;
	while(add_e.size() < n - 1) {
		int first_v;
		int to_add;
		int temp = INT_MAX;
		for(int i = 0; i < add_v.size(); ++i) {
			for(int j = 0; j < n; ++j) {
				if(notInV(j + 1, add_v) && temp > E[add_v[i] - 1][j]) {
					temp = E[add_v[i] - 1][j];
					to_add = j + 1;
					first_v = add_v[i];
				}
			}
		}
		cout << "add vertex: " << to_add << endl;
        cout << "add edge: " << first_v << "-" << to_add << " length: " << temp << endl;
        total += temp;
		add_v.push_back(to_add);
		add_e.push_back(temp);
	}
	cout << "Min cost is: " << total << endl;
}

int main()
{
	Prime();
    return 0;
}
