#include <iostream>
#include<vector>
using namespace std;
int process(vector<int>& arr, int index, int rest) {
	if (index == arr.size()) {
		return rest == 0 ? 0 : INT_MAX;
	}
	else {
		int ans = INT_MAX;
		for (int zhang = 0; zhang * arr[index] <= rest; zhang++) {
			int next = process(arr, index + 1, rest - zhang * arr[index]);
			if (next != INT_MAX) {
				ans = min(ans, zhang + next);
			}
		}
		return ans;
	}
}
int mincoin(vector<int>& arr, int aim) {
	return process(arr, 0, aim);
}
int dp(vector<int>& arr, int aim) {
	if (aim == 0) {
		return 0;
	}
	int N = arr.size();
	vector<vector<int>>dp(N + 1, vector<int>(aim + 1, 0));
	dp[N][0] = 0;
	for (int j = 1; j <= aim; j++) {
		dp[N][j] = INT_MAX;
	}
	for (int index = N - 1; index >= 0; index--) {
		for (int rest = 0; rest <= aim; rest++) {
			int ans = INT_MAX;
			for (int zhang = 0; zhang * arr[index]<=rest; zhang++) {
				int next = dp[index + 1][rest - zhang * arr[index]];
				if (next != INT_MAX) {
					ans = min(ans, zhang+next);
				}
			}
			dp[index][rest] = ans;
		}
	}
	return dp[0][aim];
}
int dp2(vector<int>& arr, int aim) {
	if (aim == 0) {
		return 0;
	}
	int N = arr.size();
	vector<vector<int>>dp(N + 1, vector<int>(aim + 1, 0));
	dp[N][0] = 0;
	for (int j = 1; j <= aim; j++) {
		dp[N][j] = INT_MAX;
	}
	for (int index = N - 1; index >= 0; index--) {
		for (int rest = 0; rest <= aim; rest++) {
			dp[index][rest] = dp[index + 1][rest];
			if (rest - arr[index] >= 0 && dp[index][rest - arr[index]] != INT_MAX) {
				dp[index][rest] = min(dp[index][rest], dp[index][rest - arr[index]] + 1);
			}
		}
	}
	return dp[0][aim];
}
int main()
{
	vector<int> arr = { 1,2,3,4 };
	cout << mincoin(arr, 9);
	cout << endl;
	cout << dp(arr, 9) << endl;
	cout << dp2(arr, 9) << endl;
}

