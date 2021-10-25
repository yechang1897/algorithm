#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    vector<vector<string>> versions = {{"0.1.1", "1.0"}, {"2.1.13", "1.20.0"},{"2.1.0","2.1.0"}};
    int m = versions.size();
    vector<int> nums;
    for(int i = 0; i < m; i++) {
        if(versions[i][0] < versions[i][1]) nums.push_back(2);
        else nums.push_back(1);
    }
    for(auto x : nums) {
        cout << x << " ";
    }
    return 0;
}