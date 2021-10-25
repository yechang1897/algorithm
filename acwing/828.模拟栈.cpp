#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1e5+10;
int stk[N],tt,m;
int main()
{
  cin>>m;
  while(m--)
  {
    string op;
    int x;
    cin>>op;
    if(op=="push")
    {
      cin>>x;
      stk[++tt]=x//向栈顶插入一个数;
    }
    else if(op=="pop")tt--;//从栈顶弹出一个数
    else if(op=="empty")cout<<(tt?"NO":"YES")<<endl;
    else cout<<stk[tt]<<endl;
  }
  return 0;
}