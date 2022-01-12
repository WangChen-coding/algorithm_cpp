#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int maxcover1(vector<vector<int>>& lines) {
	int mi = INT_MAX;
	int ma = INT_MIN;
	for (int i = 0; i < lines.size(); i++) {
		mi = min(mi, lines[i][0]);
		ma = max(ma, lines[i][1]);
	}
	int cover = 0;
	for (double p = mi + 0.5; p < ma; p++) {
		int cur = 0;
		for (int i = 0; i < lines.size(); i++) {
			if (lines[i][0]<p && lines[i][1]>p) {
				cur++;
			}
		}
		cover = max(cover, cur);
	}
	return cover;
}
struct line {
	int start;
	int end;
};

bool cmp(const line& l1, const line& l2) {
	return l1.start < l2.start;
}

int maxcover2(vector<vector<int>>& lines) {
	vector<line> li(lines.size());
	for (int i = 0; i < lines.size();i++) {
		li[i].start = lines[i][0];
		li[i].end = lines[i][1];
	}
	sort(li.begin(), li.end(), cmp);
	priority_queue<int,vector<int>,greater<int>>heap;
	int ma = 0;
	for (int i = 0; i < li.size(); i++) {
		while (!heap.empty() && heap.top() <= li[i].start) {
			heap.pop();
		}
		heap.push(li[i].end);
		int N = heap.size();
		ma = max(ma, N);
	}
	return ma;
}
int main()
{
	vector<vector<int>>arr = { {1,2},{1,3},{2,4},{2,5} };
	cout << maxcover2(arr) << endl;
	std::cout << "Hello World!\n";
}

