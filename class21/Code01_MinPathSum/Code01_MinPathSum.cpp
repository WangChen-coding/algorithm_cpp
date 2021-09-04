#include <iostream>
#include<string>
#include<vector>
using namespace std;
int minPathSum1(vector<vector<int>>& m) {
    if (m.size() == 0 || m[0].size() == 0) {
        return 0;
    }
    int row = m.size();
    int col = m[0].size();
    vector<vector<int>>dp(row, vector<int>(col, 0));
    dp[0][0] = m[0][0];
    for (int i = 1; i < row; i++) {
        dp[i][0] = m[i][0] + dp[i - 1][0];
    }
    for (int j = 1; j < col; j++) {
        dp[0][j] = m[0][j] + dp[0][j - 1];
    }
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            dp[i][j] = m[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[row - 1][col - 1];
}
int minPathSum2(vector<vector<int>>& m) {
    if (m.size() == 0 || m[0].size() == 0) {
        return 0;
    }
    int row = m.size();
    int col = m[0].size();
    vector<int>dp(col,0);
    dp[0] = m[0][0];
    for (int j = 1; j < col; j++) {
        dp[j] = dp[j - 1] + m[0][j];
    }
    for (int i = 1; i < row; i++) {
        dp[0] = m[i][0] + dp[0];
        for (int j = 1; j < col; j++) {
            dp[j] = min(dp[j - 1], dp[j]) + m[i][j];
        }
    }
    return dp[col - 1];
}

int main()
{
    vector<vector<int>>m = { {1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0} };
    cout << minPathSum1(m) << endl;
    cout << minPathSum2(m) << endl;
    return 0;
}




