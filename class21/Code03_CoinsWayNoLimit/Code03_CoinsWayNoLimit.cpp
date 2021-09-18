#include <iostream>
#include<string>
#include<vector>
using namespace std;

int process(vector<int>& arr, int index, int rest) {
	if (index == arr.size()) {
		return rest == 0 ? 1 : 0;
	}
	int ways = 0;
	for (int zhang = 0; zhang * arr[index] <= rest; zhang++) {
		ways += process(arr, index + 1, rest - zhang * arr[index]);
	}
	return ways;
}
int coinway(vector<int>& arr, int aim) {
	return process(arr, 0, aim);
}


int coinway2(vector<int>& arr, int aim) {
	int N = arr.size();
	vector<vector<int>>dp(N + 1, vector<int>(aim + 1, 0));
}

int main()
{
	vector<int>m = { 1,3,1,9,8,1,3,4,5,2,6,1,8,8,4,8 };
	cout << coinway(m, 10) << endl;
	cout << coinway(m, 10) << endl;
	return 0;
}


