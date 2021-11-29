#include <iostream>
#include<vector>
using namespace std;
void swap(vector<int>& arr, int index1, int index2) {
	int num = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = num;
}
void heapify(vector<int>& arr, int index, int heapsize) {
	int left = index * 2 + 1;
	while (left < heapsize) {
		int largest = left + 1 < heapsize && arr[left] > arr[left + 1] ? left + 1 : left;
		largest = arr[largest] >= arr[index] ? index : largest;
		if (largest == index) {
			break;
		}
		swap(arr, largest, index);
		index = largest;
		left = index * 2 + 1;
	}
}
void heapinsert(vector<int>& arr, int index) {
	while (arr[index] < arr[(index - 1) / 2]) {
		swap(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void heapsort(vector<int>& arr) {
	for (int i = arr.size(); i >= 0; i--) {
		heapify(arr, i, arr.size());
	}
	int heapsize = arr.size();
	swap(arr, 0, --heapsize);
	while (heapsize > 0) {
		heapify(arr, 0, heapsize);
		swap(arr, 0, --heapsize);
	}
}
int main()
{
	vector<int>arr{ 1,4,2,5,7,1,2 };
	heapsort(arr);
	for (auto i : arr) {
		cout << i << endl;
	}
}


