#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<pair<int,int>>> g;
vector<int> res;
int max_deg;
void dfs(int u,int par,int par_color)
{
    int cur_color = 1;
    for(pair<int,int> e: g[u])
    {
        int v = e.first,id = e.second;
        if(v == par) continue;
        if(cur_color == par_color) cur_color++;
        if(cur_color > max_deg) cur_color = 1;
        if(cur_color == par_color) cur_color++;
        res[id] =cur_color;
        dfs(v,u,cur_color);
        cur_color++;
    }
}
void solve()
{
    cin>>n;
    g.resize(n+1);
    res.resize(n+1);
    max_deg = -1;
    for(int i = 1; i<n ; i++)
    {
        int u,v; cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    for(int i = 1 ; i<=n ; i++)
    {
        int size = (int) g[i].size();
        max_deg = max(max_deg,size);
    }
    cout<<max_deg<<endl;
    dfs(1,0,0);
    for(int i = 1 ; i<n ; i++)
        cout<<res[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
