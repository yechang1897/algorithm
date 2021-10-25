#include<iostream>
#include<algorithm>

using namespace std;

int a[100000];
int nums[10000];
int n;
int q;


int search1(int l, int r, int t) {    
    while(l < r) {
        int mid = l + r >> 1;
        if(a[mid] > t) r = mid;
        else l = mid + 1;
    }
    return l;
}

int search2(int l, int r, int t) {
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(a[mid] < t) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    cin >>n>>q;
    // cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> nums[i];
    }
    for(int i = 0; i < q; i++) {
        int l = search2(-1, n, nums[i]) + 1;
        int r = search1(-1, n, nums[i]) - 1;
        if(a[l] == nums[i] && a[r] == nums[i])  cout << l << " " << r << endl;
        else cout << -1 << " " << -1 << endl;
    }
    // cout << search1(-1, 6, 1) << endl;
    // cout << search2(-1, 6, 1) << endl;
    // cout << search1(-1, 6, 6) << endl;
    // cout << search2(-1, 6, 6) << endl;
}