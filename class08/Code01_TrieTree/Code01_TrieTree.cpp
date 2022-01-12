#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;

class Node {
public:
	Node() {
		pass = 0;
		end = 0;
		nexts.resize(26);
	}
	int pass = 0;
	int end = 0;
	vector<Node*>nexts;
};

class Trie1 {
public:
	Trie1() {
		root = new Node();
	}
	void insert(string str) {
		if (str.empty()) {
			return;
		}
		vector<char>chs;
		chs.assign(str.begin(), str.end());
		Node* node = root;
		node->pass++;
		int index = 0;
		for (int i = 0; i < chs.size(); i++) {
			index = chs[i] - 'a';
			if (node->nexts[index] == nullptr) {
				node->nexts[index] = new Node();
			}
			node = node->nexts[index];
			node->pass++;
		}
		node->end++;
	}
	int search(string str) {
		if (str.empty()) {
			return 0;
		}
		vector<char>chs;
		chs.assign(str.begin(), str.end());
		Node* node = root;
		int index = 0;
		for (int i = 0; i < chs.size(); i++) {
			index = chs[i] - 'a';
			if (node->nexts[index] == nullptr) {
				return 0;
			}
			node = node->nexts[index];
		}
		return node->end;
	}
	int prefixNumber(string str) {
		if (str.empty()) {
			return 0;
		}
		vector<char>chs;
		chs.assign(str.begin(), str.end());
		Node* node = root;
		int index = 0;
		for (int i = 0; i < chs.size(); i++) {
			index = chs[i] - 'a';
			if (node->nexts[index] == nullptr) {
				return 0;
			}
			node = node->nexts[index];
		}
		return node->pass;
	}
	void deleteword(string str) {
		if (search(str) != 0) {
			vector<char>chs;
			chs.assign(str.begin(), str.end());
			Node* node = root;
			node->pass--;
			int index = 0;
			for (int i = 0; i < chs.size(); i++) {
				index = chs[i] - 'a';
				if (--node->nexts[index]->pass == 0) {
					node->nexts[index] = nullptr;
					return;
				}
				node = node->nexts[index];
			}
			node->end--;
		}
	}


private:
	Node* root;
};
class Node2 {
public:
	int pass;
	int end;
	map<int, Node2*>nexts;
	Node2() {
		pass = 0;
		end = 0;
	}
};
class Trie2 {
public:
	Trie2() {
		root = new Node2();
	}
	void insert(string str) {
		if (str.empty()) {
			return;
		}
		vector<char>chs;
		chs.assign(str.begin(), str.end());
		Node2* node = root;
		int index = 0;
		for (int i = 0; i < chs.size(); i++) {
			index = static_cast<int>(chs[i]);
			if (node->nexts.find(index) == node->nexts.end()) {
				node->nexts[index] = new Node2();
			}
			node = node->nexts[index];
			node->pass++;
		}
		node->end++;
	}
	int search(string str) {
		if (str.empty()) {
			return 0;
		}
		vector<char>chs;
		chs.assign(str.begin(), str.end());
		Node2* node = root;
		int index = 0;
		for (int i = 0; i < chs.size(); i++) {
			index = static_cast<int>(chs[i]);
			if (node->nexts.find(index) == node->nexts.end()) {
				node->nexts[index] = new Node2();
			}
			node = node->nexts[index];
		}
		return node->end;
	}
	int prefixNumber(string str) {
		if (str.empty()) {
			return 0;
		}
		vector<char>chs;
		chs.assign(str.begin(), str.end());
		Node2* node = root;
		int index = 0;
		for (int i = 0; i < chs.size(); i++) {
			index = static_cast<int>(chs[i]);
			if (node->nexts.find(index) == node->nexts.end()) {
				node->nexts[index] = new Node2;
			}
			node = node->nexts[index];
		}
		return node->pass;
	}
	void deleteword(string str) {
		if (search(str) != 0) {
			vector<char>chs;
			chs.assign(str.begin(), str.end());
			Node2* node = root;
			int index = 0;
			for (int i = 0; i < chs.size(); i++) {
				index = static_cast<int>(chs[i]);
				if (--node->nexts[index]->pass == 0) {
					node->nexts.erase(index);
					return;
				}
				node = node->nexts[index];
			}
			node->end--;
		}
	}
	Node2* root;
};
string generateRandomString(int strLen) {
	int len = rand() % strLen + 1;
	string str;
	for (int i = 0; i < len; i++) {
		str.push_back(static_cast<char>(97 + (rand() % 26)));
	}
	return str;
}
vector<string> generateRandomStringArray(int arrLen, int strLen) {
	vector<string>ans;
	int len = rand() % arrLen + 1;
	for (int i = 0; i < len; i++) {
		ans.push_back(generateRandomString(strLen));
	}
	return ans;
}
class Right {
public:
	void insert(string str) {
		if (box.find(str) == box.end()) {
			box[str] = 1;
		}
		else {
			box[str] += 1;
		}
	}
	int search(string str) {
		if (box.find(str) == box.end()) {
			return 0;
		}
		else {
			return box[str];
		}
	}
	int prefixNumber(string str) {
		int count = 0;
		for (auto it : box) {
			for (auto i = it.first.begin(); i != it.first.end(); i++) {
				string s;
				s.assign(it.first.begin(), i + 1);
				if (s == str) {
					count += box[it.first];
				}
			}
		}
		return count;
	}
	void deleteword(string str) {
		if (search(str)) {
			if (box[str] == 1) {
				box.erase(box.find(str));
			}
			else {
				box[str] -= 1;
			}
		}
	}
	map<string, int>box;
};
int main()
{
	int arrLen = 1000;
	int strLen = 20;
	int testTime = 100; 
	for (int i = 0; i < testTime; i++) {
		vector<string>arr = generateRandomStringArray(arrLen, strLen);
		Trie1* trie1 = new Trie1();
		Trie2* trie2 = new Trie2();
		Right* right = new Right();
		for (int j = 0; j < arr.size(); j++) {
			double decide = rand() % 40;
			if (decide < 19) {
				trie1->insert(arr[j]);
				trie2->insert(arr[j]);
				right->insert(arr[j]);
			}
			else if (decide == 20) {
				trie1->deleteword(arr[j]);
				trie2->deleteword(arr[j]);
				right->deleteword(arr[j]);
			}
			else if (decide < 30) {
				int ans1 = trie1->search(arr[j]);
				int ans2 = trie2->search(arr[j]);
				int ans3 = right->search(arr[j]);
				if (ans1 != ans2 || ans1 != ans2) {
					cout << "error" << endl;
				}
			}
			else {
				int ans1 = trie1->prefixNumber(arr[j]);
				int ans2 = trie2->prefixNumber(arr[j]);
				int ans3 = right->prefixNumber(arr[j]);
				if (ans1 != ans2 || ans1 != ans3) {
					cout << "pre error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

				}
			}
		}
	}
	std::cout << "finish" << endl;
}

