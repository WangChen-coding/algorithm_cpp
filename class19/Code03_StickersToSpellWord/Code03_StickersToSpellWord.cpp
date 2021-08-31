#include <iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

string minusString(string& target, string& first) {
    vector<int>count(26, 0);
    string rest;
    for (char s : target) {
        count[s - 'a']++;
    }
    for (char s : first) {
        count[s - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                rest.push_back((char)(i + 'a'));
            }
        }
    }
    return rest;
}

int process(vector<string>& stickers, string& target) {
    if (target.size() == 0) {
        return 0;
    }
    int m = INT_MAX;
    for (string first : stickers) {
        string rest = minusString(target, first);
        if (rest.size() != target.size()) {
            m = min(m, process(stickers, rest));
        }
    }
    return m + (m == INT_MAX ? 0 : 1);
}
//21/101
int way1(vector<string>& stickers, string& target) {
    int ans= process(stickers, target);
    return ans == INT_MAX ? -1 : ans;
}


int process2(vector<vector<int>>& count, string& target) {
    if (target.size() == 0) {
        return 0;
    }
    vector<int>tcounts(26, 0);
    for (auto s : target) {
        tcounts[s - 'a']++;
    }
    int m = INT_MAX;
    for (int i = 0; i < count.size(); i++) {
        if (count[i][target[0] - 'a'] > 0) {
            string rest;
            for (int j = 0; j < 26; j++) {
                if (tcounts[j] > 0) {
                    int num = tcounts[j] - count[i][j];
                    for (int k = 0; k < num; k++) {
                        rest.push_back((char)(j + 'a'));
                    }
                }
            }
            m = min(m, process2(count, rest));
        }
    }
    return m + (m == INT_MAX ? 0 : 1);
}
//33/101
int way2(vector<string>& stickers, string& target) {
    int N = stickers.size();
    vector<vector<int>>counts(N, vector<int>(26, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < stickers[i].size(); j++) {
            counts[i][stickers[i][j] - 'a']++;
        }
    }
    int ans= process2(counts, target);
    return ans== INT_MAX ?-1:ans;
}


int process3(vector<vector<int>>& count, string& target, map<string, int>& dp) {
    if (dp.find(target) != dp.end()) {
        return dp[target];
    }
    vector<int>tcounts(26, 0);
    for (auto s : target) {
        tcounts[s - 'a']++;
    }
    int m = INT_MAX;
    for (int i = 0; i < count.size(); i++) {
        if (count[i][target[0] - 'a'] > 0) {
            string rest;
            for (int j = 0; j < 26; j++) {
                if (tcounts[j] > 0) {
                    int num = tcounts[j] - count[i][j];
                    for (int k = 0; k < num; k++) {
                        rest.push_back((char)(j + 'a'));
                    }
                }
            }
            m = min(m, process3(count, rest,dp));
        }
    }
    int ans = m + (m == INT_MAX ? 0 : 1);
    dp[target] = ans;
    return ans;
}

int way3(vector<string>& stickers, string& target) {
    int N = stickers.size();
    vector<vector<int>>counts(N, vector<int>(26, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < stickers[i].size(); j++) {
            counts[i][stickers[i][j] - 'a']++;
        }
    }
    map<string, int>dp;
    dp[""] = 0;
    int ans = process3(counts, target,dp);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    vector<string>stickers = { "swim","love","father","shape","rich","multiply","new","fill","history" };
    string target= "operateform";
    //cout << way1(stickers, target);
    //cout << way2(stickers, target);
    cout << way3(stickers, target);
    return 0;
}


