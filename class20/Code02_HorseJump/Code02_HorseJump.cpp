#include <iostream>
#include<string>
#include<vector>
using namespace std;
//a b为当前位置
int process1(int x, int y, int a, int b, int rest) {
    if (a < 0 || a>9 || b < 0 || b>8) {
        return 0;
    }
    if (rest == 0) {
        return (x == a && y == b) ? 1 : 0;
    }
    int way = process1(x, y, a + 2, b + 1, rest - 1);
    way += process1(x, y, a + 1, b + 2, rest - 1);
    way += process1(x, y, a - 1, b + 2, rest - 1);
    way += process1(x, y, a - 2, b + 1, rest - 1);
    way += process1(x, y, a - 2, b - 1, rest - 1);
    way += process1(x, y, a - 1, b - 2, rest - 1);
    way += process1(x, y, a + 1, b - 2, rest - 1);
    way += process1(x, y, a + 2, b - 1, rest - 1);
    return way;
}

int way1(int x, int y, int K) {
    return process1(x, y, 0, 0, K);
}
int pick(vector<vector<vector<int>>>&dp, int x, int y, int rest) {
    if (x < 0 || x > 9 || y < 0 || y > 8) {
        return 0;
    }
    return dp[x][y][rest];
}

int dp(int a, int b, int k) {
    vector<vector<vector<int>>>dp(10, vector<vector<int>>(9,vector<int>(k+1,0)));
    dp[a][b][0] = 1;
    for (int rest = 1; rest <= k; rest++) {
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 9; y++) {
                int ways = pick(dp, x + 2, y + 1, rest - 1);
                ways += pick(dp, x + 1, y + 2, rest - 1);
                ways += pick(dp, x - 1, y + 2, rest - 1);
                ways += pick(dp, x - 2, y + 1, rest - 1);
                ways += pick(dp, x - 2, y - 1, rest - 1);
                ways += pick(dp, x - 1, y - 2, rest - 1);
                ways += pick(dp, x + 1, y - 2, rest - 1);
                ways += pick(dp, x + 2, y - 1, rest - 1);
                dp[x][y][rest] = ways;
            }
        }
    }
    return dp[0][0][k];
}


int main()
{
    int x = 7;
    int y = 7;
    int k = 10;
    cout<<way1(x, y, k)<<endl;
    cout << dp(x, y, k) << endl;
    return 0;
}


