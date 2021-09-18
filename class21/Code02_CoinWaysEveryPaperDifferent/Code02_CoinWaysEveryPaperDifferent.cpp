#include <iostream>
#include<string>
#include<vector>
using namespace std;

int process(vector<int>& arr, int index, int rest) {
    if (rest < 0) {
        return 0;
    }
    if (index == arr.size()) {
        return rest == 0 ? 1 : 0;
    }
    else {
        return process(arr, index + 1, rest) + process(arr, index + 1, rest - arr[index]);
    }
}

int coinWays(vector<int>& arr, int aim) {
    return process(arr, 0, aim);
}

int coinWays2(vector<int>& arr, int aim) {
    if (arr.size() == 0) {
        return 0;
    }
    int N = arr.size();
    vector<vector<int>>dp(N + 1, vector<int>(aim + 1,0));
    dp[N][0] = 1;
    for (int i = N-1; i >= 0; i--) {
        for (int rest = 0; rest <= aim; rest++) {
            dp[i][rest] = dp[i + 1][rest] + ((rest - arr[i] >= 0) ? dp[i + 1][rest - arr[i]] : 0);
        }
    }
    return dp[0][aim];
}



int main()
{
    vector<int>m = { 1,3,1,9,8,1,3,4,5,0,6,1,8,8,4,0 };
    cout << coinWays(m, 10)<<endl;
    cout << coinWays2(m, 10) << endl;
    return 0;
}





