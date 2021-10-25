#include<iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int count(int n)
{
    int s = 1;
    for(int i = 2 ; i * i <= n ; i++)
    {
        if(n % i == 0)
        {
            int a = 0 ;
            while(n % i == 0)
            {
                n /= i;
                a++;
            }
            s = s * (a+1) ;
        }
    }
    if(n > 1) s = s * 2;
    return s;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int t;
        cin >> t;
        cout << count(t) << endl
    }
}