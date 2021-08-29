#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int processg(vector<int>&, int, int);
int processf(vector<int>& arr, int L, int R) {
	if (L == R) {
		return arr[L];
	}
	int p1 = arr[L] + processg(arr, L + 1, R);
	int p2 = arr[R] + processg(arr, L, R - 1);
	return max(p1, p2);
}
int processg(vector<int>& arr, int L, int R) {
	if (L == R) {
		return 0;
	}
	int p1 = processf(arr, L + 1, R);
	int p2 = processf(arr, L, R - 1);
	return min(p1, p2);
}
int way1(vector<int>& arr) {
	int L = 0;
	int R = arr.size() - 1;
	int first = processf(arr, L, R);
	int second = processg(arr, L, R);
	return max(first, second);
}




int processg1(vector<int>&, int, int, vector<vector<int>>&, vector<vector<int>>&);
int processf1(vector<int>& arr, int L, int R, vector<vector<int>>& dpf, vector<vector<int>>& dpg) {
	if (dpf[L][R] != -1) {
		return dpf[L][R];
	}
	int ans = 0;
	if (L == R) {
		ans = arr[L];
	}
	else {
		int p1 = arr[L] + processg1(arr, L + 1, R, dpf, dpg);
		int p2 = arr[R] + processg1(arr, L, R - 1, dpf, dpg);
		ans = max(p1, p2);
	}

	dpf[L][R] = ans;
	return ans;
}
int processg1(vector<int>& arr, int L, int R, vector<vector<int>>& dpf, vector<vector<int>>& dpg) {
	if (dpg[L][R] != -1) {
		return dpg[L][R];
	}
	int ans = 0;
	if (L == R) {
		ans= 0;
	}
	else {
		int p1 = processf1(arr, L + 1, R, dpf, dpg);
		int p2 = processf1(arr, L, R - 1, dpf, dpg);
		ans = min(p1, p2);
	}

	dpg[L][R] = ans;
	return ans;
}
int way2(vector<int>& arr) {
	int L = 0;
	int R = arr.size() - 1;
	int N = arr.size();
	vector<vector<int>>dpf(N, vector<int>(N, -1));
	vector<vector<int>>dpg(N, vector<int>(N, -1));
	int first = processf1(arr, L, R, dpf, dpg);
	int second = processg1(arr, L, R, dpf, dpg);
	return max(first, second);
}

int way3(vector<int>& arr) {
	int N = arr.size();
	vector<vector<int>>dpf(N, vector<int>(N, 0));
	vector<vector<int>>dpg(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		dpf[i][i] = arr[i];
	}
	for (int startcol = 1; startcol < N; startcol++) {
		int L = 0;
		int R = startcol;
		while (R < N) {
			dpf[L][R] = max(arr[L] + dpg[L + 1][R], arr[R] + dpg[L][R - 1]);
			dpg[L][R] = min(dpf[L + 1][R], dpf[L][R - 1]);
			L++;
			R++;
		}
	}
	return max(dpf[0][N - 1], dpg[0][N - 1]);

}

int main(int argc, char** argv) {
	vector<int>arr = { 5, 7, 4, 5, 8, 1, 6, 0, 3, 4, 6, 1, 7 };
	cout << way1(arr) << endl;
	cout << way2(arr) << endl;
	cout << way3(arr)<<endl;
	return 0;
}



