#include <iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std; 

struct Edge {
	int v1;
	int v2;
	int w;
};

int n = 8;
int V[] = {1, 2, 3, 4, 5, 6, 7, 8}; //顶点
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
	
bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
	
void Kruskal() {
	vector<Edge> G;
	int minCost = 0;
	// 初始化G 
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1;  j < n; ++j) {
			int weight = E[i][j];
			if(weight != INT_MAX) {
				Edge *e = new Edge();
                e->v1 = i;
                e->v2 = j;
                e->w = weight;
                G.push_back(*e);
			}
		}
	}
	sort(G.begin(), G.end(), cmp);
//    cout << "Edges:" << endl;
//    for (vector<Edge>::iterator it = G.begin(); it != G.end(); ++it)
//        cout << V[it->v1] << "-" << V[it->v2] << " weight: " << it->w << endl;

	vector<int> Find(n); //Find[i]表示i的连通分支标记
    vector<int> BranchSize(n); //BranchSize[i]表示标记为i的连通分支节点数
    for (int i=0; i<n; i++) {
        Find[i] = i+1;
        BranchSize[i] = 1;
    }
    
    int count = 0;	//边数，判断退出循环 
    for(vector<Edge>::iterator it = G.begin(); count < n - 1 && it != G.end(); ++it) {
    	int m1 = Find[it->v1];
		int m2 = Find[it->v2];
		if(m1 != m2) {	//不再同一个连通分支 
			cout << "add edge: " << V[it->v1] << "-" << V[it->v2] << " weight: " << it->w << endl;
			minCost += it->w;
			if(BranchSize[m1] > BranchSize[m2]){ //使m2指示规模较大的分支
				int temp = m1;
				m1 = m2;
				m2 = temp;
			}
			
			for(int i = 0; i < n; ++i) { //将小分支合并到大分枝
				if(Find[i] == m1)
					Find[i] = m2;
			}
			
            BranchSize[m2] += BranchSize[m1];
            BranchSize[m1] = 0;
            count++;
		}
	}
	cout << "Min cost is: " << minCost << endl;
}

int main()
{
	Kruskal();
    return 0;
}
