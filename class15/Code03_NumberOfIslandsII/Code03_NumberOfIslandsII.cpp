#include <iostream>
#include<vector>
using namespace std;
vector<int> numIsland(int m, int n, vector<vector<int>>& positions) {
    UnionFind uf(m, n);
    vector<int>ans;
    for (auto position : positions) {
        ans.push_back(uf.connect(position[0], position[1]));
    }
    return ans;
}
class UnionFind {
private:
    vector<int>parent;
    vector<int>size;
    vector<int>help;
    int row;
    int col;
    int sets;
public:
    UnionFind(int m, int n) {
        row = m;
        col = n;
        sets = 0;
        int len = row * col;
        parent.resize(len);
        size.resize(len);
        help.resize(len);
    }
    int index(int r, int c) {
        return r * col + c;
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
    void un(int r1, int c1, int r2, int c2) {
        if (r1 < 0 || r1 == row || r2 < 0 || r2 == row || c1 < 0 || c1 == col || c2 < 0 || c2 == col) {
            return;
        }
        int i1 = index(r1, c1);
        int i2 = index(r2, c2);
        if (size[i1] == 0 || size[i2] == 0) {
            return;
        }
        int f1 = find(i1);
        int f2 = find(i2);
        if (i1 != i2) {
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
    int connect(int r, int c) {
        int idx = index(r, c);
        if (size[idx] == 0) {
            parent[idx] = idx;
            size[idx] = 1;
            sets++;
            un(r - 1, c, r, c);
            un(r + 1, c, r, c);
            un(r, c - 1, r, c);
            un(r, c + 1, r, c);
        }
        return sets;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

