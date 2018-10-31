#include <bits/stdc++.h>

using namespace std;


const int SIZE  = 1E4+5;
deque<int> a[SIZE];
int n,m;
bool check[SIZE];
int Curr;
void Input()
{
    cin>> n >> m;
    int x,y;
    for(int i=1;i <=m ;i++)
    {
        cin >>x >> y;
        a[x].push_back(y);
    }
}
void dfs(int u)
{
    check[u]=true;
    for(int i=0;i<a[u].size();i++)
    {

        int v=a[u][i];
        if(check[v]==false)
            {
                Curr++;
                dfs(v);
            }
    }
}
void Solve()
{
    for(int i=1;i<=n;i++)
    {
        memset(check,false,sizeof check);
        Curr=0;
        dfs(i);
        cout<<Curr<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DAG.INP","r",stdin);
    freopen("DAG.OUT","w",stdout);
    Input();
    Solve();
    return 0;
}
