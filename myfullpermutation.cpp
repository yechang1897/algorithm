#include<iostream>
#include<algorithm>
using namespace std;
int array[3] = {1, 2, 3};

void fullPermutation(int start, int end){
    if (start == end) {
        for_each(array, array + 3, [](int i) { cout << i; }), cout << endl;
    }
    for (int i = start; i <= end; i++) {
        swap(array[i], array[start]);
        fullPermutation(start + 1, end);
        swap(array[i], array[start]);
    }
}

int f(int n) {
    if (n <= 2) {
        return n;
    }
    // 加入f(n)的等价操作逻辑
    return n * f(n - 1);
}

int main(){
    fullPermutation(0, 2);
    // cout<< "result: " << f(5);
    return 0;
}