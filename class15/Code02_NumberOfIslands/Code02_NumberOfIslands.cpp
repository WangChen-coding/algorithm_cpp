#include <iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;
void infect(vector<vector<char>>& board, int i, int j) {
	if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != '1') {
		return;
	}
	board[i][j] = 0;
	infect(board, i - 1, j);
	infect(board, i + 1, j);
	infect(board, i, j - 1);
	infect(board, i, j + 1);
}
int numIslands1(vector<vector<char>>& board) {
	int island = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 0) {
				island++;
				infect(board, i, j);
			}
		}
	}
}
class Dot {};
class Node {
public:
	Dot* val;
	Node(Dot* i) {
		val = nullptr;
	}
};
class UnionFind {
public:
	map<Dot*, Node*>nodes;
	map<Node*, Node*>parents;
	map<Node*, int>sizeMap;
	UnionFind(vector<Dot*>& arr) {
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
	void un(Dot* a, Dot* b) {
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
	bool issameset(Dot* a, Dot* b) {
		return findFather(nodes[a]) == findFather(nodes[b]);
	}
};
int numIsLands2(vector<vector<char>>& board) {
	int row = board.size();
	int col = board[0].size();
	vector<vector<Dot*>>dots(row, vector<Dot*>(col, nullptr));
	vector<Dot*>dotlist;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == '1') {
				dots[i][j] = new Dot();
				dotlist.push_back(dots[i][j]);
			}
		}
	}
	UnionFind uf = UnionFind(dotlist);
	for (int j = 1; j < col; j++) {
		if (board[0][j - 1] == '1' && board[0][j] == '1') {
			uf.un(dots[0][j - 1], dots[0][j]);
		}
	}
	for (int i = 1; i < row; i++) {
		if (board[i - 1][0] == '1' && board[i][0] == '1') {
			uf.un(dots[i - 1][0], dots[i][0]);
		}
	}
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (board[i][j] == '1') {
				if (board[i][j - 1] == '1') {
					uf.un(dots[i][j - 1], dots[i][j]);
				}
				if (board[i - 1][j] == '1') {
					uf.un(dots[i - 1][j], dots[i][j]);
				}
			}
		}
	}
	return uf.sets();
}
class UnionFind2 {
public:
	vector<int>parent;
	vector<int>size;
	vector<int>help;
	int col;
	int sets;
	UnionFind2(vector<vector<char>>& board) {
		col = board[0].size();
		sets = 0;
		int row = board.size();
		int len = row * col;
		parent.resize(len);
		size.resize(len);
		help.resize(len);
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col;c++) {
				if (board[r][c] == '1') {
					int i = index(r, c);
					parent[i] = i;
					size[i] = 1;
					sets++;
				}
			}
		}
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
		int i1 = index(r1, c1);
		int i2 = index(r2, c2);
		int f1 = find(i1);
		int f2 = find(i2);
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
int numIsLands3(vector<vector<char>>& board) {
	int row = board.size();
	int col = board[0].size();
	UnionFind2 uf = UnionFind2(board);
	for (int j = 1; j < col; j++) {
		if (board[0][j - 1] == '1' && board[0][j] == '1') {
			uf.un(0, j - 1, 0, j);
		}
	}
	for (int i = 1; i < row; i++) {
		if (board[i - 1][0] == '1' && board[i][0] == '1') {
			uf.un(i - 1, 0, i, 0);
		}
	}
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (board[i][j] == '1') {
				if (board[i][j - 1] == '1') {
					uf.un(i, j - 1, i, j);
				}
				if (board[i - 1][j] == '1') {
					uf.un(i - 1, j, i, j);
				}
			}
		}
	}
	return uf.sts();
}
int main()
{
	std::cout << "Hello World!\n";
}

