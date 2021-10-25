#include<iostream>
#include<vector>
using namespace std;

int res = 0;

vector<pair<int,int>> f;

bool check(vector<pair<int,int>> f) {
    if(f.size() < 3) return false;
    // for(auto x : f) cout << x.first << " " << x.second << endl;
    // cout << "------------" << endl;
    bool flag = true;
    for(int i = 0; i < 2; i++) {
        if(f[i].first > f[i + 1].first) flag = false;
        if(f[i].second > f[i + 1].second) flag = false;
    }
    bool flag2 = true;
    for(int i = 0; i < 2; i++) {
        if(f[i].first > f[i + 1].first) flag2 = false;
        if(f[i].second < f[i + 1].second) flag2 = false;
    }
   return flag || flag2 ;
}

void dfs(vector<int> nums, int n ) {
    if(n >= (int)nums.size() || f.size() >= 3 || (f.size() + (nums.size() - n + 1) < 3)) {
        if(check(f)) res++;
        return;
    }

    dfs(nums, n + 1);

    f.push_back(make_pair(n, nums[n]));

    dfs(nums, n + 1);
    f.pop_back();
}

int main() {
    vector<int> nums;
    int i;
    while(true) {
       char c = getchar();
       if(c == '[' || c == ']' || c == ',') continue;
       cin >> i;
       cout << i << endl;
       nums.push_back(i);
       if(c == '\n') break; 
    }
    for(int i = 0; i < nums.size(); i++) 
        cout << nums[i] << " ";
    cout << endl;
    dfs(nums, 0);
    cout << res << endl;
}