#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>

using namespace std;

double n;


double search(double l, double r) {
    const double eps = 1e-6;
    while(r - l > eps) {
        double mid = (l + r) / 2 ;
        if(mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    return l;
}

int main() {
    cin >> n;
    double l = -10000,r = 10000;
    cout << fixed << setprecision(6) << search(l, r);
}