#include<stdio.h>
int main()
{
    int i, j=5;
    for(i = 1;i < 40; i++ ){
        if ((i * j) % 26 == 1) {
            printf("%d",i * j);
        }
    }
    return 0;
}