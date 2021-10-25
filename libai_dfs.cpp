#include <iostream>
using namespace std;
int ans=0;
//分析：运用DFS算法，当遇见店时酒乘一倍，遇见花时酒减1，直到店和花都为0时，输出酒的数值。
void dfs(int dian,int hua,int jiu){
    if(dian==0 && hua==0 && jiu==1){//出口 
        ans++;
    } 
    //枚举可能情况 
    if(dian>0) dfs(dian-1,hua,jiu*2);
    if(hua>0)  dfs(dian,hua-1,jiu-1);
}

int main(){   
    dfs(5,9,2);
    cout<<ans;
     return 0;
}