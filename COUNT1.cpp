#include <bits/stdc++.h>

using namespace std;
ifstream fin("COUNT1.INP");
ofstream fout("COUNT1.OUT");
const int SIZE = 1E5 +5 ;
int a[SIZE];
int n;

void Input()
{
    cin>>n;
    int x;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        a[i]=a[i-1]+(x%2);
    }
}
void Solve()
{
    int res=0;
    int oddn=0;
    int evenn=0;
    for(int i=1; i<=n; i+=2)
    {
        if(a[i-1]%2==0)
            evenn+=1;
        else
            oddn+=1;
        if(a[i]%2==0)
            res+=evenn;
        else
            res+=oddn;
    }

    oddn=0;
    evenn=0;
    for(int i=2; i<=n; i+=2)
    {
        if(a[i-1]%2==0)
            evenn+=1;
        else
            oddn+=1;
        if(a[i]%2==0)
            res+=evenn;
        else
            res+=oddn;
    }
    cout<<res;
}
int main()
{

   // freopen("COUNT1.INP","r",stdin);
   // freopen("COUNT1.OUT","w",stdout);
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    Input();
    Solve();
    return 0;
}
