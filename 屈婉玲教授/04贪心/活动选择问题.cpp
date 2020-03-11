#include <iostream>
#include<algorithm>
#include<vector>
using namespace std; 

struct Event {
	int start;
	int end;
};

bool cmp(Event a, Event b) {
	return a.end < b.end;
}

vector<Event> greed(vector<Event> events) {
	vector<Event> result;
	sort(events.begin(), events.end(), cmp);
	result.push_back(events[0]);
	int temp = events[0].end;
	for(int i = 1; i < events.size(); ++i) {
		if(events[i].start >= temp) {
			result.push_back(events[i]);
			temp = events[i].end;
		}
	}
	return result;
}

int main()
{
	vector<Event> events = {
			{1,4},{3,5},{2,6},{5,7},{4,9},
			{5,9},{6,10},{8,11},{8,12},{2,13}
		};
	vector<Event> ans = greed(events);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i].start << "-" << ans[i].end << endl;
    return 0;
}
