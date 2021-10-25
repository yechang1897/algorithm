#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    int nums[10] = {6, 7, 9, 10, 11, 2, 6, 13, 12, 1};
    sort(nums, nums + 10);
    for(int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    priority_queue<int> heap;
    for(int i = 0; i < 10; i++) {
        if(heap.size() < 5) heap.push(nums[i]);
        else {
            if(heap.top() >  nums[i]){
                heap.pop();
                heap.push(nums[i]);
            } 
        }
    }
    cout << heap.top();
    return 0;
}