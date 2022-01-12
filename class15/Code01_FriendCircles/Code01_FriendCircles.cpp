#include <iostream>
#include<vector>

using namespace std;

class UnionFind1 {
public:
    vector<int>parent;
    vector<int>size;
    vector<int>help;
    int sets = 0;
    UnionFind1(int N) {
        parent.resize(N);
        size.resize(N);
        help.resize(N);
        sets = N;
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int i) {
        int hi = 0;
        while (i != parent[i]) {
            help[hi++] = i;
            i = parent[i];
        }
        for (hi--; hi >= 0; hi--) {
            parent[help[hi]] = i;
        }
        return i;
    }
    void un(int i, int j) {
        int f1 = find(i);
        int f2 = find(j);
        if (f1 != f2) {
            if (size[f1] >= size[f2]) {
                size[f1] += size[f2];
                parent[f2] = f1;
            }
            else {
                size[f2] += size[f1];
                parent[f1] = f2;
            }
            sets--;
        }
    }
    int sts() {
        return sets;
    }
};
template<typename T>
class Node {
public:
    T val;
    Node(T i) {
        val = i;
    }
};
template<typename T>
class UnionFind {
public:
    map<T, Node*>nodes;
    map<Node*, Node*>parents;
    map<Node*, int>sizeMap;
    UnionFind(vector<T>& arr) {
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
    void un(T a, T b) {
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
    int sts() {
        return sizeMap.size();
    }
    bool issameset(T a, T b) {
        return findFather(nodes[a]) == findFather(nodes[b]);
    }
};
int findCircleNum(vector<vector<int>>& isconnected) {
    int N = isconnected.size();
    UnionFind<int>* unionfind ;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (isconnected[i][j] == 1) {
                unionfind->un(i, j);
            }
        }
    }
    return unionfind->sts();
}


int main()
{
    std::cout << "Hello World!\n";
}
