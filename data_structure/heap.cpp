#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int tree[1000001];

int number = 0;

void push(int x)
{
    number ++;
    tree[number] = x;
    int nb = number;
    while(nb > 1)
    {
        int nxt = nb / 2;
        if(tree[nxt] > tree[nb])
        {
            swap(tree[nxt], tree[nb]);
            nb = nxt;
        }
        else
        {
            return ;
        }
    }
}

int top()
{
    return tree[1];
}

int pop()
{
    swap(tree[1], tree[number]);
    number --;
    int tis = 1, nxt = 0;
    while(tis * 2 <= number)
    {
        nxt = tis * 2;
        if(nxt + 1 <= number &&  tree[nxt + 1] < tree[nxt] )
        {
            nxt ++;
        }
        if(tree[nxt] < tree[tis])
        {
            swap(tree[nxt], tree[tis]);
            tis = nxt;
        }
        else
        {
            break;
        }

    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int t = n;
    while(t -- )
    {
        int opt;
        scanf("%d", &opt);
        push(opt);
    }
    cout << " test " << endl;
    for(int i = 0; i < n; i++) {
        cout << tree[i] << endl;
    } 
    for(int i = 1; i <= n; i ++ )
    {
        printf("%d ", top());
        pop();
    }
    return 0;
}

// 作者：smallfang
// 链接：https://www.acwing.com/blog/content/3345/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。