#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> g;
vector<pair<int,int>> edges;
void bfs(int s,int ban_u,int ban_v,vector<int>& dist)
{
    dist.resize(n+1,-1);
    dist[s] = 0;
    queue<int> qu; qu.push(s);
    while(!qu.empty())
    {
        int u = qu.front(); qu.pop();
        for(auto v : g[u])
        {
            if((u == ban_u && v == ban_v) || (u == ban_v && v == ban_u)) continue;
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
}
int findR(int s,int ban_u,int ban_v)
{
    vector<int> dist1;
    bfs(s,ban_u,ban_v,dist1);
    int A = s;
    for(int i = 1 ; i<=n ; i++)
    {
        if(dist1[i] > dist1[A]) A = i;
    }
    vector<int> dist2;
    bfs(A,ban_u,ban_v,dist2);
    int B = A;
    for(int i = 1 ; i<=n ; i++) 
    {
        if(dist2[i] > dist2[B]) B = i;
    }
    return (dist2[B] + 1) / 2 ;
}
void solve()
{
    cin>>n;
    g.resize(n+1);
    for(int i = 1 ; i<n ; i++)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u,v});
    }
    int res = INT_MAX;
    for(auto e : edges)
    {
        int u = e.first,v = e.second;
        int uR = findR(u,u,v);
        int vR = findR(v,u,v);
        res = min(res,max(uR,vR));
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}