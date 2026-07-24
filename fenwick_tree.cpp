#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> BIT,a;
void init()
{
    BIT.assign(200000,0); a.assign(200000,0);
}
void update(int pos,int val)
{
    while(pos <=n)
    {
        BIT[pos] += val;
        pos += pos & (-pos);
    }
}
int query(int pos)
{
    int res = 0;
    while(pos > 0)
    {
        res += BIT[pos];
        pos -= pos &(-pos);
    }
    return res;
}
int main()
{
    init();
    cin>>n;
    for(int i = 1 ; i<=n ; i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    int t; cin>>t;
    while(t--)
    {
        int u; cin>>u;
        cout<<query(u)<<endl;
    }
}