#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> res;
vector<int> t;
bool vis[10];
int cnt = 0;
//去重，可以排序给定数组，递归条件可以设置为当前未访问，且与t数组最后一个数字不相同。
void bt(vector<int> nums, int k) {
    if(k == nums.size()) {
        cnt++;
        // t.erase(t.begin());
        res.push_back(t);
        return; 
    }
    
    for(int i = 0; i < nums.size(); i++) {
        if(vis[i]) continue;


        t.push_back(nums[i]);
        vis[i] = true;
        bt(nums, k + 1);
        vis[i] = false;
        t.pop_back();
        
    }
} 

int main() {
    vector<int> nums = {1,2,3};
    sort(nums.begin(), nums.end());
    bt(nums, 0);
    for(auto v : res) {
        for(auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}