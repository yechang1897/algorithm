#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100010;
int n, m;
int h[N], size1;

void down(int u) {
    int t = u;
    if(t * 2 <= size1 && h[u * 2] < h[t]) t = 2 * u;
    if(u * 2 + 1 <= size1 && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if(t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}

void up(int u) {
    while(u / 2 > 0 && h[u] < h[u / 2]) {
        swap(h[u], h[u / 2]);
        up(u / 2);
    }
}



// int findKthLargest(vector<int>& nums, int k) {
   
// }
//第k大用最小堆,第k小用最大堆。
 int findKthLargest(vector<int>& nums, int k) {
    // priority_queue<int, std::vector<int>, std::greater<int> > small_queue;
    priority_queue<int> max_queue;
    for(int i=0; i<nums.size(); ++i){
        if(i<k){
            max_queue.push(nums[i]);
        }
        else{
            if(nums[i]<max_queue.top()){
                max_queue.pop();
                max_queue.push(nums[i]);
            }
        }
    }
    for(int i = 0; i < k; i++) {
        cout << max_queue.top() << " ";
        max_queue.pop();
    }
    cout << endl;
    return max_queue.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    n = nums.size();
    m = 4;
    for(int i = 1; i <= n; i++) {
        h[i] = nums[i - 1];
    }
    size1 = n;
    for(int i = n / 2; i; i--) {
        down(i);
    }
    // for(int i = n / 2; i; i--) {
    //     down(i);
    // }
    // cout << findKthLargest(nums, 4);
    for(int i = 1; i <= size1; i++) {
        cout << h[i] << endl;
    }
    // while(m--) {
    //     cout << h[1] << endl;
    //     h[size1] = h[1];
    //     up(size1);
    //     size1--;
    // }
    // cout << h[1] << endl;

    // cout << findKthLargest(nums, k);
}