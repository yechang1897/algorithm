#include<iostream>
#include<algorithm>
#include<vector>

const int MAX_VALUE=0x3f3f3f3f;
using namespace std;


int coinChange(vector<int> &coins, int amount) {
    int result[amount+1];//+1表示我这里需要用到 amount
    result[0] = 0;
    for(int i = 1;i <= amount;i++){
        result[i] = MAX_VALUE; //先初始化为最大值，这里是考虑到了不存在硬币的情况
        for(int j = 0;j < coins.size();++j){
            if(i>= coins[j] && result[i-coins[j]] != MAX_VALUE){
                result[i] = min(result[i-coins[j]]+1,result[i]);//就是那条公式的一个转换
            }
        }
    }
    if(result[amount] == MAX_VALUE)
    {
        return -1;
    }else
    {
        return result[amount];
    }


}
 int main()
 {
     vector<int> coins;
     int m,n;
     cin >> n >> m;
     for(int i = 0;i < n;i++)
    {
        int tmpvalue;
        cin >> tmpvalue;
        coins.push_back(tmpvalue);
    }


    cout <<coinChange(coins,m)<< endl;

     return 0;

 }
