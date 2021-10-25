#include<iostream>
using namespace std;
const int N=100010;
int idx,head,n[N],ne[N],a;

void add_head(int x){
    n[idx]=x;
    ne[idx]=head;
    head=idx++;
}
void add(int k,int x){
    n[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
void remove(int k){
    ne[k]=ne[ne[k]];
}

int main(){

    head=-1;idx=0;
    cin>>a;
    while(a--){
        string op;
        int k,x;
        cin>>op;
        if(op=="D")
        {

            cin>>k;
            if(!k)head=ne[head];
            remove(k-1);
        }
        else if(op=="H")
        {
            cin>>x;
            add_head(x);
        }
        else if(op=="I"){
            cin>>k>>x;
            add(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i])
      cout<<n[i]<<" ";
    return 0;

}

/**
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
**/