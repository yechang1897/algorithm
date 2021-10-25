#include<iostream>

using namespace std;

const int N = 100010;
int n;
int q[N], s[N];

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
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    int res = 0;
    for(int i = 0, j = 0; i < n; i++) {
        s[q[i]]++;
        while(j < i && s[q[i]] > 1) s[q[j++]]--;
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}