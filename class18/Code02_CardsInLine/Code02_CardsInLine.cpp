#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int processg(vector<int>&, int, int);
int processf(vector<int>& arr, int L, int R) {
	if (L == R) {
		return arr[L];
	}
	int p1 = arr[L] + processg(arr, L + 1, R);
	int p2 = arr[R] + processg(arr, L, R - 1);
	return max(p1, p2);
}
int processg(vector<int>& arr, int L, int R) {
	if (L == R) {
		return 0;
	}
	int p1 = processf(arr, L + 1, R);
	int p2 = processf(arr, L, R - 1);
	return min(p1, p2);
}
int way1(vector<int>& arr) {
	int L = 0;
	int R = arr.size() - 1;
	int first = processf(arr, L, R);
	int second = processg(arr, L, R);
	return max(first, second);
}

//int way2


int main(int argc, char** argv) {
	vector<int>arr = { 5, 7, 4, 5, 8, 1, 6, 0, 3, 4, 6, 1, 7 };
	cout << way1(arr) << endl;
	//cout << way2(arr) << endl;
	//cout << way3(arr)<<endl;
	return 0;
}



