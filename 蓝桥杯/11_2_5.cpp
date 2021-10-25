#include <cstdio>
#include <cstring>
struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
}a,b;
bign add(bign &a, bign &b){
	bign c;
	int carry = 0;
	for(int i=0; i<a.len||i<b.len; i++){
		int temp = a.d[i]+b.d[i]+carry;
		c.d[c.len++] = temp%10;
		carry = temp/10;
	}
	if(carry){
		c.d[c.len++] = carry;
	}
	return c;
}
bign multi(bign &a, int &b){
	bign c;
	int carry = 0;
	for(int i=0; i<a.len; i++){
		int temp = a.d[i]*b + carry;
		c.d[c.len++] = temp%10;
		carry = temp/10; 
	}
	while(carry){
		c.d[c.len++] = carry%10;
		carry /= 10;
	}
	return c;
}
void print(bign &a){
	for(int i=a.len-1; i>=0; i--){
		printf("%d",a.d[i]);
	}
	printf("\n");
}
bool vis[10]={false};
	
bool judge(bign &c){
	for(int i=0;i<=c.len-1; i++){
		if(!vis[c.d[i]]) return false;
	}
	return true;
}
int main()
{
	vis[0]=vis[1]=vis[4]=vis[9]=true;
	b.d[0]=1,b.len=1;
	a.d[0]=0,a.len=1;
	int num=0;
    bign c;
	for(int i=0; num<2020; i++){
		c = multi(a,i); 
		if(judge(c)){
			num++;
			// printf("%d:",num);
			// print(c);					
		}
		a = add(a,b);
	}
	print(c);
	return 0;
}