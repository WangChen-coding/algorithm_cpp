#include <iostream>
#include<vector>
using namespace std;

int process(vector<int>& weight, vector<int>& value, int index, int rest) {
	if (rest < 0) {
		return -1;
	}
	if (index == weight.size()) {
		return 0;
	}

	int p1 = process(weight, value, index + 1, rest);
	int p2 = 0;
	int next = process(weight, value, index + 1, rest - weight[index]);
	if (next != -1) {
		p2 = value[index] + next;
	}
	return max(p1, p2);
}
int way1(vector<int>& weight, vector<int>& value, int bag) {

	return process(weight, value, 0, bag);
}

int way2(vector<int>& weight, vector<int>& value, int bag) {
	int N = weight.size();
	vector<vector<int>>dp(N + 1, vector<int>(bag + 1, 0));
	for (int index = N - 1; index >= 0; index--) {
		for (int rest = 0; rest <= bag; rest++) {
			int p1 = dp[index + 1][rest];
			int p2 = 0;
			int next = (rest - weight[index]) < 0 ? -1 : dp[index + 1][rest - weight[index]];
			if (next != -1) {
				p2 = value[index] + next;
			}
			dp[index][rest] = max(p1, p2);
		}
	}
	return dp[0][bag];
}

//¸´Ï°²âÊÔ´úÂë
int testprocess(vector<int>& weights, vector<int>& values, int index, int rest) {
	if (rest < 0) {
		return -1;
	}
	if (index == weights.size()) {
		return 0;
	}
	int p1 = testprocess(weights, values, index + 1, rest);
	int p2 = 0;
	int next = testprocess(weights, values, index + 1, rest - weights[index]);
	if (next != -1) {
		p2 = values[index] + next;
	}
	return max(p1, p2);
}
int testways(vector<int>& weights, vector<int>& values, int bag) {
	return testprocess(weights, values, 0, bag);
}




int main()
{
	vector<int>weight = { 3, 2, 4, 7, 3, 1, 7 };
	vector<int>value = { 5, 6, 3, 19, 12, 4, 2 };
	int bag = 15;
	cout << way1(weight, value, 15) << endl;
	cout << way2(weight, value, 15) << endl;
	cout << testways(weight, value, 15) << endl;
	return 0;
}


