#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> nums;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        nums.push_back(make_pair(a,b));
    }
    sort(nums.begin(), nums.end(), [](pair<int,int> x, pair<int,int> y){
        return x.second < y.second;
    });
    puts("---------------------------");
    for(auto x : nums) {
        cout << x.first << " " << x.second << endl;
    }
    puts("---------------------------");
    int res = 0, ed = -2e9;
    for(int i = 0; i < n; i++) {
        if(nums[i].first >= ed) {
            // cout << nums[i].first << " " << ed << endl;
            res++;
            ed = nums[i].second;
        }
    }
    // cout << ("3" > "30") <<endl;
    cout << res << endl;
}