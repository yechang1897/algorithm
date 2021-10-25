#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

int get_max_sum(string n_k, string arr) {
    stringstream ss(n_k);
    string t = "";
    vector<int> nk;
    while(getline(ss, t, ' ')) {
        int num = stoi(t);
        nk.push_back(num);
    }
    ss.clear();
    ss.str("");
    ss << arr;
    vector<int> nums;
    string t2;
    while(getline(ss, t2, ' ')) {
        int num = stoi(t2);
        nums.push_back(num);
    }
    // sort(nums.begin(), nums.end());
    // for(auto x : arr) cout << x <<" ";
    // cout << endl;
    int res = 0;
    for(int i = 0; i < nk[1] - 1; i++) {
        res += nums[i] * (i + 1);
    }
    for(int i = nk[1] - 1; i < nk[0]; i++) {
        res += nums[i] * (nk[1]);
    }
    return res;
}

int main() {
    cout << get_max_sum("7 3", "1 2 3 4 5 6 7");
    return 0;
}