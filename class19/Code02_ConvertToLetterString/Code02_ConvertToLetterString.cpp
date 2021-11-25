#include  <sstream>
#include <iostream>
#include<string>
#include<vector>
using namespace std;


int process(string& str, int index) {
    if (index == str.size()) {
        return 1;
    }
    if (str[index] == '0') {
        return 0;
    }
    int p1 = process(str, index + 1);
    if (index + 1 < str.size() && ((str[index] - 'a') * 10 + str[index + 1] - 'a') < 27) {
        p1 += process(str, index + 2);
    }
    return p1;
}
int way1(string& str) {
    return process(str, 0);
}
int way2(string& str) {
	int N = str.size();
	vector<int>dp(N+1, 0);
	dp[N] = 1;
	for (int index = N - 1; index >= 0; index--) {
		if (str[index] != '0') {
			int p1 = dp[index + 1];
			if (index + 1 < str.size() && ((str[index] - 'a') * 10 + str[index + 1] - 'a') < 27) {
				p1 += dp[index + 2];
			}
			dp[index] = p1;
		}
	}
	return dp[0];
}
int testprocess(string& str, int index) {
	if (index == str.size()) {
		return 1;
	}
	if (str[index] == '0') {
		return 0;
	}
	int p1 = testprocess(str, index + 1);
	if ((index + 1) < str.size() && ((str[index] - 'a') * 10 + str[index + 1] - 'a') < 27) {
		p1 += testprocess(str, index + 2);
	}
	return p1;
}
int testways(string& str) {
	return process(str, 0);
}


int main()
{
	int N = 3000000000;
	int testTime = 10;
	for (int i = 0; i < testTime; i++) {
		long long s = rand()*rand()*rand()*rand();
		string str;
		stringstream ss;
		ss << s;
		ss >> str;
		int a= way1(str);
		int b= way2(str);
		int c = testways(str);
	//	if (a != b) {
			cout << str << endl;
			cout << a << endl;
			cout << b << endl;
			cout << c << endl;
//		}
		
	}

    return 0;
}


