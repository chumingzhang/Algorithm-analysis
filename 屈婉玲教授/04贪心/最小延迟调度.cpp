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
	cout << "����ӳٷ�����sort��� " << index + 1 << "������" <<endl;
	cout << "�ӳ�Ϊ��" << temp << endl;
}

int main()
{
	vector<Task> tasks = {{5,10},{8,12},{4,15},{10,11},{3,20}};
    greed(tasks);
	return 0;
}
