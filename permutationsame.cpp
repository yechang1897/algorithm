#include<iostream>
#include<algorithm>
 
using namespace std;
 
int arry[3] = { 1,2,2 };
 
bool IsEqual(int s, int t)
{
	for (int i = s; i < t; i++)
		if (arry[i] == arry[t])
			return true;
 
	return false;
}
 
void Recursion(int s, int t)
{
	if (s == t)
		for_each(arry, arry + 3, [](int i) {printf("%d", i); }), printf("\n");
	else
	{
		for (int i = s; i <= t; i++)
		{
			if (!IsEqual(s, i))//不相等才能交换
			{
				swap(arry[i], arry[s]);
				Recursion(s + 1, t);
				swap(arry[i], arry[s]);
			}
		}
	}
}
 
int main()
{
 
	Recursion(0, 2);
 
	return 0;
}