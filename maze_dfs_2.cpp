#include<stdio.h>
#define N 1000//最大行列数
int mg[N][N];//存放迷宫图
int re[N][N];//记录之前是否走过
int n, m;//行，列
int dfs(int x, int y){//现在在(x,y)点
	if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || re[x][y] == 1 || mg[x][y] == 0) return 0;//走出界外或之前走过或遇到障碍
	if(x == n - 1 && y == m - 1) return 1;//走到终点
	re[x][y] = 1;//该点标记为走过
	int sum = 0;
	sum += dfs(x - 1, y);//向左走
	sum += dfs(x + 1, y);//向右走
	sum += dfs(x, y - 1);//向上走
	sum += dfs(x, y + 1);//向下走
	re[x][y] = 0;//该点还原为没有走过
	return sum;
}
int main(){
	int i, j;
	while(~scanf("%d%d", &n, &m)){//输入行列
		for(i = 0; i < n; i ++)
		{
			for(j = 0; j < m; j ++) scanf("%d", &mg[i][j]);//读入迷宫图
		}
		printf("%d\n", dfs(0, 0));//输出结果
	}
	return 0;
}