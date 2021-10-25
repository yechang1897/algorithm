#include <stdio.h>
struct p
{
    char x:2;
    int y:2;
};
 
int main()

{
    
    /* 我的第一个 C 程序 */
    struct p p;
    p.x=2;
    p.y=1;
    p.x=p.x&p.y;
    
    printf("%d",p.x);
 
    return 0;
}