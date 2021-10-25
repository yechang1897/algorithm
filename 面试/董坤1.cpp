#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int s[2400];

int findx(int x){
    int r=x;
    while(s[r]!=r)r=s[r];
    return r;
}

void mergeset(int a,int b){
    int x=findx(a);
    int y=findx(b);
    if(x!=y)s[y]=x;//初次尝试查并集：注意这个地方一定是根节点换，第一次写成s[b]=a，错误
}

int countMax(vector<vector<string>>& timeSchedule) {
    vector<pair<int,int>> nums;
    int sz = timeSchedule.size();
    for(int i = 0; i < sz; i++) {
        string s1 = timeSchedule[i][0];
        string s2 = timeSchedule[i][1];
        s1.erase(2,1);
        s2.erase(2,1);
        nums.push_back(make_pair(stoi(s1),stoi(s2)));
    }
    int maxN = 0; 
    for(int i = 0; i < sz;i++) {
        if(maxN < nums[i].first) {
            maxN = nums[i].first;
        }
        if(maxN < nums[i].second) {
            maxN = nums[i].second;
        }
    }
    sort(nums.begin(), nums.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });
    // for(auto x : nums) {
    //     cout << x.first << " " << x.second << endl;
    // }
    int res = 0, ed = -2e9;
    for(int i = 0; i < sz; i++) {
        if(nums[i].first >= ed) {
            res++;
            ed = nums[i].second;
        }
    }
    return res;
}

int main() {
    vector<vector<string>> nums = {{"10:00", "12:00"}, {"03:00", "11:30"}, {"11:30", "14:00"}};
    int res = countMax(nums);
    cout << res << endl;
    return 0;
}