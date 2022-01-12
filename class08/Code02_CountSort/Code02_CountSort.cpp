#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//适用于数据范围0-200的arr情况
void countSort(vector<int>& arr) {
	if (arr.empty() || arr.size() < 2) {
		return;
	}
	int maxNumber = INT_MIN;
	for (int i : arr) {
		maxNumber = max(maxNumber, i);
	}
	vector<int>bucket(maxNumber + 1, 0);
	for (int i : arr) {
		bucket[i]++;
	}
	int index = 0;
	for (int count = 0; count < bucket.size(); count++) {
		while (bucket[count]-- > 0) {
			arr[index++] = count;
		}
	}
}
vector<int> generateArray(int arraySize, int maxNumber) {
	vector<int>arr;
	for (int i = 0; i < arraySize; i++) {
		arr.push_back(rand() % maxNumber + 1);
	}
	return arr;
}
int main()
{
	int testTimes = 1000;
	int arrLen = 1000;
	int maxNumber = 100;
	for (int i = 0; i < testTimes; i++) {
		vector<int>arr = generateArray(arrLen, maxNumber);
		vector<int>arr1 = arr;
		sort(arr.begin(), arr.end());
		countSort(arr1);
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] != arr1[j]) {
				cout << "error" << endl;
			}
		}
	}
}

