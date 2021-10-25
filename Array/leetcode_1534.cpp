#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int i, j, k;
    int sz = (int)arr.size();
    int res = 0;
    for (i = 0; i < sz - 2; i++) {
        for (j = i + 1; j < sz - 1; j++) {
            for (k = j + 1; k < sz; k++) {
                if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                    res++;
                }
            }
        }
    }
    return res; 
}

int countGoodTriplets_2(vector<int>& arr, int a, int b, int c) {
    int ans = 0, n = arr.size();
    vector<int> sum(1001, 0);
    for (int j = 0; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
            if (abs(arr[j] - arr[k]) <= b) {
                int lj = arr[j] - a, rj = arr[j] + a;
                int lk = arr[k] - c, rk = arr[k] + c;
                int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
                if (l <= r) {
                    if (l == 0) {
                        ans += sum[r];
                    }
                    else {
                        ans += sum[r] - sum[l - 1];
                    }
                }
            }
        }
        for (int k = arr[j]; k <= 1000; ++k) {
            ++sum[k];
        }
    }
    return ans;
}

int main() {
    vector arr = {3,0,1,1,9,7};
    int a = 7, b = 2, c = 3;
    cout << countGoodTriplets_2(arr, a, b, c);
}