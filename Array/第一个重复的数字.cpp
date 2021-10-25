#include<iostream>
#include <float.h>
using namespace std;

int sqrt(int A) {
    int l = 0, r = A;
    while(l < r) {
        int m = l + r >> 1;
        if(m * m >= A) r = m;
        else l = m + 1; 
    }
    return r;
}

double sqrtD(double A) {
    double l = 0.0, r = A + 0.25, m;
    while(l < r) {
        m = (l + r) / 2;
        if(m - l < DBL_EPSILON || r - m < DBL_EPSILON) break;
        if((m*m - A)*(l*l - A) < 0) r = m;
        else l = m;
    }
    return m;
}

int main() {
    // int a[7] = {1,3,1,0,2,5,3};
    // for(int i = 0; i < 7; i++) {
    //     if(a[a[i] % 7] >= 7) {
    //         cout << a[i] % 7 << endl;
    //         break;
    //     } else {
    //         a[a[i] % 7] += 7;
    //     }
    // }

    cout << sqrtD(7) << endl; 
    return 0;

}