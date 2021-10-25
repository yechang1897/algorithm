#include<iostream>
#include<vector>
using namespace std;

const int N = 3e4 + 5;
int l[N];
int r[N];

int trap(vector<int>& height) {
    int sz = height.size();
    l[0] = height[0];
    for(int i = 1; i < sz; i++) l[i] = max(l[i - 1], height[i]);
    r[sz - 1] = height[sz - 1];
    for(int i = sz - 2; i >= 0; i--) r[i] = max(r[i + 1], height[i]);
    int res = 0;
    for(int i = 0; i < sz; i++) res += min(l[i], r[i]) - height[i];
    
    for(int i = 0; i < sz;i++) {
        cout << l[i] << " " << r[i] << endl;
    }
    return res;
}

int main() {
    vector<int> height = {4,3,2,1,0};
    cout << trap(height);
    return 0;
}