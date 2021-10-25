#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

typedef long long ll;

int sz(int const & n) {
  return __builtin_popcount(n);
}

struct comp {
  bool operator()(int const & a, int const & b) const {
    return sz(a) >= sz(b);
  }
};


int main() {
    // int n;
    // cin >> n;
    // vector<ll> nums(n + 1);
    // set<ll> s1;
    // long long ans = 0;
    // for(int i = 1; i <= n; i++) {
    //     cin >> nums[i];
    //     cout << *s1.upper_bound(nums[i]) << endl;
    //     cout << *s1.lower_bound(nums[i]) << endl;
    //     ans += *s1.upper_bound(nums[i]) * i;
    //     s1.insert(nums[i]);
    // }
    // cout << ans << endl;
    set<int, comp> s;
    for(int i = 1; i <= 10; i++) s.insert(i * 10);
    cout << *s.lower_bound(29) << endl;
    cout << *s.upper_bound(29) << endl;
    return 0;
}