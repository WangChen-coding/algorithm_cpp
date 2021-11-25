#include <iostream>
#include<vector>
using namespace std;

int process(vector<int>& arr, int index, int rest) {
    if (index == arr.size()) {
        return 0;
    }
    else {
        int p1 = process(arr, index + 1, rest);
        int p2 = 0;
        if (arr[index] <= rest) {
            p2 =arr[index]+ process(arr, index + 1, rest - arr[index]);
        }
        return max(p1, p2);
    }
}
int ways(vector<int>& arr) {
    if (arr.size() == 0 || arr.size() < 2) {
        return 0;
    }
    int sum = 0;
    for (int i : arr) {
        sum += i;
    }
    return process(arr, 0, sum / 2);
}

int dp(vector<int>& arr) {
    if (arr.size() == 0 || arr.size() < 2) {
        return 0;
    }
    int sum = 0;
    for (int i : arr) {
        sum += i;
    }
    sum /= 2;
    int N = arr.size();
    vector<vector<int>>dp(N + 1, vector<int>(sum+1, 0));
    for (int index = N - 1; index >= 0; index--) {
        for (int rest = 0; rest <= sum; rest++) {
            int p1 = dp[index + 1][rest];
            int p2 = 0;
            if (arr[index] <= rest) {
                p2 = arr[index] + dp[index + 1][rest - arr[index]];
            }
            dp[index][rest] = max(p1, p2);
        }
    }
    return dp[0][sum];

}
int main()
{
    vector<int>arr{ 1,2,3,4,5,9 };
    cout << ways(arr)<<endl;
    cout << dp(arr) << endl;
    std::cout << "Hello World!\n";
}

