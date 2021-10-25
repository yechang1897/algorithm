#include<iostream>

using namespace std;

int res = 0;


// 思想：一直往深处走，直到找到解或者走不下去为止

// 主要步骤：
// 1．构建一个递归函数，函数参数应该最起码包括题目需求使用的参数
// 2．找到边界，递归函数里首先列出递归结束的条件，即满足要求或者超出范围
// 3．接着列出所有可能移动或者变化的路径


// void dfs(int step,...)
// {
//     if(走不下去了)  // 判断边界
//       {   
//           相应操作；
//        }
//     // 枚举每一种可能
//    if(满足条件)  dfs(step+1,...)；
//    if(满足条件)  dfs(step-2,...)；
//  }  

void dfs(int n, int step){
    if(n < 0)
        return;
    if (n == 0 && step % 2 == 0) {
        res++;
    }
    dfs(n - 1, step + 1);
    dfs(n - 2, step + 1);
}

int main() {
    dfs(39, 0);
    cout << res;
}

