
#include <iostream>
#include<vector>
using namespace std;
class myheap {
public:
    myheap(int limit) {
        heap.resize(limit);
        this->limit = limit;
        heapsize = 0;
    }
    bool isempty() {
        return heapsize == 0;
    }
    bool isfull() {
        return heapsize == limit;
    }
    void swap(vector<int>& heap, int num1, int num2) {
        int num = heap[num1];
        heap[num1] = heap[num2];
        heap[num2] = num;
    }
    void heapinsert(vector<int>& heap, int index) {
        while (heap[index] < heap[(index - 1) / 2]) {
            swap(heap, index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }
    void heapify(vector<int>& heap, int index, int size) {
        int left = index * 2 + 1;
        while (left<heapsize)
        {
            int largest = left + 1 < heapsize && heap[left + 1] < heap[left] ? left + 1 : left;
            largest = heap[largest] < heap[index] ? largest : index;
            if (largest == index) {
                break;
            }
            swap(heap, largest, index);
            index = largest;
            left = index * 2 + 1;
        }
    }
    void push(int value) {
        if (heapsize == limit)
            cout << "heap is full" << endl;
        heap[heapsize] = value;
        heapinsert(heap, heapsize++);
    }
    int pop() {
        int ans = heap[0];
        swap(heap, 0, --heapsize);
        heapify(heap, 0, heapsize);
        return ans;
    }
    

private:
    vector<int>heap;
    int heapsize;
    int limit;
};
int main()
{
    myheap heap1(5);
    heap1.push(1);
    heap1.push(3);
    heap1.push(8);
    heap1.push(2);
    heap1.push(0);
    cout<<heap1.pop()<<endl;
    cout<<heap1.pop()<<endl;
    cout<<heap1.pop()<<endl;
    cout<<heap1.pop()<<endl;
    cout<<heap1.pop()<<endl;

}

