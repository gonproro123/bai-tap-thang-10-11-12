#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const int SIZE = 1e6+5;
const ull MOD = 1E9+7;
const int base = 31;
ull Hash_A[SIZE],Hash_B[SIZE],POW[SIZE];
int n,m;
string A,B;
int l, r, u, v;
void Init()
{
    int k=max(m,n);
    for(int i=1; i<=n; i++)
    {
        Hash_A[i]=(Hash_A[i-1] * base + A[i] - 32 ) % MOD;
    }

    for(int i=1; i<=m; i++)
    {
        Hash_B[i]=(Hash_B[i-1] * base + B[i] - 32 ) % MOD;
    }

    POW[0]=1;
    for(int i=1; i<=k; i++)
    {
        POW[i]=(POW[i-1] * base) % MOD;
    }
}

ull Get_Hash_A(int st, int len)
{
    return (Hash_A[st + len - 1] - Hash_A[st - 1]*POW[len] + MOD*MOD)%MOD;
}
ull Get_Hash_B(int st, int len)
{
    return (Hash_B[st + len - 1] - Hash_B[st - 1]*POW[len] + MOD*MOD)%MOD;
}
bool check(int len)
{
    ull X =Get_Hash_A(l, len);
    ull Y =Get_Hash_B(u, len);
    if(X == Y)
        return true;
    return false;
}
void Solve()
{
    int L=1;
    int R= min(r - l + 1, v - u + 1);

    int res=0;
    while(L <= R)
    {
        //cerr << L << ' ' << R << ' ';
        int mid = (L + R)/2;
        //cerr << mid << '\n';
        if( check(mid) )
        {
            res=mid;
            L = mid + 1;
        }
        else
            R = mid - 1;
    }
    //cerr << res << '\n';
    if(res==min(r-l+1,v-u+1))
    {
        if(r-l< v-u)
            cout<<'<';
        else if(r-l>v-u)
            cout<<'>';
        else
            cout<<'=';
    }
    else if(A[l+res]<B[u+res])
        cout<<'<';
    else cout<<'>';


}
void Input()
{
    cin >> n >> m;
    cin >> A >> B;
    A=' '+A;
    B=' '+B;
    Init();

    int Q;
    cin >> Q;

    while(Q--)
    {
        cin >> l >> r >> u >> v;
        Solve();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CMPSTR.INP","r",stdin);
    freopen("CMPSTR.OUT","w",stdout);
    Input();

    return 0;
}
