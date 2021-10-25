#include<iostream>
#include<vector>

using namespace std;
 
vector<vector<int>> res;
vector<int> num;
int n;
vector<int> temp;
vector<bool> visit;

void dfs(int k) {
    if(k == n) {
        // cout << " test1 " << endl;
        res.push_back(temp);
        return;
    }
    for(int i = 0; i < n; i++) {
        cout << "test2" << endl;
        if(!visit[i]) {
            cout << "test3" << endl;
            visit[i] = true;
            temp[k] = num[i];
            dfs(k + 1);
            // temp[k] = 0;
            visit[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    num = nums;
    n = (int)nums.size();
    temp.resize(n);
    visit.resize(n);
    dfs(0);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    ans = permute(nums);
    for(auto x : ans) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << temp.size();
    return 0;
}