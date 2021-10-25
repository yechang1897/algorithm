#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n) { //middle
	long long stop = sqrt(n) + 1;
	if (n == 2) {
		return 1;
	}
	if (n % 2 == 0) {
		return 0;
	}
	for (int i = 3; i <= stop; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int fun(int x) {
    int f = 1;
    while(!isPrime(f) || f - 1 < x) {
        f++;
    }
    int t = f;
    while(!isPrime(t) || t - f < x) {
        t++;
    }
    //cout << f << " " << t << endl;
    return f * t;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int x;
        cin >> x;
        cout << fun(x) << endl;
    }
    return 0;
}