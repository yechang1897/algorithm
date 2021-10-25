#include<iostream>

using namespace std;

double myPow(double x, long n) {
    if(n==0)   return 1;
    if(n<0)    //这里提前进行预处理
        x=1/x,n=-n;
    double result=1;
    while(n>0){
        if(n&1)   result*=x;
        n>>=1;    //若n小于0，且前面没有n=-n这一步，就不能这么写了，要换成n/=2
        x*=x;
    }
    return result;
}

int main() {
    double x = 2.0;
    long n = -2;
    cout << myPow(x, n);
    return 0;
}