#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void add(vector<int> &A,vector<int> &B, vector<int>& result)
{

    int t=0;//进位
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    for(int i=0;i < A.size() || i < B.size();i++)
    {
        if(i<A.size()) t+=A[i];//如果i小于A的总长度的话，那么就将sum加上A的这一位的数
        if(i<B.size()) t+=B[i];//如果i小于B的总长度的话，那么就将sum加上B的这一位的数
        result.push_back(t%10);//保证sum不大于10
        t/=10;//把各位去掉
    }
    if(t) result.push_back(1);//如果最后还有数的话，那么它就一定是1
    reverse(result.begin(), result.end());
}

// int solution(int * nums1, int len1, int * nums2, int len2, int * result) {
//     vector<int> A;
//     for (int i = 0; i, len1; i++) {
//         A.push_back(nums1[i]);
//     }
//     vector<int> B;
//     for (int i = 0; i < len2; i++) {
//         B.push_back(nums2[i]);
//     }
//     vector<int> C = add(A, B);
//     int res = C.size();
//     cout << res << endl;
//     int flag = 0;
//     for (int i = res - 1; i >= 0; i--) {
//         result[flag++] = C[i];
//     }
//     cout << res << endl;
//     return res;
// }

int main() {
    vector<int> A = {5, 1};
    vector<int> B = {5, 2};
    vector<int> C;
    add(A, B, C);
    for(auto x : C) {
        cout << x << " ";
    }
    // return 0;
    // int nums1[2] = {1, 5};
    // int nums2[2] = {2, 5};
    // int *p1, *p2;
    // p1 = nums1, p2 = nums2;
    // // cout << nums1[0] << " " << nums2[0] << endl;
    // int* result1;
    // int len = solution(p1, 2, p2, 2, result1);
    // cout << len << endl;
    // for (int i = 0; i < len; i++) {
    //     cout << result1[i] << " ";
    // }
    // return 0;
}