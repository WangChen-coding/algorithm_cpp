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
	dp[N][0] = 1;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j <= aim; j++) {
			int ways = 0;
			for (int zhang = 0; zhang * arr[i] <= j; zhang++) {
				ways += dp[i + 1][j - (zhang * arr[i])];
			}
			dp[i][j] = ways;
		}
	}
	return dp[0][aim];
}
int coinway3(vector<int>& arr, int aim) {
	int N = arr.size();
	vector<vector<int>>dp(N + 1, vector<int>(aim + 1, 0));
	dp[N][0] = 1;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j <= aim; j++) {
			dp[i][j] = dp[i + 1][j];
			if (j - arr[i] >= 0) {
				dp[i][j] += dp[i][j - arr[i]];
			}
		}
	}
	return dp[0][aim];
}

int main()
{
	vector<int>m = { 1,3,1,9,8,1,3,4,5,2,6,1,8,8,4,8 };
	cout << coinway(m, 10) << endl;
	cout << coinway2(m, 10) << endl;
	cout << coinway3(m, 10) << endl;
	return 0;
}


