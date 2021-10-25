#include<iostream>

using namespace std;
typedef long long ll;
ll getMinSetup(ll a, ll b) {
    ll i = 1;
    ll sub = abs(a - b);
    ll t = 1;
    ll setup = 1;
    while(sub > i) {
        t++;
        i += t;
        setup++;
    }
    if(sub == i) return setup;
    int next = i;
    i -= t;
    int flag = min(next - sub, sub - i);
    cout << next <<" " << sub << endl;
    cout << setup << endl;
    if(sub - i < next - sub)
        setup--;
    cout << setup << endl;
    setup += 2 * (flag);
    return setup;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        cout << getMinSetup(a, b) <<endl;
    }
}