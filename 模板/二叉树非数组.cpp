#include <cstdio>
#include <vector>
using namespace std;
//声明结点
struct node
{
    int val;
    node *left;
    node *right;
};
//先序序列
vector<int> pre;
//中序序列
vector<int> in;
int n;
bool flag=false;
//构造二叉树
node *build(int preindex,int instart,int inend)
{
    node *root=NULL;
    int i;
    int mid=-1;
    for(i=instart;i<=inend;i++)
    {
        if(pre[preindex]==in[i])
        {
            mid=i;
            break;
        }
    }
    if(mid!=-1)
    {
        root=new node;
        root->val=pre[preindex];
        root->left=build(preindex+1,instart,mid-1);
        root->right=build(preindex+mid-instart+1,mid+1,inend);
    }
    return root;
}
//先序遍历二叉树
void traversal(node *root)
{
    if(root==NULL)
        return;
    if(flag)
        printf(" ");
    printf("%d",root->val);
    flag=true;
    traversal(root->left);
    traversal(root->right);
}
int main()
{
    scanf("%d",&n);
    int i;
    int t;
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        pre.push_back(t);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        in.push_back(t);
    }
    node *root=build(0,0,n-1);
    traversal(root);
    printf("\n");
    return 0;
}