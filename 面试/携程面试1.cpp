#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, K;
    cin >> n >> K;
    vector<int> nums(n + 1);

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums[i] = nums[i - 1] + t;
    }

    
    vector<int> res(2);
    int t = -1;
    for(int i = K; i <= n; i++) {
        for(int j = 0; j < n - i + 1; j++) {
            int k = j + i - 1;
            int temp = (nums[k] - nums[j - 1]) / i;
            cout << temp <<" "<< t << endl;
            if(temp > t) {                             
                res[0] = j;
                res[1] = k;
                t = (nums[k] - nums[j - 1]) / (i);  
            }  
            if(temp == t) { 
                cout << res[0] << " " << res[1] << endl;
                cout << j << " " << k << endl;               
                if(k - j > res[1] - res[0]) {
                    
                    res[0] = j;
                    res[1] = k;
                } else if(k - j == res[1] - res[0]) {
                    if(j < res[0]) {
                        res[0] = j;
                        res[1] = k;
                    }
                }
            }
        }        
    }
    cout << res[0] << " " << res[1] << endl;
    return 0;
}

/**
9 3
1 3 2 1 1 2 2 2 2
**/