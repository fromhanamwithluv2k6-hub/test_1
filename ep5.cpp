#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin>>n>>k;
    map<int,int> mp;
    while(k--)
    {
        int t; cin>>t;
        mp[t] = 1;
    }
    vector<long long> fib(n+1,0);
    fib[0] = 1;
    if(!mp[1])
        fib[1] = 1;
    for(int i = 2 ; i<=n ; i++)
    {
        if(mp[i-1] && mp[i-2])
        {
            return cout<<0<<endl , 0 ;
        }
        else if(mp[i-1])
            fib[i] = fib[i-2] ;
        else if(mp[i-2])
            fib[i] = fib[i-1];
        else
            fib[i] = fib[i-1] + fib[i-2];
    }
    cout<<fib[n]<<endl;
}