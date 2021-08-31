#include <iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int process1(string& str1, string& str2, int i, int j) {
    if (i == 0 && j == 0) {
        return str1[i] == str2[j] ? 1 : 0;
    }
    else if (i == 0) {
        if (str1[i] == str2[j]) {
            return 1;
        }
        else {
            return process1(str1, str2, 0, j - 1);
        }
    }
    else if (j == 0) {
        if (str1[i] == str2[j]) {
            return 1;
        }
        else {
            return process1(str1, str2, i - 1, 0);
        }
    }
    int p1 = process1(str1, str2, i - 1, j);
    int p2 = process1(str1, str2, i, j - 1);
    int p3 = str1[i] == str2[j] ? (1 + process1(str1, str2, i - 1, j - 1)) : 0;
    return max(p1, max(p2, p3));


}

//通过15/44
int way1(string& str1, string& str2) {
    if (str1.empty() || str2.empty()) {
        return 0;
    }
    return process1(str1, str2, str1.size() - 1, str2.size() - 1);
}

int way2(string& str1, string& str2) {
    int N = str1.size();
    int M = str2.size();
    vector<vector<int>>dp(N, vector<int>(M, -1));
    dp[0][0] = str1[0] == str2[0] ? 1 : 0;
    for (int j = 1; j < M; j++) {
        dp[0][j] = str1[0] == str2[j] ? 1 : dp[0][j - 1];
    }
    for (int i = 1; i < N; i++) {
        dp[i][0] = str1[i] == str2[0] ? 1 : dp[i-1][0];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            int p1 = dp[i - 1][j];
            int p2 = dp[i][j - 1];
            int p3 = str1[i] == str2[j] ? (1 + dp[i - 1][j - 1]): 0;
            dp[i][j] = max(p1, max(p2, p3));
        }
    }
    return dp[N-1][M-1];
}




int main()
{
    string str1 = "abcde";
    string str2 = "ace";
    cout<< way2(str1, str2);
    return 0;
}

