#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    stringstream ss(s);
    vector<string> nums;
    while(getline(ss, s, ',')) {
        nums.push_back(s);
    }
    
    sort(nums.begin(), nums.end(), [](string a, string b){return a + b > b + a;});
    string res = "";
    int ans;
    for(auto str : nums) {
        res += str;
    }
    ss.clear();
    ss.str("");
    ss << res;
    ss >> ans;
    cout << ans << endl;
    return 0;
}