#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const int SIZE =1E5 +5 ;
const ull MOD = 1E9+7;
const int base=31;
ull Hash_S[SIZE],Pow[SIZE];
ull Hash_P;
string S,P;
ull Get_Hash(int i,int j)
{
    return (Hash_S[j] - Hash_S[i-1]*Pow[j-i+1] + MOD*MOD)%MOD;
}
int main()
{
    freopen("HASH.INP", "r" , stdin);
    freopen("HASH.OUT", "w" , stdout);
    cin >> S >> P;

    int S_len = S.size();
    int P_len = P.size();

    S = " "+S;
    P = " "+P;

    Pow[0] = 1;
    for(int i=1;i<=S_len;i++)
        {
            Pow[i] = (Pow[i-1]*base)%MOD;
            Hash_S[i] = (Hash_S[i-1]*base + S[i]-32 )%MOD;
        }

    for(int i = 1; i <= P_len; i++)
        Hash_P = (Hash_P*base + P[i]-32 )%MOD;

    deque<int> Q;
    Q.clear();
    for(int i = 1; i<= S_len - P_len + 1; i++)
        if(Get_Hash(i, i+P_len-1) == Hash_P)
            Q.push_back(i);
    while(!Q.empty())
    {
        cout<<Q.front()<<"\n";
        Q.pop_front();
    }
    return 0;
}
