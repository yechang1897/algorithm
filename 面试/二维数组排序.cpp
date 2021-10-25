#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<pair<int,int>> nums;
    while(true) {
        int a, b;
        cin >> a >> b;
        nums.push_back(make_pair(a, b));
        if(getchar() == 'a') break;
    }
    cout << "-----------------------------" << endl;
    stable_sort(nums.begin(), nums.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first < b.first) return a.second < b.second;
        else return a.second < b.second;
    });
    for(auto x : nums) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}