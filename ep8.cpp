#include<bits/stdc++.h>
using namespace std;
void solve()
{
    queue<int> qu;
    int q; cin>>q;
    while(q--)
    {
        int t; cin>>t;
        if(t == 1)
        {
            int x; cin>>x;
            qu.push(x);
        }
        else if(t == 2)
        {
            cout<<qu.front();
            qu.pop();
        }
        else{
            vector<int> sorted;
            while(!qu.empty())
            {
                sorted.push_back(qu.front());
                qu.pop();
            }
            sort(sorted.begin(),sorted.end());
            for(auto i : sorted)
                qu.push(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}