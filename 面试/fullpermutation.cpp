#include<iostream>
#include<vector>
using namespace std;

int n;
int num[10];
bool tong[10];

void dfs(int k)
{
    if(k == n + 1)
    {
        for(int i = 1;i <= n;++i)
            cout << num[i] << " ";
        cout << endl;

        return;
    }

    for(int i = 1;i <= n;++i)
    {
        if(tong[i] == 0)
        {
            num[k] = i;
            tong[i] = 1;

            dfs(k + 1);

            num[k] = 0;
            tong[i] = 0;
        }
    }
}

int main(void)
{
    cin >> n;

    dfs(1);

    return 0;
}