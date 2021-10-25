#include<iostream>
#include<algorithm>

using namespace std;

int no;
int k;
int nums[22] = {0};
int p[22] = {0};
bool visit[22] = {0};
int res = 0;
int sum = 0;

bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
//全排列但是会重复
void dfs(int begin, int end) {
    if (end == begin) {
        for_each(nums, nums + 4, [](int i) { cout << i << " "; }), cout << endl;
        // int sum = 0;
        // for (int i = 0; i < k; i++) {
        //     sum += nums[i];
        // }
        // if(isprime(sum)) {
        //     res++;
        // }
    }else {
        for (int i = begin; i <= end; i++) {
            swap(nums[i], nums[begin]);
            dfs(begin + 1, end);
            swap(nums[i], nums[begin]);
        }
    }
    
}
//使用visit数组，不会重复
void dfs_2(int index) {
    if (index == k + 1) {
        if(isprime(sum)) {
            res++;
        }
        for_each(p, p + index, [](int i) { cout << i <<" "; }), cout << endl;
        return;
    }
    for (int i = 1; i <= no; i++) {
        if(visit[i] == false && i > p[index - 1]) {
            p[index] = i;
            visit[i] = true;
            sum += nums[i];
            dfs_2(index + 1);
            sum -= nums[i];
            visit[i] = false;
        }
    }
}


int main() {
    cin >> no >> k;    
    for (int i = 1; i <= no; i++) {
        cin >> nums[i], p[i] = i;
    }
    // cout << isprime(29) << endl;
    dfs_2(1);
    cout << res;
}