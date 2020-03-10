// ººÅµËþ

#include<iostream>
using namespace std;

void Hanoi(char A, char B, char C, int n) {
	if(n == 1) {
		cout << "move from " << A << " to " << C << endl;
		return;
	}
	Hanoi(A, C, B, n - 1);
	cout << "move from " << A << " to " << C << endl;
	Hanoi(B, A, C, n - 1);
}

int main() {
	int n;
	cin >> n;
	char A = 'A', B = 'B', C = 'C';
	Hanoi(A, B, C, n);
	return 0;
} 
