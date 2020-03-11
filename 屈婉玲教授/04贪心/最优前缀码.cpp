#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

int result;

struct Node {
	char ch;		//对应字符
	int freq;		//频率
	Node *left;
	Node *right; 
};

bool cmp(Node a, Node b) {
	return a.freq < b.freq;
}

void print(Node *root, string s) {
	if(root->left == NULL) {
		cout << root->ch << ": " << s << endl;
		result += root->freq * s.length();
	} else {
		print(root->left, s + "0");
		print(root->right, s + "1");
	}
}

void greed(vector<Node> nodes) {
	vector<Node>::iterator it1 = nodes.begin();
	vector<Node>::iterator it2 = nodes.begin();
	it2++;
	int result = 0;
	while(nodes.size() > 1) {
		sort(nodes.begin(), nodes.end(), cmp);
		Node *n1 = new Node(*it1);
		Node *n2 = new Node(*it2);
//		cout << n1->freq << " " << n2->freq << endl;
		Node temp = {'N', (*it1).freq + (*it2).freq};
		temp.left = n1;
		temp.right = n2;
		
		nodes.erase(it1);	//指针自动前移 
		nodes.erase(it1);
		nodes.insert(it1, temp); 
	}
	Node *root = &(*nodes.begin());
	print(root, "");
}

int main()
{
	vector<Node> nodes = {
			{'A', 45}, {'B', 13}, {'C', 12}, {'D', 16}, {'E', 9}, {'F', 5}
		};
	greed(nodes);
	cout << result << endl;
    return 0;
}
