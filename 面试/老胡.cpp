#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include <string.h>
using namespace std;

// int f(vector<int>& nums) {
//     stack<int> stk;
//     vector<int> temp;
//     int sz = nums.size();
//     for(int i = sz - 1; i >= 0; i--) {
//         stk.push(nums[i]);
//     }
//     while(stk.size() > 2) {
//         while(stk.size()) {
//             int a = stk.top(); stk.pop();
//             int b = stk.top(); stk.pop();
//             temp.push_back(a + b);       
//             if(stk.size() == 1) {
//                 temp.push_back(stk.top());
//                 stk.pop();
//             }     
//         }
//         cout <<"sz:" << sz << endl;
//          for(auto x : temp) {
//             cout << x <<" ";
//         }
//         cout << endl;
//         reverse(temp.begin(), temp.end());
//         for(auto x : temp){
//             stk.push(x);
//             // cout << x << " ";
//         }
//         temp.clear();
//         // cout << endl;
//         // cout <<temp.size() <<endl;
//         sz /= 2;        
//     }
//     // cout << stk.size() << endl;
//     int a = stk.top(); stk.pop();
//     int b = stk.top(); stk.pop();
//     return a * a + b * b;
// }

// int main() {
//     vector<int> nums = {1,2,3,4,5};
//     cout << f(nums);
// }

// int get(int X, int Y) {
//     int t = X;
//     int res = 0;
//     while(t <= Y) {
//         t *= 2;
//         res++;
//     }
//     return res;
// }

const int N = 1e5 + 10;
int f[N][N];
int e[N];
int res;
int tmp = 0;

int dfs(int i, int no) {
    if(f[i][no] != 0) return f[i][no];
    if(i == n) {
        //判断是最后一颗子弹。
        if(no % 4 == 0){
            res = max(res, f[i]);
        }
        return f[i][no];
    }
    //没选
    dfs(i + 1, no);
    //选了
    if(no % 4 == 0) {
        tmp += 2 * e[i];
        f[i + 1][no + 1] = dfs(i + 1, no + 1);
        tmp -= 2 * e[i];
    }
    tmp +=  e[i];
    f[i + 1][no + 1] = dfs(i + 1, no + 1);
    tmp -= e[i];
    }
}

int main() {
    // long long  X, Y;
    // cin >> X >> Y;
    // long long t = X;
    // int res = 0;
    // while(t <= Y) {
    //     t *= 2;
    //     res++;
    // } 
    // cout << res << endl;

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> e[i];
    }

    for(int i = 2; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        
    }
}