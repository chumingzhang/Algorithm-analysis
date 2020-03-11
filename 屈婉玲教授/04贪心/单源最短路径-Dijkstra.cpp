#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include<algorithm>
using namespace std;

int n = 6;
vector<int> V = {1, 2, 3, 4, 5, 6};
vector<vector<int> > E = {
		{0, 10, INT_MAX, INT_MAX, INT_MAX, 3},
        {INT_MAX, 0, 7, 5, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX},
        {3, INT_MAX, 4, 0, 7, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX},
        {INT_MAX, 2, INT_MAX, 6, 1, 0}
	};
	
bool notInTempV(int v, vector<int> add_v) {
	for(int i = 0; i < add_v.size(); ++i) {
		if(v == add_v[i])
			return false;
	}
	return true;
}
	
vector<int> Dijkstra(int s) {
	vector<int> result;
	for(int i = 0; i < n; ++i)
		result.push_back(INT_MAX);
	
	vector<int> tempV;
	tempV.push_back(s + 1);
	while(tempV.size() < n) {
		//更新到每个顶点的最短边 
		int curV = tempV[tempV.size() - 1] - 1;	//最新的顶点的下标 
		for(int j = 0; j < n; ++j) {
			if(curV == s && E[curV][j] < result[j]) {
				cout << E[curV][j] << " 111" << endl;
				result[j] = E[curV][j];
			} else if(curV != s && E[curV][j] != INT_MAX && E[curV][j] + result[curV] < result[j]) {
				cout << E[curV][j] + result[curV] << " 222" << endl;
				result[j] = E[curV][j] + result[curV];
			}
		}
		
		//选择最小的作为新顶点添加进temp_v
		int toAdd;
		int minLen = INT_MAX;
		for(int i = 0; i < n; ++i) {
			if(notInTempV(i + 1, tempV) && result[i] < minLen) {
				minLen = result[i];
				toAdd = i; 
			}
		}
		cout << toAdd << endl;
		tempV.push_back(toAdd + 1);
	}
	return result;
}

int main() {
	int s = 0;	//源节点下标
	vector<int> dist = Dijkstra(s);
    cout << "Min distance is: " << endl;
    for (int i = 0; i < n; ++i)
       cout << V[s] << "->" << V[i] << ": " << dist[i] << endl;

	return 0;
}
