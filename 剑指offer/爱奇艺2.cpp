#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    
    while(true) {
        string str;
        getline(cin, str);
        if(str.size() == 0) break;
        vector<int> nums;
        int t = 0;
        int sz = str.size();
        for(int i = 0; i < sz; i++) {
            if(str[i] == ',') {
                nums.push_back(t);
                t = 0;
            } else {
                t *= 10;
                t += str[i] - '0';
            }
        }
        nums.push_back(t);
        int n = nums.size();
        if(n == 2) {
            cout << (int)abs(nums[0] - nums[1]) << endl;
            continue;
        }

        int res = 0;
        int last = nums[0];
        int flag = nums[1] > nums[0] ? 1 : 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1] && flag == 1) {
                res = max(res, abs(last - nums[i - 1]));
                last = nums[i - 1];
                flag = 0;
            } else if(nums[i] > nums[i - 1] && flag == 0) {
                res = max(res, abs(last - nums[i - 1]));
                last = nums[i - 1];
                flag = 1;
            }
        } 
        res = max(res, abs(nums[n - 1] - last));
        cout << res << endl;
    }
    return 0;
}