#include <iostream>
#include<vector>
using namespace std;
int process(vector<int>& arr, int index, int picks, int rest) {
    if (index == arr.size()) {
        return picks == 0 ? 0 : -1;
    }
    else {
        int p1 = process(arr, index + 1, picks, rest);
        int p2 = -1;
        int next = -1;
        if (arr[index] <= rest) {
            next = process(arr, index + 1, picks - 1, rest - arr[index]);
        }
        if (next != -1) {
            p2 = arr[index] + next;
        }
        return max(p1, p2);
    }
}
int ways(vector<int>& arr) {
    if (arr.empty() == true || arr.size() < 2) {
        return 0;
    }
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    if ((arr.size() & 1) == 0) {
        return process(arr, 0, arr.size() / 2, sum / 2);
    }
    else {
        return max(process(arr, 0, arr.size() / 2, sum / 2), process(arr, 0, arr.size() / 2 + 1, sum / 2));
    }
}
int dp(vector<int>& arr) {
    if (arr.empty() == true || arr.size() < 2) {
        return 0;
    }
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    sum /= 2;
    int N = arr.size();
    int M = (N + 1) / 2;
    vector<vector<vector<int>>>dp(N + 1, vector<vector<int>>(M + 1, vector<int>(sum + 1, 0)));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= sum; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    for (int rest = 0; rest <= sum; rest++) {
        dp[N][0][rest] = 0;
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int picks = 0; picks <= M; picks++) {
            for (int rest = 0; rest <= sum; rest++) {
                int p1 = dp[i + 1][picks][rest];
                // 就是要使用arr[i]这个数
                int p2 = -1;
                int next = -1;
                if (picks - 1 >= 0 && arr[i] <= rest) {
                    next = dp[i + 1][picks - 1][rest - arr[i]];
                }
                if (next != -1) {
                    p2 = arr[i] + next;
                }
                dp[i][picks][rest] = max(p1, p2);
            }
        }
    }
    if ((arr.size() & 1) == 0) {
        return dp[0][arr.size() / 2][sum];
    }
    else {
        return max(dp[0][arr.size() / 2][sum], dp[0][(arr.size() / 2) + 1][sum]);
    }

}
int main()
{
    vector<int>arr{ 1,2,3,4,5,6,7,8,9 };
    cout << ways(arr) << endl;
    cout << dp(arr) << endl;
    std::cout << "Hello World!\n";
}

