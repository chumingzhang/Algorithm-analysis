//p25 ƽ��������
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<limits>
using namespace std;

struct Point {
	float x;
	float y;
	int index;
};

float Distance(Point p1, Point p2) {
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

//���պ���������
int QuickSortPartitionByX(Point s[], int l, int r){
    Point temp = s[l];
    while (l < r)
    {
        while(l < r && s[r].x >= temp.x)
            r--;
        if(l < r)
            s[l++] = s[r]; //ֱ���滻������Ԫ�أ�����temp�д��б��ݣ�
        while(l < r && s[l].x <= temp.x)
            l++;
        if(l < r)
            s[r--] = s[l];
    }
    s[l] = temp;  //l��λ�÷���temp����������඼С��temp���Ҳ඼����temp
    return l;
}
void QuickSortByX(Point s[], int l, int r)
{
    if (l>=r){
        return;
    }
    int i = QuickSortPartitionByX(s, l, r);
    QuickSortByX(s, l, i - 1);
    QuickSortByX(s, i + 1, r);
}

//��������������
int QuickSortPartitionByY(Point s[], int l, int r){
    Point temp = s[l];
    while (l < r)
    {
        while(l < r && s[r].y >= temp.y)
            r--;
        if(l < r)
            s[l++] = s[r]; //ֱ���滻������Ԫ�أ�����temp�д��б��ݣ�
        while(l < r && s[l].y <= temp.y)
            l++;
        if(l < r)
            s[r--] = s[l];
    }
    s[l] = temp;  //l��λ�÷���temp����������඼С��temp���Ҳ඼����temp
    return l;
}
void QuickSortByY(Point s[], int l, int r)
{
    if (l>=r){
        return;
    }
    int i = QuickSortPartitionByY(s, l, r);
    QuickSortByY(s, l, i - 1);
    QuickSortByY(s, i + 1, r);
}

float MinDistanceRecur(Point *PX, int l, int r, Point *PY, int totalNum) {
	int n = r + l - 1;
	float delta = numeric_limits<float>::max(); //delta��Ϊ����float, ��Ҫ#include<limits>
	if(n < 2)
		return delta;//�˴�ȡ���ֵ������ʣ1����ʱ���ٸ�����̾���
	//3����ֱ���� 
	if(n <= 3) {
		for(int i = l; i <= r; ++i) {
			for(int j = i + 1; j <= r; ++j) {
				delta = min(Distance(PX[i], PX[j]), delta);
			}
		} 
		return delta;
	}
	
	//��P���ƻ���Ϊ��С��ȵ������֣��ݹ������������
    float minLeft = MinDistanceRecur(PX, l, n / 2, PY, n);
    float minRight = MinDistanceRecur(PX, n / 2 + 1, r, PY, n);
    delta = min(minLeft, minRight);
    
    //���߽�����������,�ҳ��߽���mid����delta��Χ��խ���еĵ�
    float mid = (PX[n / 2].x + PX[n / 2 + 1].x) / 2;
    //����������ߵĿ��ڵ� 
	vector<int> leftStripPoints;
    vector<int> rightStripPoints;
    for (int i = n / 2; (mid - PX[i].x) < delta && i >= l; --i)
        leftStripPoints.push_back(PX[i].index);
        
	for (int i = n / 2 + 1; (PX[i].x - mid) < delta && i <= r; ++i)
   	    rightStripPoints.push_back(PX[i].index);
   	    
   	//��y������Ӵ�Сɨ�裬�˴���ʼʹ��PY
	for(int i = totalNum - 1; i >= 0; --i) {
		if (find(rightStripPoints.begin(), rightStripPoints.end(), PY[i].index)!=rightStripPoints.end()){
            //������������Сdelta֮�ڣ����������ߵĵ㣬������̾���
            for (int j=i-1; (j>=0 && (PY[i].y-PY[j].y)<delta && (find(leftStripPoints.begin(), leftStripPoints.end(), PY[j].index)!=leftStripPoints.end())); j--){
                delta = min(delta, Distance(PY[i], PY[j]));
            }
        }
        
        //���ĳ������������խ��
        if (find(leftStripPoints.begin(), leftStripPoints.end(), PY[i].index)!=leftStripPoints.end()){
            //������������Сdelta֮�ڣ��������Ұ�ߵĵ㣬������̾���
            for (int j=i-1; (j>=0 && (PY[i].y-PY[j].y)<delta && (find(rightStripPoints.begin(), rightStripPoints.end(), PY[j].index)!=rightStripPoints.end())); j--){
                delta = min(delta, Distance(PY[i], PY[j]));
            }
        }
	}
	return delta;
} 

float MinDistance(Point P[], int l, int r) {
	//Ԥ�������Ƴ����������ݣ�
	//�ֱ�x��y�������򣬿ɽ����ӶȽ���O(nlogn)
    //���ÿ�εݹ鶼�������򣬸��ӶȽ���O(n(logn)^2)
    int totalNum = r - l + 1;
    Point *PX = new Point[totalNum];
    memcpy(PX, P, totalNum *sizeof(Point));
    Point *PY = new Point[totalNum];
    memcpy(PY, P, totalNum *sizeof(Point));
    float minDistance = MinDistanceRecur(PX, l, r, PY, totalNum);
    delete[] PX;
    delete[] PY;
    return minDistance;
}


int main() {
	int n = 4;
	Point points[] = {{0.5, 2}, {2, 3}, {-2, 4}, {1, -1}};
	for(int i = 0; i < n; ++i)
		points[i].index = i;
		
	for (int i=0; i<n; i++){
        cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
    }
    
    float minDistance = MinDistance(points, 0, n - 1);
    cout << "min distance is :" << minDistance << endl;
	return 0;
} 
