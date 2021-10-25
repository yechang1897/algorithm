#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/**
9 3
1 3 2 1 1 2 2 2 2
**/

int main() {
    int n, K;
    cin >> n >> K;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        nums[i] = nums[i - 1] + t;

    }

    // for(auto x : nums) {
    //     cout << x << " ";
    // }
    // cout << endl;

    int l = 0,  r = 0;
    double avg = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + K - 1; j <= n; j++) {
            int t = nums[j] - nums[i - 1];
            double tavg = (double)t / (j - i + 1);
            if(tavg > avg) {
                l = i;
                r = j;
                avg = tavg;
            } else if(tavg == avg) {
                if(j - i == r - l) {
                    if(i < l) {
                        l = i;
                        r = j;
                    }
                } else if(j - i > r - l) {
                    l = i;
                    r = j;
                }
            }
            
        }
    }

    cout << l - 1 << " " << r - 1 << endl;
    return 0;
















    /**
    double f[n][n];
    memset(f, 0.0, sizeof f);
    for(int i = 0; i < n - K + 1; i++) {
        int temp = 0;
        for(int j = i; j < i + K; j++) {
            temp += nums[j];
        }
        f[i][i + K - 1] = temp;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + K; j < n; j++) {
            // double d1 = (f[i][j - 1] / (j - i));
            // cout <<nums[j] << " "<<d1 << endl;
            // cout << (nums[j] >= d1) << endl;
            if(nums[j] >= (f[i][j - 1] / (j - i))) f[i][j] = f[i][j - 1] + nums[i];
            else break;
        }
    }

    int l = 0, r = 0;
    double avg = 0.0;
    for(int i = 0; i < n; i++) {
        for(int j = i + K - 1; j < n; j++) {
            double t = f[i][j] / (j - i + 1);
            if(t > avg) {
                l = i, r = j;
                avg = t;
            } else if(t == avg) {
                if(r - l == j - i) {
                    if(i < l) {
                        l = i, r = j;
                    }
                } else if(j - i > r - l) {
                    l = i;
                    r = j;
                }
            }
        }
    }
    cout << l << " " << r << endl;
    return 0;
    **/
}