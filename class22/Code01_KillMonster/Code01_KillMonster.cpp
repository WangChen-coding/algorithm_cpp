
#include <iostream>
#include<vector>
using namespace std;
int process(int rest, int hp, int M) {
	if (rest == 0) {
		return hp <= 0 ? 1 : 0;
	}
	if (hp <= 0) {
		return pow(M + 1, rest);
	}
	int ways = 0;
	for (int i = 0; i < M + 1; i++) {
		ways += process(rest - 1, hp - i, M);
	}
	return ways;
}
double right(int K, int N, int M) {
	if (N < 1 || M < 1 || K < 1) {
		return 0;
	}
	long all = pow(M + 1, K);
	long result = process(K, N, M);
	cout << all << endl;
	cout << result << endl;
	return static_cast<double>(result) / static_cast<double>(all);
}

double dp(int K, int N, int M) {
	if (K < 1 || N < 1 || M < 1) {
		return 0;
	}
	vector<vector<int>>dp(K + 1, vector<int>(N + 1, 0));
	dp[0][0] = 1;
	for (int rest = 1; rest <= K; rest++) {
		dp[rest][0] = pow(M + 1, rest);
		for (int hp = 1; hp <= N; hp++) {
			long ways = 0;
			for (int i = 0; i <= M; i++) {
				if (hp - i >= 0) {
					ways += dp[rest - 1][hp - i];
				}
				else {
					ways += pow(M + 1, rest - 1);
				}
			}
			dp[rest][hp] = ways;
		}
	}
	long all = pow(M + 1, K);
	cout << all << endl;
	cout << dp[K][N] << endl;
	return static_cast<double>(dp[K][N]) / static_cast<double>(all);
}

int main()
{
	cout << right(10, 20, 3) << endl;
	cout << dp(10, 20, 3) << endl;

}

