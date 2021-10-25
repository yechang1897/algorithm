#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int divide(int dividend, int divisor) {
	// prevent integer overflow
	if (divisor == 0 || ((dividend == INT_MIN) && (divisor == -1)))
		return INT_MAX;

	bool resNeg = (dividend < 0) ^ (divisor < 0);
    dividend = (0 < dividend) ? -dividend : dividend; // to neg
	if (divisor == INT_MIN)
		return dividend == INT_MIN;
	divisor= (0 < divisor) ? divisor: -divisor; // to pos
	if (dividend == INT_MIN) {
		for (int i=0; i<32; i++)
			if (divisor == (1 << i))
		return INT_MIN >> i;
	} // Below method cannot be applied to divisors that are multiples of 2
	// because "divisor << ls" is bigger than INT_MAX when "dividend + cur" is 0.

	int res = 0;
	for (int ls=31; 0<=ls; ls--) { // ls: left shift
		if ((INT_MAX >> ls) < divisor) // same effect with "INT_MAX < (divisor << ls)"
			continue;
		int cur = divisor << ls;
        if (dividend + cur <= 0) {
			dividend += cur;
		    res += 1 << ls;
		}
	}
	return resNeg ? -res : res;
}

int divide_2(int dividend, int divisor) {
	bool signA = dividend >= 0, signB = divisor > 0;
 
	unsigned num = abs(dividend), div = abs(divisor), res = 0, curr = 0;
	// using Long division
	for (int idx = 31; idx >= 0; idx--) {
		curr <<= 1;
		curr |= ((num >> idx) & 1);
 
		res = res << 1;
		if (curr >= div) {
			curr -= div;
			res |= 1;
		}
	}
 
	if (signA ^ signB)
		return -(int)res;
	return (int)res;
 
}

int main() {
    cout << divide_2(10, 3) << endl;
}