#include<bits/stdc++.h>
#include<cmath>
using namespace std;
vector<long long> pow3(40),pow5(26);
void init()
{
    for(int i = 0 ; i<40 ; i++)
    {
        pow3[i] = (long long)pow(3,i);
    }
    for(int i = 0 ; i<26 ; i++)
    {
        pow5[i] = (long long)pow(5,i);
    }
}
void solve()
{
    long long n; cin>>n;
    for(int i = 0 ; i<40 ; i++)
    {
        for(int j = 0 ; j <26 ; j++)
        {
            if(pow3[i] + pow5[j] == n)
            {
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}