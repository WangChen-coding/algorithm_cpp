#include<iostream>
#include<vector>
#include<stack>
#include<map>

using namespace std;

class Node {
public:
	int val;
	Node(int i) {
		val = i;
	}
};
class UnionFind {
public:
	map<int, Node*>nodes;
	map<Node*, Node*>parents;
	map<Node*, int>sizeMap;
	UnionFind(vector<int>& arr) {
		for (auto cur : arr) {
			Node* node = new Node(cur);
			nodes[cur] = node;
			parents[node] = node;
			sizeMap[node] = 1;
		}
	}
	Node* findFather(Node* cur) {
		stack<Node*>path;
		while (cur != parents[cur]) {
			path.push(cur);
			cur = parents[cur];
		}
		while (!path.empty()) {
			parents[path.top()] = cur;
			path.pop();
		}
		return cur;
	}
	void un(int a, int b) {
		Node* aHead = findFather(nodes[a]);
		Node* bHead = findFather(nodes[b]);
		if (aHead != bHead) {
			int asetsize = sizeMap[aHead];
			int bsetsize = sizeMap[bHead];
			Node* big = asetsize >= bsetsize ? aHead : bHead;
			Node* small = big == aHead ? bHead : aHead;
			parents[small] = big;
			sizeMap[big] = asetsize + bsetsize;
			sizeMap.erase(small);
		}
	}
	int sets() {
		return sizeMap.size();
	}
	bool issameset(int a,int b) {
		return findFather(nodes[a]) == findFather(nodes[b]);
	}
};

int main() {

}