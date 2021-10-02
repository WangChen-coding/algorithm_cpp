#include <iostream>
#include<map>
#include<vector>
using namespace std;

int process(vector<int>&coins,vector<int>&zhangs, int index, int rest) {
	if (index == zhangs.size()) {
		return rest == 0 ? 1 : 0;
	}
	int ways = 0;
	for (int zhang = 0; zhang * coins[index] <= rest && zhang <= zhangs[index]; zhang++) {
		ways += process(coins, zhangs, index + 1, rest - zhang * coins[index]);
	}
	return ways;
}
int coinway(vector<int>& arr, int aim) {
	map<int, int>counts;
	for (auto i : arr) {
		if (counts.find(i) != counts.end()) {
			counts[i]++;
		}
		else {
			counts[i] = 1;
		}
	}
	int N = counts.size();
	vector<int>coins;
	vector<int>zhang;
	for (auto i : counts) {
		coins.push_back(i.first);
		zhang.push_back(i.second);
	}
	return process(coins,zhang, 0, aim);
}

int dp1(vector<int>& arr, int aim) {
	map<int, int>counts;
	for (auto i : arr) {
		if (counts.find(i) != counts.end()) {
			counts[i]++;
		}
		else {
			counts[i] = 1;
		}
	}
	int N = counts.size();
	vector<int>coins;
	vector<int>zhangs;
	for (auto i : counts) {
		coins.push_back(i.first);
		zhangs.push_back(i.second);
	}
	vector<vector<int>>dp(N + 1, vector<int>(aim + 1, 0));
	dp[N][0] = 1;
	for (int index = N - 1; index >= 0; index--) {
		for (int rest = 0; rest <= aim; rest++) {
			int ways = 0;
			for (int zhang = 0; zhang * coins[index] <= rest && zhang <= zhangs[index]; zhang++) {
				ways += dp[index + 1][rest - zhang * coins[index]];
			}
			dp[index][rest] = ways;
		}
	}
	return dp[0][aim];
}
int dp2(vector<int>& arr, int aim) {
	map<int, int>counts;
	for (auto i : arr) {
		if (counts.find(i) != counts.end()) {
			counts[i]++;
		}
		else {
			counts[i] = 1;
		}
	}
	int N = counts.size();
	vector<int>coins;
	vector<int>zhangs;
	for (auto i : counts) {
		coins.push_back(i.first);
		zhangs.push_back(i.second);
	}
	vector<vector<int>>dp(N + 1, vector<int>(aim + 1, 0));
	dp[N][0] = 1;
	for (int index = N - 1; index >= 0; index--) {
		for (int rest = 0; rest <= aim; rest++) {
			dp[index][rest] = dp[index + 1][rest];
			if (rest - coins[index] >= 0) {
				dp[index][rest] += dp[index][rest - coins[index]];
			}
			if(rest-coins[index]*(zhangs[index]+1)>=0) {
				dp[index][rest] -= dp[index + 1][rest - coins[index] * (zhangs[index] + 1)];
			}
		}
	}
	return dp[0][aim];
}

int main()
{
	vector<int>m = { 1,3,1,9,8,1,3,4,5,2,6,1,8,8,4,8 };
	cout<<coinway(m, 30)<<endl;
	cout << dp1(m, 20)<<endl;
	cout << dp2(m, 20) << endl;
}

