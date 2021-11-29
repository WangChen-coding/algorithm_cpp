//已知一个几乎有序的数组。几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离一定不超过k
//k相对于数组长度来说是比较小的。请选择一个合适的排序策略，对这个数组进行排序。

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void sortedArrDistanceLessK(vector<int>& arr, int k) {
	if (k == 0) {
		return;
	}
	priority_queue<int, vector<int>, greater<int>> heap;
	int index = 0;
	int len = arr.size();
	//先建一个k大小的堆
	for (; index <= min(len - 1, k - 1); index++) {
		heap.push(arr[index]);
	}
	//将新的加入到堆中，再将堆顶的元素弹出，存放在数组中
	int i = 0;
	for (; index < len; i++, index++) {
		heap.push(arr[index]);
		arr[i] = heap.top();
		heap.pop();
	}
	//如果数组中的元素都进入堆中，最后只剩下堆里面有元素，那么依次将堆中属于元素弹出
	while (!heap.empty()) {
		arr[i++] = heap.top();
		heap.pop();
	}
}

int main()
{
	vector<int> arr = { 2,4,1,3,5 };
	sortedArrDistanceLessK(arr, 3);
	for (auto i : arr) {
		cout << i << endl;
	}
}

