#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int A[N], B[N];
int n, m, x;
/*
for (int i = 0, j = 0; i < n; i ++ )
{
    while (j < i && check(i, j)) j ++ ;

    // 具体问题的逻辑
}
常见问题分类：
    (1) 对于一个序列，用两个指针维护一段区间
    (2) 对于两个序列，维护某种次序，比如归并排序中合并两个有序序列的操作
*/

int main() {
    cin >> n >> m >> x;
    for (int i=0;i<n;i++) cin>>A[i];
    for (int i=0;i<m;i++) cin>>B[i];
    for(int i = 0, j = m - 1; i < n; i++) {
        while(j >= 0 && A[i] + B[j] > x) j--;
        if(A[i] + B[j] == x) {
            cout << i << " " << j << endl;
            break;
        }
    }
    return 0;
}