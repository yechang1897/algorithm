#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    for (int i = 0; i <= (int)nums.size() - k; i++) {
        vector<int>::iterator it = nums.begin();
        cout << *(it + i) << " " << *(it + i + k - 1) << endl;
        int tempMax = *max_element(it + i, it + i + k);
        res.push_back(tempMax);
    }
    return res;
}

vector<int> maxSlidingWindow_2(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    int n = (int)nums.size();
    if (n == 0 || k > n) {
        return res;
    }
    for (int i = 0; i < n; i++) {
       if (!dq.empty()) {
           if (i >= dq.front() + k) {
               dq.pop_front();
           }
           while (!dq.empty() && nums[dq.back()] < nums[i]) {
               dq.pop_back();
           }
       }
       dq.push_back(i);
       if (i >= k - 1) {
           res.push_back(nums[dq.front()]);
       }
    }
    return res;
}

vector<int> maxSlidingWindow_3(vector<int>& nums, int k){
        vector<int> f;
        int n = nums.size();
        if(n == 0 || k > n)
            return f;
        deque<int> que;
        for(int i = 0; i < n; i++){
            if(!que.empty()){
                if(i >= que.front() + k)
                    que.pop_front();
                while(!que.empty() && nums[i] >= nums[que.back()])
                    que.pop_back();
            }
            que.push_back(i);
            if(i+1 >= k)
                f.push_back(nums[que.front()]);
        }
        return f;
}


int main(){
    vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
    // vector<int> vec = {1, -1};
    for(int i : maxSlidingWindow_2(vec, 3)) {
        cout << i << " ";
    }
    cout << endl;
}