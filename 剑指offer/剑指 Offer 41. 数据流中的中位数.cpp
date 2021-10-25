#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;
int mid = 0;

void addNum(int num) {
    if(mid == 0) {
        mid = num;
        return;
    }

    if(num < mid) {
        maxHeap.push(num);
    } else if(num >= mid){
        minHeap.push(num);
    }
    int gap = (int)maxHeap.size() - minHeap.size();
    if(abs(gap) > 1) {
        if(maxHeap.size() > minHeap.size()) {
            minHeap.push(mid);
            mid = maxHeap.top();
            maxHeap.pop();
        } else {
            maxHeap.push(mid);
            mid = minHeap.top();
            minHeap.pop();
        }
    }
}
    
double findMedian() {
    if(minHeap.size() == maxHeap.size()) return mid;
    else if(minHeap.size() > maxHeap.size()) {
        return (double) (minHeap.top() + mid ) / 2;

    } else {
        return (double) (maxHeap.top() + mid) / 2;
    }
}
/*
1,2,3
*/
int main() {
    addNum(1);
    addNum(2);
    addNum(3);
    cout << findMedian() << endl;
    return 0;
};