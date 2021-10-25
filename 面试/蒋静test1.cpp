#include<iostream>
#define Area(m, n) m + n

using namespace std;

int main() {
    int res = Area(2, 3) * Area(4, 5);
    cout << res << endl;
    return 0;
}