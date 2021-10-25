#include<iostream>

using namespace std;

int divide(int a, int b) {
    if( a==0 )//分子为0的情况
        return 0;

    if( a==INT_MIN && b==-1 )
        return INT_MAX;
    if( a==INT_MIN && b==1 )
        return INT_MIN;
    bool signal=(a>0) ^ (b>0); //预先判断结果的符号
    long long aPlus=abs(a);
    long long bPlus=abs(b);
    int ans=0;
    /*
        aPlus<bPlus返回0
        否则不断左移一位bPlus,直到bBlus刚好大于bPlus
    */
    while( aPlus >= bPlus ){
        int cnt=0;  //左移次数
        while( aPlus >= ( bPlus << cnt ) ){
            ++cnt;
        }
        //因为 bPlus * ( 1<<(cnt-1) )是小于aPlus的
        ans += ( 1<<(cnt-1)); //累加结果
        aPlus -= ( bPlus << (cnt-1) ); //更新aPlus
    }
    return signal ? -ans : ans;

}


int main() {
    long long a = -2147483648, b = 1;
    int flag = (a > 0 && b > 0) || (a < 0 && b < 0) ? 1 : -1;
    // cout << flag << endl;
    long long abs_a = abs(a);
    long long abs_b = abs(b);
    cout << abs_a << " " << abs_b << endl;
    long long ans = 0;
    if(abs_a < abs_b) cout << 0;
    while(abs_a >= abs_b) {
        abs_a -= abs_b;
        // cout << abs_a << endl;
        ans++;
    }
    cout <<  flag * ans;
    return 0;
}