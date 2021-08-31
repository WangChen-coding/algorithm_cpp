#include <iostream>
#include<string>
#include<vector>
using namespace std;
int process1(string& str, int L, int R) {
	if (L == R) {
		return 1;
	}
	if (L == R - 1) {
		return str[L] == str[R] ? 2 : 1;
	}
	int p1 = process1(str, L + 1, R - 1);
	int p2 = process1(str, L, R - 1);
	int p3 = process1(str, L + 1, R);
	int p4 = str[L] == str[R]?2+process1(str, L+1, R-1):0;
	return max(max(p1, p2), max(p3, p4));
}

//61 / 86 个通过测试用例
int way1(string& str) {
	return process1(str, 0, str.size() - 1);
}
int way2(string& str) {
	int N = str.size();
	vector<vector<int>>dp(N, vector<int>(N, 0));
	dp[N - 1][N - 1] = 1;
	for (int i = 0; i < N-1; i++) {
		dp[i][i] = 1;
		dp[i][i + 1] = str[i] == str[i + 1] ? 2 : 1;
	}
	for (int L = N - 3; L >= 0; L--) {
		for (int R = L + 2; R < N; R++) {
			dp[L][R]= max(dp[L][R - 1], dp[L + 1][R]);
			if (str[L] == str[R]) {
				dp[L][R] = max(dp[L][R], 2 + dp[L + 1][R - 1]);
			}
		}
	}
	return dp[0][N - 1];
}

int main()
{
	std::cout << "Hello World!\n";
}


