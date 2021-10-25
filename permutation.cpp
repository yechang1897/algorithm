
#include<iostream>
#include<algorithm>
 
using namespace std;
 
int arry[5] = { 1,2,3,4,5 };//len==3;
 
void Permutation()
{
	int len = 5;
	int j, k;
 
	while (true)
	{
		printf("%d%d%d%d%d\n", arry[0], arry[1], arry[2],arry[3],arry[4]);
 
		for (j = len - 2; j >= 0 && arry[j] > arry[j + 1]; j--);//注意此处 j >= 0 判断条件在前
 
		if (j < 0) return;//结束
		
		for (k = len - 1; k > j&&arry[k] < arry[j]; k--);
 
		swap(arry[k], arry[j]);
 
		for (int l = j + 1, r = len - 1; l < r; l++, r--)
			swap(arry[l], arry[r]);
	}
}
 
int main()
{
 
	Permutation();
 
	return 0;
}