
#include <iostream>
#include<vector>
#include<map>
using namespace std;
class heapgreater {
public:
    vector<int>arr;
    map<int, int>indexmap;
    int heapsize;
    bool empty() {
        return heapsize == 0;
    }
    int size() {
        return heapsize;
    }
    int top() {
        return arr[0];
    }
    //交换,不止是要交换数组中的两数
    //还要将对应的map中对应的下标和data映射修改好
    //
    void swap(vector<int>& arr, int num1,int num2) {
        int o1 = arr[num1];
        int o2 = arr[num2];
        arr[num1] =o2;
        arr[num2] = o1;
        indexmap.insert(o1, num2);
        indexmap.insert(o2, num1);
    }
    //对index下标的元素做heapify或者heapinsert操作
    //调整完毕后，重新形成堆
    void resign(int index) {
        heapinsert(arr,indexmap[index]);
        heapify(arr, indexmap[index], heapsize);
    }
    //移除某个数num
    //首先获取数组的最后一个元素
    //然后在map中找到需要去掉的元素num对应的索引index
    //去掉数组arr中的最后一位
    //判断要去掉的num是否本来是就是尾部的元素
    //如果不是，则将index位置替换为原来尾部的元素，再将map中的索引进行更新
    //最后对这个结果位置进行堆操作
    void remove(int num) {
        int end = arr[heapsize - 1];
        //找到num的索引
        int index = indexmap[num];
        //在arr和map中删掉num的信息
        indexmap.erase(num);
        arr.erase(arr.begin()+(--heapsize));
        //将end的信息加进去，再做堆化
        if (num != end) {
            arr[index] = end;
            indexmap[end] = index;
            resign(end);
        }
    }
    void heapinsert(vector<int>& arr, int index) {
        while (arr[index] > arr[(index - 1) / 2]) {
            swap(arr, index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }
    void heapify(vector<int>& arr, int index, int size) {
        int left = index * 2 + 1;
        while (left < size) {
            int largest = left + 1 < size && arr[left] < arr[left + 1] ? left + 1 : left;
            largest = arr[index] < arr[largest] ?  largest:index;
            if (largest == index) {
                break;
            }
            swap(arr, index, largest);
            index = largest;
            left = index * 2 + 1;
        }
    }
    //向堆内添加元素，首先要将元素添加到数组的尾部
    //其次，在map集合中加入对应的数值和下标
    //最后做heapinsert，将堆调整完毕
    void push(int num) {
        arr.push_back(num);
        indexmap.insert(num, heapsize);
        heapinsert(arr,heapsize++);
    }
    //从堆顶弹出元素，
    //交换数组首尾位置
    //去掉map中堆顶节点和下标
    //去除数组中的尾节点
    //堆从堆顶开始heapify
    int pop() {
        int num = arr[0];
        swap(arr, 0, heapsize-1);
        indexmap.erase(num);
        arr.pop_back();
        heapify(arr, 0, --heapsize);
        return num;
    }




};
int main()
{
    std::cout << "Hello World!\n";
}

