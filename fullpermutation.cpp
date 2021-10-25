#include<iostream>
#include<algorithm>
 
using namespace std;
 
// int arry[4] = { 2,3,5,7 };
int arry[4] = { 3,7,12,19 };

 
void Recursion(int s, int t)
{
	if (s == t)
		for_each(arry, arry + 4, [](int i) {printf("%d ", i); }), printf("\n");
	else
	{
		for (int i = s; i <= t; i++)
		{
			swap(arry[i], arry[s]);
			Recursion(s + 1, t);
			swap(arry[i], arry[s]);
		}
	}
}
 
int main()
{
 
	Recursion(0, 3);
    // next_permutation(arry, arry + 3);
    // for_each(arry, arry + 3, [](int i) { cout << i; }), cout << endl;
    return 0;
}
