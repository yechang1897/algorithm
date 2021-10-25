#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k, H;
    cin >> n >> k >> H;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int res = 0;
    vector<pair<int,int>> arr;
    arr.push_back(make_pair(nums[0], 1));
    // arr[0].first = nums[0];
    // arr[0].second = 1;
    int p = 0;
    int total = 1;
    if(k == 1){
        cout << min(n, H);
        return 0;
    }
    for(int i = 1; i < n; i++) {
        if(nums[i] == arr[p].first) {
            cout << "test1" << endl;
            arr[p].second++;
            total++;
            if(total == H) break;
            if(arr[p].second == k) {
                res++;
                arr.pop_back();
                p--;
                total -= k;
            }
        } else {
            cout << "test2" << endl;
            arr.push_back(make_pair(nums[i], 1));
            p++;
            total++;
            if(total == H) break;
        }
    }
    cout << res << endl;
}
