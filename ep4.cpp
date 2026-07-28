#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
bool isprime(int n)
{
    if(n < 2) return 0;
    for(int i = 2 ; i<=sqrt(n) ; i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}
int lengdre(int n,int p)
{
    int res = 0;
    for(int i = p ; i<=n ; i *= p)
        res += n/i;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    long long res = 1;
    for(int i = 2 ; i<=n ; i++)
    {
        if(isprime(i))
        {
            res *= (lengdre(n,i) + 1);
            res %= MOD;
        }
    }
    cout<<res<<endl;
}