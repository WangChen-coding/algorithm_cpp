#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//设置尝试函数
//cur为当前位置
//rest 为剩余步数
//N为路径长度
//aim为目标位置
int process(int cur, int rest, int N, int aim) {
	if (rest == 0) {
		return cur == aim ? 1 : 0;
	}
	if (cur == 1) {
		return process(2, rest - 1, N, aim);
	}
	if (cur == N) {
		return process(N - 1, rest - 1, N, aim);
	}
	return process(cur - 1, rest - 1, N, aim) + process(cur + 1, rest - 1, N, aim);
}
//暴力递归法
int way1(int N, int start, int aim, int K) {
	if (start<1 || start>N || aim<1 || aim>N || K < 1 || N < 2) {
		return -1;
	}
	return process(start, K, N, aim);
}

int process1(int cur, int rest, int N, int aim, vector<vector<int>>& dp) {
	if (dp[cur][rest] != -1) {
		return dp[cur][rest];
	}
	int ans = 0;
	if (rest == 0) {
		ans = cur == aim ? 1 : 0;
	}
	else if (cur == 1) {
		ans = process1(2, rest - 1, N, aim, dp);
	}
	else if (cur == N) {
		ans = process1(N - 1, rest - 1, N, aim, dp);
	}
	else {
		ans = process1(cur - 1, rest - 1, N, aim, dp) + process1(cur + 1, rest - 1, N, aim, dp);
	}
	dp[cur][rest] = ans;
	return ans;
}
//傻缓存法
int way2(int N, int start, int aim, int K) {
	if (start<1 || start>N || aim<1 || aim>N || K < 1 || N < 2) {
		return -1;
	}
	vector<vector<int>>dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = -1;
		}
	}
	return process1(start, K, N, aim, dp);
}
int way3(int N, int start, int aim, int K) {
	if (start<1 || start>N || aim<1 || aim>N || K < 1 || N < 2) {
		return -1;
	}
	vector<vector<int>>dp(N + 1, vector<int>(K + 1, 0));
	dp[aim][0] = 1;
	for (int rest = 1; rest <= K; rest++) {
		dp[1][rest] = dp[2][rest - 1];
		for (int cur = 2; cur < N; cur++) {
			dp[cur][rest] = dp[cur - 1][rest - 1] + dp[cur + 1][rest - 1];
		}
		dp[N][rest] = dp[N - 1][rest - 1];
	}
	return dp[start][K];
}
int main(int argc, char** argv) {
	cout << way1(5, 2, 4, 6) << endl;
	cout << way2(5, 2, 4, 6) << endl;
	cout << way3(5, 2, 4, 6) << endl;
	return 0;
}



