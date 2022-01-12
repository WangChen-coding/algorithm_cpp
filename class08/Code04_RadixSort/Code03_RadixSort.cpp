#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getDigit(int x, int d) {
    return (x / static_cast<int>(pow(10, d - 1)) % 10);
}
void radixSort(vector<int>& arr, int L, int R, int digit) {
    int radix = 10;
    int i = 0, j = 0;
    vector<int>help(R - L + 1, 0);
    for (int d = 1; d <= digit; d++) {//有多少位，就执行多少次进桶操作
        vector<int>count(radix);
        for (i = L; i <= R; i++) {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for (i = 1; i < radix; i++) {
            count[i] = count[i] + count[i - 1];
        }
        for (i = R; i >= L; i--) {
            j = getDigit(arr[i], d);
            help[count[j] - 1] = arr[i];
            count[j]--;
        }
        for (i = L, j = 0; i <= R; i++, j++) {
            arr[i] = help[j];
        }
    }
}
int maxbits(vector<int>& arr) {
    int maxNumber = INT_MIN;
    for (int i : arr) {
        maxNumber = max(maxNumber, i);
    }
    int res = 0;
    while (maxNumber != 0) {
        res++;
        maxNumber /= 10;
    }
    return res;

}
void radixSort(vector<int>& arr) {
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    radixSort(arr, 0, arr.size() - 1, maxbits(arr));
}
void generateArray(vector<int>& arr,int maxNumber) {
    for (int i = 0; i < arr.size();i++) {
        arr[i] = rand() % maxNumber + 1;
    }
}
int main()
{
    int testTime = 1000;
    int arrayLen = 10000;
    int maxNumber = 500;
    for (int i = 0; i < testTime; i++) {
        vector<int>arr(arrayLen, 0);
        generateArray(arr,maxNumber);
        vector<int>arr1 = arr;
        sort(arr.begin(), arr.end());
        radixSort(arr1);
        for (int i = 0; i < arrayLen; i++) {
            if (arr[i] != arr1[i]) {
                cout << "error" << endl;
            }
        }
        //cout << "finish" << endl;
    }
}
