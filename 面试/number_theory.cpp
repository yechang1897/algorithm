#include<iostream>

using namespace std;
//欧几里得函数
//求两个正整数的最大公约数，时间复杂度 O(logn)O(logn)。
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

//扩展欧几里得函数

/*
裴蜀定理：若 a,ba,b 是整数,且 (a,b)=d(a,b)=d，那么对于任意的整数 x,y,ax+byx,y,ax+by 都一定是 dd 的倍数，特别地，一定存在整数 x,yx,y，使 ax+by=dax+by=d 成立。

扩展欧几里得算法可以在 O(logn)O(logn) 的时间复杂度内求出系数 x,yx,y。
*/
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;
    return d;
}
//3. 线性筛素数
//可以在 O(n)O(n) 的时间复杂度内求出 1∼n1∼n 之间的所有质数
int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

/*
4. 欧拉函数
欧拉函数，一般记为 ϕ(n)ϕ(n)，表示小于等于 nn 的数中与 nn 互质的数的个数。
如果 n=pa11×pa22×…×pammn=p1a1×p2a2×…×pmam,
则 ϕ(n)=n(1−1p1)…(1−1pm)ϕ(n)=n(1−1p1)…(1−1pm).

欧拉函数的常用性质：

如果 n,mn,m 互质，则 ϕ(nm)=ϕ(n)ϕ(m)ϕ(nm)=ϕ(n)ϕ(m);
小于等于 nn，且与 nn 互质的数的和是 ϕ(n)×n/2ϕ(n)×n/2;
欧拉定理：如果 n,an,a 互质，且均为正整数，则 aϕ(n)≡1(mod n)aϕ(n)≡1(mod n);
下面的代码可以在 O(n)O(n) 的时间复杂度内求出 1∼n1∼n 中所有数的欧拉函数：

作者：yxc
链接：https://www.acwing.com/blog/content/28/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int primes[N], euler[N], cnt;
bool st[N];

// 质数存在primes[]中，euler[i] 表示
// i的欧拉函数
void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                euler[i * primes[j]] = euler[i] * primes[j];
                break;
            }
            euler[i * primes[j]] = euler[i] * (primes[j] - 1);
        }
    }
}
//快速幂乘法
int qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int a = 3, b = 7;
    int x = 0, y = 0;
    cout << gcd(a, b) << endl;
    cout << exgcd(a, b, x, y) << endl;
    cout << x << " " << y << endl;
}