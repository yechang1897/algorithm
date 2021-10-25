#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=100010,M=2*N;
int n;
int h[N],e[M],ne[M],idx;
int ans=N;
bool st[N];
void add(int a,int b)
{
  e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u)
{
    st[u]=true;
    int size=0,sum=0;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(st[j]) continue;
        int s=dfs(j);
        size=max(size,s);
        sum += s;
    }
    size=max(size,n-sum-1);
    ans=min(ans,size);
    return sum+1;
}

void travel(int r) {
    for(int i = h[r]; i != -1; i = ne[i])
        cout << "i:" << i << " " << e[i];
}

int main()
{
  cin>>n;
  memset(h,-1,sizeof h);
  for(int i=0;i < n - 1;i++)
  {
    int a,b;
    cin>>a>>b;
    add(a,b);
    add(b,a);
  }
  // travel(1);  
  dfs(1);
  cout<<ans<<endl;
  return 0;
}