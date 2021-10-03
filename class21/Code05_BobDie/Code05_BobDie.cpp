#include <iostream>
#include<vector>
#include<cmath>
using namespace std;



double process(int row, int col, int rest, int N, int M) {
	if (row < 0 || row == N || col < 0 || col == M) {
		return 0;
	}
	if (rest == 0) {
		return 1;
	}
	long up = process(row - 1, col, rest - 1, N, M);
	long down = process(row + 1, col, rest - 1, N, M);
	long left = process(row, col - 1, rest - 1, N, M);
	long right = process(row, col + 1, rest - 1, N, M);
	return up + down + left + right;
}
double livePosibility1(int row, int col, int k, int N, int M)
{
	cout << process(row, col, k, N, M) << endl;
	return  process(row, col, k, N, M) / pow(4, k);
}
int pick(vector<vector<vector<double>>>& dp, int N, int M, int r, int c, int rest) {
	if (r < 0 || r == N || c < 0 || c == M) {
		return 0;
	}
	return dp[rest][r][c];
}

double livePosibility2(int row, int col, int k, int N, int M)
{
	vector<vector<vector<double>>>dp(k + 1, vector < vector<double>>(N, vector<double>(M, 0)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dp[0][i][j] = 1;
		}
	}
	for (int rest = 1; rest <= k; rest++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dp[rest][i][j] = pick(dp, N, M, i - 1, j, rest - 1);
				dp[rest][i][j] += pick(dp, N, M, i + 1, j, rest - 1);
				dp[rest][i][j] += pick(dp, N, M, i, j - 1, rest - 1);
				dp[rest][i][j] += pick(dp, N, M, i, j + 1, rest - 1);
			}
		}
	}
	cout << dp[k][row][col] << endl;
	return static_cast<double>(dp[k][row][col]) / pow(4, k);
}

int main()
{
	cout << livePosibility1(6, 6, 10, 50, 50) << endl;
	cout << livePosibility2(6, 6, 10, 50, 50) << endl;
}
