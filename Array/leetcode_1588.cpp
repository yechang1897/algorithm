#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int s = (int)arr.size();
    int res = 0;
    for (int i = 1; i <= s; i += 2) {
        for (int j = 0; j < s - i + 1; j++) {
            for (int k = j; k < j + i; k++) {
                // cout << "arr[k]:" << arr[k] << endl;
                res += arr[k];
                // cout <<"res :"<<res << endl;
            }
        }
    }
    return res;
}

//前缀数组
int sumOddLengthSubarrays_2(vector<int>& arr) {
    int s = (int)arr.size();
    int res = 0;
    vector<int> prefix{0};
    for(int e : arr) {
        prefix.push_back(prefix.back() + e);
    }
    for (int i = 1; i <= s; i += 2) {
        for (int j = 0; j < s - i + 1; j++) {
            res += prefix[j + i] - prefix[j];
        }
    }
    return res;
}

int sumOddLengthSubarrays_3(vector<int>& arr) {
    int res = 0;
    for(int i = 0; i < arr.size(); i ++){
        int left = i + 1, right = arr.size() - i,
            left_even = (left + 1) / 2, right_even = (right + 1) / 2,
            left_odd = left / 2, right_odd = right / 2;
        res += (left_even * right_even + left_odd * right_odd) * arr[i];
    }
    return res;
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};
    cout << sumOddLengthSubarrays_3(arr);
}