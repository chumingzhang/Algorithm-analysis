#include <iostream>
#include<algorithm>
#include<vector>
using namespace std; 

struct Task {
	int spend;
	int limit;
}; 

bool cmp(Task a, Task b) {
	return a.limit < b.limit;
}

void greed(vector<Task> tasks) {
	sort(tasks.begin(), tasks.end(), cmp);
	int cur_time = tasks[0].spend;
	int temp = cur_time - tasks[0].limit;
	int index = 0; 
	for(int i = 1; i < tasks.size(); ++i) {
		cur_time += tasks[i].spend;
		if(cur_time - tasks[i].limit >= temp) {
			temp = cur_time - tasks[i].limit;
			index = i;
		}
	}
	cout << "最大延迟发生在sort后第 " << index + 1 << "个任务" <<endl;
	cout << "延迟为：" << temp << endl;
}

int main()
{
	vector<Task> tasks = {{5,10},{8,12},{4,15},{10,11},{3,20}};
    greed(tasks);
	return 0;
}
