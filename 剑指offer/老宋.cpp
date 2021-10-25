#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main() {
    string str;
    cin >> str;
    stringstream ss(str);
    vector<int> nums;
    while(getline(ss, str, ',')) {
        int num = stoi(str);
        nums.push_back(num);
    }
    int n = nums.size();
    int l = 1;
    vector<vector<int>> ed;
    int idx = 0;
    while(n >= l) {
        vector<int> t;
        int t = l;
        while(t-- > 0) {
            t.push_back(nums[idx]);
            idx++;
        }
        n -= l;
        l++;
        ed.push_back(t);
    }
    for(auto x : ed) {
        for(auto y : x) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}