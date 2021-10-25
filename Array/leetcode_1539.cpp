#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int sz = (int)arr.size();
    int end = arr[sz - 1] + k;
    cout << end << endl;
    int flag = 0;
    int res = 0;
    for (int i = 1; i <= end; i++) {
        if(flag == sz || i != arr[flag]) {
            k--;
        } else {
            flag++;
            cout << flag << endl;
        }
        if (k == 0) {
            res = i;
            break;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1,2,3,4};
    int k = 2;
    cout << findKthPositive(arr, k);
}