#include<iostream>
#include<string>
#include<cmath>
using namespace std;
//26进制
typedef long long ll;
/*
a = 26, 3;
17576
*/
ll fastpow(ll a, ll n)//快速幂算法，a的n次方
{
	ll base = a;
	ll power = n;
	ll result = 1;
	while (power)
	{
		if (power & 1)//位运算判断奇偶性，若n为偶数则返回0
		{
			result = result * base;//如果指数为奇数,把指数为奇数时分离出来的底数的一次方收集好
		}
		base = base * base;//底数变大成原来的平方
		power >>= 1;//此处等价于power=power/2
	}
	return result;
}

int main() {
    string str = "LANQIAO";
    long long int res = 0;
    int digit = 0;
    for(long long int i = str.size() - 1; i >= 0 ; i--) {
        int t = str[i] - 'A' + 1;
        res += t * pow(26, digit++);
        cout << "t: " << t << "res: " << res << endl;
    }
    cout << res << endl;
}

/*
res = 3725573269
3725573269
*/